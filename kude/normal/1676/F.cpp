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
    sort(all(a));
    VI b;
    for(int i = 0; i < n;) {
      int j = i;
      while(j < n && a[j] == a[i]) j++;
      if (j - i >= k) b.emplace_back(a[i]);
      i = j;
    }
    int ans = -1;
    int last = -111;
    int cnt = 0;
    int l = -1, r = -1;
    for(int x: b) {
      if (x != last + 1) {
        cnt = 0;
      }
      cnt++;
      if (chmax(ans, cnt)) {
        l = x - cnt + 1;
        r = x;
      }
      last = x;
    }
    if (ans == -1) {
      cout << ans << '\n';
    } else {
      cout << l << ' ' << r << '\n';
    }
  }
}