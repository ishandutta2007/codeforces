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
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    VVI c(n, VI(m));
    rep(i, n) rep(j, m) cin >> c[i][j];
    VL s(n);
    rep(i, n) {
      ll sm = 0;
      rep(j, m) sm += (ll)j * c[i][j];
      s[i] = sm;
    }
    ll tgt = *min_element(all(s));
    rep(i, n) if (s[i] != tgt) {
      cout << i + 1 << ' ' << s[i] - tgt << '\n';
      break;
    }
  }
}