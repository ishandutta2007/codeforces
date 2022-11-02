#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>


using namespace std;

typedef long long ll;
typedef long double ld;

const long long mod = 1000000009;
typedef complex<double> cd;

const long long INF = 1000000010;
const ll LONGINF = 4e18;
const double PI = 3.141592653589793;

int getNext(set<int>& s, int x) {
  auto it = s.lower_bound(x);
  if (it == s.end())
    return -1;
  return *it;
}

int getPrev(set<int>& s, int x) {
  auto it = s.upper_bound(x);
  if (it == s.begin())
    return -1;
  return *(prev(it));
}

void solve() {
  int n, m;
  int cs, ce;
  int v;
  cin >> n >> m >> cs >> ce >> v;
  set<int> stairs, lifts;
  for (int i = 0; i < cs; ++i) {
    int a;
    cin >> a;
    stairs.insert(a);
  }

  for (int i = 0; i < ce; ++i) {
    int a;
    cin >> a;
    lifts.insert(a);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = INF;
    int nl, pl, ns, ps;
    int h = abs(c - a);

    nl = getNext(lifts, b);
    pl = getPrev(lifts, b);
    ns = getNext(stairs, b);
    ps = getPrev(stairs, b);

    if (nl != -1) {
      ans = min(ans, abs(nl - b) + (h + v - 1) / v + abs(nl - d));
    }

    if (pl != -1) {
      ans = min(ans, abs(pl - b) + (h + v - 1) / v + abs(pl - d));
    }

    if (ns != -1) {
      ans = min(ans, abs(ns - b) + h + abs(ns - d));
    }

    if (ps != -1) {
      ans = min(ans, abs(ps - b) + h + abs(ps - d));
    }

    if (h == 0)
      ans = abs(b - d);

    cout << ans << endl;

  }
}

void init() {

}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  init();
//  ll t;
//  cin >> t;
//  while (t--)
  solve();
  return 0;
}