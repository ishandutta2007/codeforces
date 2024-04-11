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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    rep(i, n) cin >> g[i];
    // -(n - 1) <= y - x <= m - 1
    const int B = n - 1;
    VI d(B + m);
    int low = 0, high = 0;
    int ans = 0;
    // d[B+low, B+high] is valid range
    for(int xpy = 0; xpy <= n - 1 + m - 1; xpy++) {
      int xmax = min(xpy, n - 1), ymax = min(xpy, m - 1);
      int new_low = (xpy - xmax) - xmax, new_high = ymax - (xpy - ymax);
      low = new_low;  // discard element if it gets out of range
      // move down
      while(high > new_high) {
        d[B + high - 2] += d[B + high];
        high--;
      }
      high = new_high;
      int p = -1001001001;
      for(int y = ymax, x = xpy - y; x <= xmax; x++, y--) {
        int xy = y - x;
        if (d[B + xy]) p = xy;
        if (g[x][y] == '0' || d[B + xy]) continue;
        // if (x == 1 && y == 0 && tt == 0) {
        //   cout << "?!" << ans << ' ' << low << ' ' << high << ' ' << p << '\n';
        //   for(int i = low; i <= high; i++) cout << d[B + i] << " \n"[i == high];
        //   exit(0);
        // }
        if (p == -1001001001) {
          ans++;
          d[B + xy]++;
          p = xy;
        } else {
          assert(d[B + p] > 0);
          d[B + p]--;
          d[B + xy]++;
          p = xy;
        }
      }
      // cout << "!!" << ans << ' ' << low << ' ' << high << '\n';
      // for(int i = low; i <= high; i++) cout << d[B + i] << " \n"[i == high];
    }
    cout << ans << '\n';
  }
}