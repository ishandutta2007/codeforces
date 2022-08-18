#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n;
    cin >> n;
    vvd p(n, vd(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      int x;
      scanf("%d", &x);
      p[i][j] = x / 100.;
    }
    vd x(n, 100*(n - 1));
    x[n-1] = 0;
    for (int i = 0; i < n - 1; ++i) if (p[i][n-1] > 0) {
      x[i] = min(x[i], 1. / p[i][n-1]);
    }
    vi ord(n);
    for (int t = 0; t < 100; ++t) {
      vector<pair<double, int> > ts(n);
      for (int i = 0; i < n; ++i) ts[i] = make_pair(x[i], i);
      sort(ts.begin(), ts.end());
      for (int i = 0; i < ts.size(); ++i) ord[i] = ts[i].second;
      for (int i1 = 1; i1 < ts.size(); ++i1) {
        int i = ord[i1];
        double mul = 1, sum = 1;
        for (int j1 = 0; j1 < i1; ++j1) {
          int j = ord[j1];
          sum += mul * p[i][j] * x[j];
          mul *= (1 - p[i][j]);
          if (mul < 1e-9) break;
        }
//        cerr << i << ' ' << mul << ' ' << sum << endl;
        if (mul < 1 - 1e-8) {
          x[i] = min(100.*(n - 1), sum / (1 - mul));
        }
      }
    }
    printf("%.10lf\n", x[0]);
//    printf("%.10lf\n", x[1]);
//    printf("%.10lf\n", x[2]);
    return 0;
}