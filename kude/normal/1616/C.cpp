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
    VI a(n);
    rep(i, n) cin >> a[i];
    int mx = 1;
    rep(j, n) rep(i, j) {
      int dx = a[j] - a[i];
      int di = j - i;
      int g = gcd(dx, di);
      dx /= g;
      di /= g;
      int p = i;
      int x = a[i];
      while(p - di >= 0) {
        p -= di;
        x -= dx;
      }
      int cnt = 0;
      while(p < n) {
        if (a[p] == x) cnt++;
        p += di;
        x += dx;
      }
      chmax(mx, cnt);
    }
    cout << n - mx << '\n';
  }
}