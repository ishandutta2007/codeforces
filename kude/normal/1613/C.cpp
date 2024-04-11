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
  while(tt--) {
    int n;
    cin >> n;
    ll h;
    cin >> h;
    VL a(n);
    rep(i, n) cin >> a[i];
    ll r = h, l = 0;
    while(r - l > 1) {
      ll c = (l + r) >> 1;
      ll nxt_start = 0;
      ll tot = 0;
      rep(i, n) {
        chmax(nxt_start, a[i]);
        ll nxt_end = a[i] + c;
        tot += nxt_end - nxt_start;
        nxt_start = nxt_end;
      }
      if (tot >= h) r = c;
      else l = c;
    }
    cout << r << '\n';
  }
}