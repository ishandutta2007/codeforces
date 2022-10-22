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
    int n, m, k;
    cin >> n >> m >> k;
    VI a(k);
    rep(i, k) cin >> a[i];
    bool ans = false;
    rep(_, 2) {
      ll tot = 0;
      bool all2 = true;
      for(int x: a) {
        int cnt = x / n;
        if (cnt >= 2) {
          tot += cnt;
          if (cnt > 2) all2 = false;
        }
      }
      if (tot >= m && (!all2 || m % 2 == 0)) {
        ans = true;
        break;
      }
      swap(n, m);
    }
    cout << (ans ? "Yes\n" : "No\n");
  }
}