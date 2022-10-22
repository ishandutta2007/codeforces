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
    VI a(m);
    rep(i, m) cin >> a[i], a[i]--;
    sort(all(a));
    a.emplace_back(a[0] + n);
    VI d(m);
    rep(i, m) d[i] = a[i+1] - a[i] - 1;
    sort(rall(d));
    int ans = 0;
    int cnt = 0;
    rep(i, m) {
      int rest = d[i] - 2 * cnt;
      if (rest <= 0) continue;
      if (rest == 1) {
        ans++;
        cnt++;
      } else {
        ans += rest - 1;
        cnt += 2;
      }
    }
    cout << n - ans << '\n';
  }
}