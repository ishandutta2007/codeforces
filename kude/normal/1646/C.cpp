#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  ll f[12];
  f[0] = 6;
  for(int i = 1, x = 4; i <= 11; i++, x++) f[i] = x * f[i - 1];
  VL v(1 << 12);
  rep(s, 1 << 12) {
    ll t = 0;
    rep(k, 12) if (s >> k & 1) t += f[k];
    v[s] = t;
  }
  while(tt--) {
    ll n;
    cin >> n;
    constexpr int INF = 1001001001;
    int ans = INF;
    rep(s, 1 << 12) {
      ll x = v[s];
      if (x <= n) {
        chmin(ans, __builtin_popcount(s) + __builtin_popcountll(n - x));
      }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }
}