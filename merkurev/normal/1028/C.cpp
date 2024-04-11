#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

typedef long long int int64;

struct Rect {
  int x1, y1, x2, y2;

  Rect() : x1(), y1(), x2(), y2() {}

  Rect(int _x1, int _y1, int _x2, int _y2)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

  bool good() { return x2 >= x1 && y2 >= y1; }

  Rect operator+(const Rect &A) const {
    return Rect(max(x1, A.x1), max(y1, A.y1), min(x2, A.x2), min(y2, A.y2));
  }

  void scan() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
};

const int INF = (int)1e9 + 100;
const int N = (int)2e5 + 100;
Rect rect[N];
Rect pr[N], suf[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) rect[i].scan();
  Rect full = Rect(-INF, -INF, INF, INF);

  pr[0] = full;
  for (int i = 0; i < n; i++) pr[i + 1] = pr[i] + rect[i];
  suf[n] = full;
  for (int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + rect[i];

  for (int i = 0; i < n; i++) {
    Rect cur = pr[i] + suf[i + 1];
    if (cur.good()) {
      printf("%d %d\n", cur.x1, cur.y1);
      return 0;
    }
  }

  return 0;
}