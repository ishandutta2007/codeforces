/**
 *    author:  tourist
 *    created: 24.04.2022 18:00:11       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
struct TPoint {
  T x;
  T y;
  int id;

  TPoint() : x(0), y(0), id(-1) {}
  TPoint(const T& x_, const T& y_) : x(x_), y(y_), id(-1) {}
  TPoint(const T& x_, const T& y_, int id_) : x(x_), y(y_), id(id_) {}

  static constexpr T eps = static_cast<T>(1e-9);

  inline TPoint operator+(const TPoint& rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
  inline TPoint operator-(const TPoint& rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
  inline TPoint operator*(const T& rhs) const { return TPoint(x * rhs, y * rhs); }
  inline TPoint operator/(const T& rhs) const { return TPoint(x / rhs, y / rhs); }

  friend T smul(const TPoint& a, const TPoint& b) {
    return a.x * b.x + a.y * b.y;
  }

  friend T vmul(const TPoint& a, const TPoint& b) {
    return a.x * b.y - a.y * b.x;
  }

  inline T abs2() const {
    return x * x + y * y;
  }

  inline bool operator<(const TPoint& rhs) const {
    return (y < rhs.y || (y == rhs.y && x < rhs.x));
  }

  inline bool is_upper() const {
    return (y > eps || (abs(y) <= eps && x > eps));
  }

  inline int cmp_polar(const TPoint& rhs) const {
    assert(abs(x) > eps || abs(y) > eps);
    assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
    bool a = is_upper();
    bool b = rhs.is_upper();
    if (a != b) {
      return (a ? -1 : 1);
    }
    long long v = x * rhs.y - y * rhs.x;
    return (v > eps ? -1 : (v < -eps ? 1 : 0));
  }
};

typedef long double ld;

//using Point = TPoint<long long>;
using Point = TPoint<ld>;

template <typename T>
string to_string(const TPoint<T>& p) {
  return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

const ld pi = acos((ld) -1.0);

ld Solve(Point pa, Point pb, Point pc) {
  // a^2 = b^2 + c^2 - 2bc*cos(alpha)
  ld a = sqrt((pb - pc).abs2());
  ld b = sqrt((pa - pc).abs2());
  ld c = sqrt((pb - pa).abs2());
  if (min(a, min(b, c)) < 1e-9) {
    return (a + b + c) / 2;
  }
  ld da = acos(max((ld) -1.0, min((ld) 1.0, (b * b + c * c - a * a) / (2 * b * c))));
  ld db = acos(max((ld) -1.0, min((ld) 1.0, (a * a + c * c - b * b) / (2 * a * c))));
  ld dc = acos(max((ld) -1.0, min((ld) 1.0, (a * a + b * b - c * c) / (2 * a * b))));
//  debug(a, b, c, da, db, dc);
  if (max(da, max(db, dc)) >= 2 * pi / 3) {
    return a + b + c - max(a, max(b, c));
  }
  ld wa = a / sin(da + pi / 3);
  ld wb = b / sin(db + pi / 3);
  ld wc = c / sin(dc + pi / 3);
  Point p = (pa * wa + pb * wb + pc * wc) * (1.0 / (wa + wb + wc));
  ld ra = sqrt((p - pa).abs2());
  ld rb = sqrt((p - pb).abs2());
  ld rc = sqrt((p - pc).abs2());
  return ra + rb + rc;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Point a, b, c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  ld ans = 1e30;
  auto GetXY = [&](ld x, ld y) {
    Point p(x, y);
    ld ret = max(Solve(p, a, b), max(Solve(p, a, c), Solve(p, b, c)));
    ans = min(ans, ret);
    return ret;
  };
  auto GetX = [&](ld x) {
    ld low = -1e5, high = 1e5;
    ld best = 1e30;
    for (int it = 0; it < 200; it++) {
      ld q1 = (2 * low + high) / 3;
      ld q2 = (low + 2 * high) / 3;
      ld v1 = GetXY(x, q1);
      ld v2 = GetXY(x, q2);
      best = min(best, min(v1, v2));
      if (v1 < v2) {
        high = q2;
      } else {
        low = q1;
      }
    }
    return best;
  };
  ld low = -1e5, high = 1e5;
  for (int it = 0; it < 200; it++) {
    ld q1 = (2 * low + high) / 3;
    ld q2 = (low + 2 * high) / 3;
    ld v1 = GetX(q1);
    ld v2 = GetX(q2);
    if (v1 < v2) {
      high = q2;
    } else {
      low = q1;
    }
  }
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}