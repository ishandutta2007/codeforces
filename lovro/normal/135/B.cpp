#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

template<typename T> inline T sqr( const T &a ) { return a*a; }
typedef long long int64;

struct Point {
  int64 x, y;

  friend Point operator-(const Point &p1, const Point &p2) {
    return (Point){p1.x-p2.x, p1.y-p2.y};
  }
};

int64 sqrdist(const Point &p1, const Point &p2) {
  return sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
}

int64 dotproduct(const Point &v1, const Point &v2) {
  return v1.x*v2.x + v1.y*v2.y;
}

bool isrect(const Point &A, const Point &B, const Point &C, const Point &D, bool check_square) {
  Point p[4] = {A, B, C, D};
  int64 d[4];
  for (int i=0; i<4; ++i) {
    int j = (i+1)%4, k = (i+2)%4;
    if (dotproduct(p[i]-p[j], p[k]-p[j]) != 0) {
      return false;
    }
    d[i] = sqrdist(p[i], p[j]);
    if (d[i] == 0) {
      return false;
    }
  }
  if (d[0] != d[2] || d[1] != d[3]) {
    return false;
  }
  if (check_square && d[0] != d[1]) {
    return false;
  }
  return true;
}

Point pts[8];
bool check(const vector<int> &perm) {
  return
    isrect(pts[perm[0]], pts[perm[1]], pts[perm[2]], pts[perm[3]], true) &&
    isrect(pts[perm[4]], pts[perm[5]], pts[perm[6]], pts[perm[7]], false);
}

int main() {
  cin.sync_with_stdio(0);

  for (int i=0; i<8; ++i) {
    cin >> pts[i].x >> pts[i].y;
  }

  vector<int> perm(8);
  for (int i=0; i<8; ++i) perm[i] = i;

  do {
    if (check(perm)) {
      cout << "YES\n";
      for (int i=0; i<8; ++i) {
        if (i%4 != 0) cout << ' ';
        cout << perm[i] + 1;
        if (i%4 == 3) cout << '\n';
      }
      return 0;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  cout << "NO\n";

  return 0;
}