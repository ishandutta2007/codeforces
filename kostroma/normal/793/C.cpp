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
//int timer = 1;

int testNumber = 1;

bool todo = true;

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
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
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

//#define int li
//const int mod = 1000000007;

double eps = 1e-11;
double INF = 1e9;

pair<double, double> get_segment(double r, double v, double left_border, double right_border) {
  if (v < 0) {
    r = -r;
    v = -v;
    left_border = -left_border;
    right_border = -right_border;
    swap(left_border, right_border);
  }

  if (fabs(v) < eps) {
    if (r < left_border + eps || r + eps > right_border) {
      return {0, -INF};
    } else {
      return {0, INF};
    }
  }
  if (r + eps > right_border) {
    return {0, -INF};
  }

  double L = 0;
  if (r < left_border) {
    L = (left_border - r) / v;
  }
  double R = (right_border - r) / v;
  return {L, R};
}

void solve(bool read) {
  int n;
  cin >> n;
  vector<double> x(2), y(2);
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  double minR = INF, maxL = 0;
  for (int i = 0; i < n; ++i) {
    double r[2], v[2];
    cin >> r[0] >> r[1] >> v[0] >> v[1];
    auto x_seg = get_segment(r[0], v[0], x[0], x[1]);
    minR = min(minR, x_seg.second);
    maxL = max(maxL, x_seg.first);
    auto y_seg = get_segment(r[1], v[1], y[0], y[1]);
    minR = min(minR, y_seg.second);
    maxL = max(maxL, y_seg.first);
  }

  if (minR < maxL + eps) {
    cout << "-1\n";
    return;
  }

  cout << maxL << endl;

}