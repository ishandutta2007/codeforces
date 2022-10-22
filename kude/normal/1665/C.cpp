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
    VI deg(n + 1);
    for(int i = 1; i < n; i++) {
      int p;
      cin >> p;
      p--;
      deg[p]++;
    }
    deg[n] = 1;
    sort(rall(deg));
    while(deg.back() == 0) deg.pop_back();
    n = deg.size();
    int ans = n;
    rep(i, n) deg[i] -= n - i;
    sort(rall(deg));
    while(deg.size() && deg.back() <= 0) deg.pop_back();
    if (deg.size()) {
      int r = deg[0], l = 0;
      while(r - l > 1) {
        int c = (r + l) / 2;
        ll cnt = 0;
        for(int x: deg) cnt += max(0, x - c);
        if (cnt <= c) r = c;
        else l = c;
      }
      ans += r;
    }
    cout << ans << '\n';
  }
}