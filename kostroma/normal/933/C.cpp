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
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
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
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  while (t--) {
    solve(true);
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

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

//#define int li
//const int mod = 1000000007;

const double eps = 1e-9;

struct Point {
  double x, y;
  Point(): x(0), y(0) {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator - (const Point& ot) const {
    return Point(x - ot.x, y - ot.y);
  }
  Point operator + (const Point& ot) const {
    return Point(x + ot.x, y + ot.y);
  }
  Point rotate(double alpha) const {
    return Point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
  }
  double dist() {
    return sqrt(x * x + y * y);
  }
  bool operator < (const Point& ot) const {
    if (fabs(x - ot.x) > eps) {
      return x < ot.x;
    }
    return y + eps < ot.y;
  }
  Point operator * (double c) {
    return Point(x * c, y * c);
  }
};

struct Circle {
  Point center;
  int r;
  void scan() {
    cin >> center.x >> center.y >> r;
  }
};

vector<int> dsu;

int find_set(int v) {
  if (dsu[v] == v) {
    return v;
  }
  return dsu[v] = find_set(dsu[v]);
}

void merge(int q, int w) {
  q = find_set(q);
  w = find_set(w);
  dsu[w] = q;
}

int get_diff(vector<Point>& points) {
  sort(all(points));
  int res = 0;
  for (int i = 0; i < points.size(); ++i) {
    if (i == 0 || fabs((points[i] - points[i - 1]).dist()) > eps) {
      ++res;
    }
  }
  return res;
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<Circle> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].scan();
    for (int j = 0; j < i; ++j) {
      if (fabs((a[i].center - a[j].center).dist()) < eps && a[i].r == a[j].r) {
        a.pop_back();
        --i;
        --n;
        break;
      }
    }
  }
  dsu.resize(n);
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
  }
  vector<vector<Point>> inters(n);
  vector<Point> all_points;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }
      double d = (a[i].center - a[j].center).dist();
      if (d > a[i].r + a[j].r + eps) continue;
      if (d + eps < abs(a[i].r - a[j].r)) continue;
      if (fabs(d) < eps) continue;

      double co = (d * d + a[i].r * a[i].r - a[j].r * a[j].r) / 2 / a[i].r / d;
      co = min(co, 1.);
      co = max(co, -1.);
      double alpha = acos(co);

      Point vec = a[j].center - a[i].center;
      vec = vec * (a[i].r / vec.dist());
      for (int dom = -1; dom <= 1; dom += 2) {
        auto now = vec.rotate(dom * alpha) + a[i].center;
        inters[i].push_back(now);
        all_points.push_back(now);
        merge(i, j);
      }
    }
  }

  int comps = 0;
  for (int i = 0; i < n; ++i) {
    if (find_set(i) == i) {
      ++comps;
    }
  }
  int vs = get_diff(all_points) + n;
  int edges = 0;
  for (int i = 0; i < n; ++i) {
    edges += get_diff(inters[i]) + 1;
  }

  //cout << vs << " " << edges << " " << comps << endl;

  int res = comps + 1 - vs + edges;

  cout << res << endl;

}