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
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--;
    int l = -1, r = n;
    vector<char> rmv(n);
    while(r - l > 1) {
      int c = (l + r) / 2;
      rmv.assign(n, false);
      rep(i, c) rmv[a[i]] = true;
      int last = -1;
      bool ok = true;
      for(int x: a) {
        if (rmv[x]) x = -1;
        if (x < last) {
          ok = false;
          break;
        }
        last = x;
      }
      (ok ? r : l) = c;
    }
    rmv.assign(n, false);
    rep(i, r) rmv[a[i]] = true;
    int ans = accumulate(all(rmv), 0);
    cout << ans << '\n';
  }
}