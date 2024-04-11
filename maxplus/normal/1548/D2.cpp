#include <iostream>
#include <numeric>
#include <vector>
#include <bitset>

using namespace std;

constexpr int PC = 5400;
bitset<PC / 2> gcd4pc[PC / 2];

int gcd4(int a, int b) {
  if (!b) {
    return a % 4;
  } else if (a < PC) {
    return ((const decltype(*gcd4pc))gcd4pc[b / 2])[a / 2] * 2 + 1;
  }
  a %= b;
  return gcd4(b, a >> __builtin_ctz(a));
}

struct Point {
  int x, y;

  Point operator-(const Point& b) {
    return {x - b.x, y - b.y};
  }

  Point mod4() {
    return {::abs(x) % 4, ::abs(y) % 4};
  }

  int gcd4(bool lazy = 0) {
    int a = abs(x);
    int b = abs(y);
    if (a % 2 || b % 2) {
      if (lazy) {
        return 1;
      }
      if (a % 2 == 0) {
        swap(a, b);
      }
      b >>= __builtin_ctz(b);
      if (a < b) {
        swap(a, b);
      }
      return ::gcd4(a, b);
    } else {
      return (a % 4 || b % 4) * 2;
    }
  }

  bool operator==(const Point& b) const {
    return x == b.x && y == b.y;
  }

  bool operator<(const Point& b) const {
    return x != b.x? x < b.x: y < b.y;
  }

  int operator^(const Point& b) const {
    return x * b.y - y * b.x;
  }

  friend istream& operator>>(istream& in, Point& p) {
    return in >> p.x >> p.y;
  }
};

constexpr int N = 6000;

Point p[N];
int cnt[N][4][4][4];
constexpr int range4[]{0, 1, 2, 3};

using Group = pair<Point, int>;

int getcnt(int i, const Group& gr, int sub = 0) {
  return cnt[i][gr.first.x][gr.first.y][gr.second] - sub;
}

int main() {
  for (int i = 1; i < PC; ++++i)
  for (int j = i; j < PC; ++++j) {
    if (int ni = j % i; ni? gcd4pc[ni >> __builtin_ctz(ni) + 1][i >> 1]: i % 4 == 3) {
      gcd4pc[i / 2].set(j / 2);
    }
  }
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  int64_t ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<pair<Point, int>> nei;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int g = (p[i] - p[j]).gcd4();
      for ([[maybe_unused]] auto c: {0, 1}) {
        auto [x, y] = p[j].mod4();
        ++cnt[i][x][y][g];
        swap(i, j);
      }
    }
    nei.clear();
    for (auto x: range4)
    for (auto y: range4)
    for (auto g: range4) if (cnt[i][x][y][g]) {
      nei.emplace_back(Point{x, y}, g);
    }
    auto p = ::p[i].mod4();
    for (auto& gr1: nei)
    for (auto& gr2: nei) if (&gr1 <= &gr2) {
      auto& [p1, g1] = gr1;
      auto& [p2, g2] = gr2;
      int g = (p1 - p2).gcd4(1);
      if (g % 2 || (g + g1 + g2 + 4 - (p1 - p ^ p2 - p) % 4) % 4) {
        continue;
      }
      ans += getcnt(i, gr1) * getcnt(i, gr2, gr1 == gr2) / (gr1 == gr2? 2: 1) * (g1 % 2? 3: 1);
    }
  }
  cout << ans / 3 << '\n';
  return 0;
}