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
    VI a(n), b1, b2;
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n) {
      int x;
      cin >> x;
      ans += x;
      (a[i] ? b1 : b2).emplace_back(x);
    }
    int sz1 = b1.size(), sz2 = b2.size();
    if (sz1 > sz2) {
      swap(sz1, sz2);
      swap(b1, b2);
    }
    sort(rall(b1));
    sort(rall(b2));
    if (sz1 < sz2) {
      rep(i, sz1) ans += b1[i] + b2[i];
    } else {
      rep(i, sz1 - 1) ans += b1[i] + b2[i];
      ans += max(b1[sz1-1], b2[sz1-1]);
    }
    cout << ans << '\n';
  }
}