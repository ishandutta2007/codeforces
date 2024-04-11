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
    int n, k;
    cin >> n >> k;
    VI a(n);
    VI hist(n);
    rep(i, n) {
      int x;
      cin >> x; x--;
      hist[x]++;
      a[i] = x;
    }
    VI s(n + 1);
    rep(i, n) s[i + 1] = s[i] + hist[i];
    int r = 0;
    int now = 0;
    int m = (n + k + 1) / 2;
    int x0 = 0, y0 = n;
    rep(l, n) {
      while(r < n && now < m) now += hist[r++];
      if (now < m) break;
      if (r - l < y0 - x0) x0 = l, y0 = r;
      now -= hist[l];
    }
    int i = 0;
    VI ans(k + 1);
    rep(t, k) {
      ans[t] = i;
      int now = 0;
      while(now <= 0) {
        if (x0 <= a[i] && a[i] < y0) now++;
        else now--;
        i++;
      }
    }
    ans[k] = n;
    cout << x0 + 1 << ' ' << y0 << '\n';
    rep(i, k) cout << ans[i] + 1 << ' ' << ans[i + 1] << '\n';
  }
}