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
    int n;
    cin >> n;
    VI c(n);
    rep(i, n) cin >> c[i];
    VI ans(n);
    int i = 0;
    while(i < n && c[i] == 0) i++;
    if (i == n) {
      rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
      continue;
    }
    int nxt = i;
    int x = c[i] - i;
    rep(_, x) ans[nxt++] = 1;
    if (nxt < n) ans[nxt++] = 0;
    for(i++; i < n; i++) {
      int x = c[i] - i * ans[i] - (nxt - i);
      rep(_, x) ans[nxt++] = 1;
      if (nxt < n) ans[nxt++] = 0;
    }
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}