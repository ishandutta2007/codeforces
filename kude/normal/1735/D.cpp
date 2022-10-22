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

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  using UI = unsigned int;
  vector<UI> c(n);
  UI pow3[20];
  pow3[0] = 1U;
  rep(i, 19) pow3[i+1] = pow3[i] * 3U;
  map<UI, int> mp;
  rep(i, n) {
    UI x = 0;
    rep(j, k) {
      unsigned int t;
      cin >> t;
      x += t * pow3[j];
    }
    c[i] = x;
    mp[x] = i;
  }
  VI cnt(n);
  rep(i, n) rep(j, i) {
    UI xi = c[i], xj = c[j];
    UI xk = 0;
    rep(t, k) {
      UI bi = xi % 3;
      UI bj = xj % 3;
      xi /= 3, xj /= 3;
      UI bk = bi == bj ? bi : 3U - bi - bj;
      xk += bk * pow3[t];
    }
    auto it = mp.find(xk);
    if (it == mp.end()) continue;
    int k = it->second;
    if (k < j) {
      cnt[i]++;
      cnt[j]++;
      cnt[k]++;
    }
  }
  ll ans = 0;
  rep(i, n) ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
  cout << ans << '\n';
}