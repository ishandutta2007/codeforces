#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
  //freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
    //cout << "Case #" << testNum++ << ": ";
    //cerr << testNum << endl;
    solve(true);
    //cerr << testNum - 1 << endl;
  }
  cout.flush();
#ifdef AIM1
  while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

void precalc() {

}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

#define int li
//const int mod = 1000000007;

struct Point {
  int x, y;
  int id;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}
  int operator * (const Point& ot) const {
    return x * ot.y - y * ot.x;
  }
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
};

bool inside(Point a, Point b, Point c, Point d) {
  return abs((b - a) * (c - a)) == abs((a - d) * (b - d)) + abs((c - d) * (b - d)) + abs((a - d) * (c - d));
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
    points[i].id = i;
  }

  for (int i = 2; i < n; ++i) {
    if ((points[i] - points[0]) * (points[1] - points[0]) != 0) {
      swap(points[i], points[2]);
      break;
    }
  }

  vector<Point> tr(points.begin(), points.begin() + 3);
  for (int uk = 3; uk < n; ++uk) {
    if (inside(tr[0], tr[1], tr[2], points[uk])) {
      for (int i = 0; i < 3; ++i) {
        int val = (tr[i] - points[uk]) * (tr[(i + 1) % 3] - points[uk]);
        if (val != 0) {
          tr[(i + 2) % 3] = points[uk];
          break;
        }
      }
    }
  }

  for (int i = 0; i < 3; ++i) {
    cout << tr[i].id + 1 << " ";
  }
  cout << endl;

}