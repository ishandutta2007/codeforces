#include "bits/stdc++.h"

using namespace std;
using ll = long long;

template <class T>
using vc = vector<T>;

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))

void solve() {
  ll N;
  cin >> N;

  map<tuple<ll, ll, ll>, ll> MEMO;
  auto ask = [&](ll i, ll j, ll k) -> ll {
    tuple<ll, ll, ll> key = mt(i, j, k);
    if (MEMO.count(key)) return MEMO[key];
    auto &res = MEMO[key];
    assert(i != j);
    assert(i != k);
    assert(j != k);
    ++i, ++j, ++k;
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();
    ll x;
    cin >> x;
    MEMO[key] = x;
    return x;
  };

  auto OUT = [&](ll i, ll j) -> void {
    cout << "! " << ++i << " " << ++j << endl;
    cout.flush();
  };

  vc<ll> vals(N);
  FOR3(k, 2, N) vals[k] = ask(0, 1, k);
  auto p = max_element(all(vals)) - vals.begin();
  // 0, p  max OR min
  vc<ll> I, X;
  FOR(i, N) if (i != 0 && i != p) {
    I.eb(i);
    X.eb(ask(0, p, i));
  }
  if (MIN(X) == MAX(X)) return OUT(0, p);
  auto q = I[max_element(all(X)) - X.begin()];
  // q  max OR min
  // (0, q) OR (p, q)
  //  2 
  ll k = -1;
  FOR(i, N) if (i != 0 && i != p && i != q) k = i;
  if (ask(0, q, k) < ask(p, q, k))
    OUT(p, q);
  else
    OUT(0, q);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T;
  cin >> T;
  FOR(_, T) solve();

  return 0;
}