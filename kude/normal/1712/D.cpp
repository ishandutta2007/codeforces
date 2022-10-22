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
    int n, k;
    cin >> n >> k;
    VI a(n);
    rep(i, n) cin >> a[i];
    VI d;
    int l = 0, r = 1000000001;
    while(r - l > 1) {
      int c = (l + r) / 2;
      int cnt = 0;
      d = a;
      for(int& x: d) {
        if (2 * x < c) {
          x = 1000000000;
          cnt++;
        }
      }
      int mncost = 2;
      rep(i, n - 1) {
        int cost = (d[i] < c) + (d[i+1] < c);
        chmin(mncost, cost);
      }
      cnt += mncost;
      (cnt <= k ? l : r) = c;
    }
    cout << l << '\n';
  }
}