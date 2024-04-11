#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

ll ub(ll x, ll d) {
  return x / d + (x % d > 0 ? 1 : 0);
}

void solve(istream& cin = cin, ostream& cout=cout) {
  int n;
  ll x1, x2;
  cin >> n >> x1 >> x2;
  vector<pair<ll, int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  vector<ll> can1(n, 0), can2(n, 0);
  vector<bool> rcan1(n + 1, false), rcan2(n + 1, false);
  for (int i = 0; i < n; ++i) {
    if (ub(x1, v[i].first) <= n - i) {
      can1[i] = ub(x1, v[i].first);
    }
    if (ub(x2, v[i].first) <= n - i) {
      can2[i] = ub(x2, v[i].first);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    rcan1[i] = rcan1[i + 1] || (can1[i] > 0);
    rcan2[i] = rcan2[i + 1] || (can2[i] > 0);
  }
  int st1 = n, st2 = n;
  for (int i = n - 1; i >= 0; --i) {
    ll k = ub(x1, v[i].first);
    if (k + i < n && (rcan2[k + i])) {
      st1 = i;
      for (int j = i + k; j < n; ++j) {
        if (can2[j] > 0) {
          st2 = j;
          break;
        }
      }
      break;
    }
    k = ub(x2, v[i].first);
    if (k + i < n && (rcan1[k + i])) {
      st2 = i;
      for (int j = i + k; j < n; ++j) {
        if (can1[j] > 0) {
          st1 = j;
          break;
        }
      }
      break;
    }
  }
  if (st1 == n || st2 == n) {
    cout << "No\n";
    return;
  }
  cout << "Yes\n";
  cout << can1[st1] << ' ' << can2[st2] << endl;
  for (int i = st1; i < st1 + can1[st1]; ++i) {
    cout << v[i].second << ' ';
  }
  cout << endl;
  for (int i = st2; i < st2 + can2[st2]; ++i) {
    cout << v[i].second << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();
  return 0;
}