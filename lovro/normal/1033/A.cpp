#define NDEBUG
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <type_traits>

// <lib>

template <typename T> struct GridPoint {
  GridPoint() { }
  GridPoint(T x, T y) : x(x), y(y) { }
  GridPoint(const GridPoint& p) = default;
  template <typename U> GridPoint(const GridPoint<U>& p) : x(p.x), y(p.y) {}

  template <typename U> GridPoint& operator+=(const GridPoint<U>& p) {
    x += p.x; y += p.y;
    return *this;
  }
  template <typename U> GridPoint& operator-=(const GridPoint<U>& p) {
    x -= p.x; y -= p.y;
    return *this;
  }
  template <typename U>
  GridPoint<typename std::common_type<T, U>::type> operator+(const GridPoint<U>& p) const {
    return GridPoint<typename std::common_type<T, U>::type>(x + p.x, y + p.y);
  }
  template <typename U>
  GridPoint<typename std::common_type<T, U>::type> operator-(const GridPoint<U>& p) const {
    return GridPoint<typename std::common_type<T, U>::type>(x - p.x, y - p.y);
  }
  GridPoint operator-() const { return GridPoint(-x, -y); }

  template <typename U> bool operator<(const GridPoint<U>& p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  template <typename U> bool operator>(const GridPoint<U>& p) const { return p < *this; }
  template <typename U> bool operator==(const GridPoint<U>& p) const {
    return x == p.x && y == p.y;
  }
  template <typename U> bool operator!=(const GridPoint<U>& p) const {
    return !(*this == p);
  }

  std::string str() const {
    return "(x=" + std::to_string(x) + ", y=" + std::to_string(y) + ")";
  }

  T x, y;
};

const std::array<GridPoint<int8_t>, 8>& delta8() {
  static std::array<GridPoint<int8_t>, 8> arr{
    {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}}};
  return arr;
}
// </lib>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  using Point = GridPoint<int>;
  int n;
  cin >> n;
  Point Q, K, target;
  cin >> Q.x >> Q.y;
  cin >> K.x >> K.y;
  cin >> target.x >> target.y;
  static char been[1005][1005];
  queue<Point> q;
  q.push(K);
  been[K.x][K.y] = true;
  while (!q.empty()) {
    Point pos = q.front(); q.pop();
    if (pos == target) {
      cout << "YES\n";
      return 0;
    }
    for (Point d : delta8()) {
      Point next = pos + d;
      if (next.x >= 1 && next.x <= n &&
          next.y >= 1 && next.y <= n &&
          !been[next.x][next.y] &&
          next.x != Q.x &&
          next.y != Q.y &&
          next.x + next.y != Q.x + Q.y &&
          next.x - next.y != Q.x - Q.y) {
        q.push(next);
        been[next.x][next.y] = true;
      }
    }
  }
  cout << "NO\n";
}