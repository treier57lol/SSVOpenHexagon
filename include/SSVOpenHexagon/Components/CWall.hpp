// Copyright (c) 2013-2020 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#pragma once

#include "SSVOpenHexagon/Components/SpeedData.hpp"
#include "SSVOpenHexagon/Utils/PointInPolygon.hpp"

#include <SFML/System/Vector2.hpp>

#include <array>

namespace hg
{

class HexagonGame;

class CWall
{
private:
    std::array<sf::Vector2f, 4> vertexPositions;

    SpeedData speed;
    SpeedData curve;

    float hueMod;
    bool killed;

public:
    CWall(HexagonGame& mHexagonGame, const sf::Vector2f& mCenterPos, int mSide,
        float mThickness, float mDistance, const SpeedData& mSpeed,
        const SpeedData& mCurve);

    void update(HexagonGame& mHexagonGame, ssvu::FT mFT);

    void moveTowardsCenter(HexagonGame& mHexagonGame,
        const sf::Vector2f& mCenterPos, ssvu::FT mFT);

    void moveCurve(HexagonGame& mHexagonGame, const sf::Vector2f& mCenterPos,
        ssvu::FT mFT);

    void draw(HexagonGame& mHexagonGame);

    void setHueMod(float mHueMod) noexcept;

    [[gnu::always_inline, nodiscard]] const SpeedData& getSpeed() const noexcept
    {
        return speed;
    }

    [[gnu::always_inline, nodiscard]] const SpeedData& getCurve() const noexcept
    {
        return curve;
    }

    [[gnu::always_inline, nodiscard]] bool isOverlapping(
        const sf::Vector2f& mPoint) const noexcept
    {
        return Utils::pointInPolygon(vertexPositions, mPoint.x, mPoint.y);
    }

    [[gnu::always_inline, nodiscard]] bool isDead() const noexcept
    {
        return killed;
    }
};

} // namespace hg
