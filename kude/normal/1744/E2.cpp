#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

template<class T>
vector<pair<T, int>> factorize(T x) {
  vector<pair<T, int>> res;
  for(T p = 2; p * p <= x; p++) {
    int cnt = 0;
    while(x % p == 0) x /= p, cnt++;
    if (cnt) res.emplace_back(p, cnt);
  }
  if (x > 1) res.emplace_back(x, 1);
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    auto facts_a = factorize(a);
    auto facts_b = factorize(b);
    vector<P> facts_ab;
    rep(_, 2) {
      for(auto [p, _]: facts_a) {
        facts_ab.emplace_back(p, 0);
      }
      swap(facts_a, facts_b);
    }
    sort(all(facts_ab));
    facts_ab.erase(unique(all(facts_ab)), facts_ab.end());
    rep(_, 2) {
      int idx = 0;
      for(auto [p, c]: facts_a) {
        while(facts_ab[idx].first != p) idx++;
        facts_ab[idx].second += c;
      }
      swap(facts_a, facts_b);
    }
    vector<ll> ds{1};
    for(auto [p, c]: facts_ab) {
      int sz = ds.size();
      rep(i, sz) {
        ll d = ds[i];
        rep(_, c) {
          d *= p;
          ds.emplace_back(d);
        }
      }
    }
    sort(all(ds));
    int sz = ds.size();
    bool done = false;
    rep(i, sz) {
      int x = c / ds[i] * ds[i];
      if (x <= a) continue;
      int y = d / ds[sz-1-i]* ds[sz-1-i];
      if (y <= b) continue;
      cout << x << ' ' << y << '\n';
      done = true;
      break;
    }
    if (!done) cout << -1 << ' ' << -1 << '\n';
  }
}