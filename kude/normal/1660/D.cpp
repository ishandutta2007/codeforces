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
    VI a(n);
    rep(i, n) cin >> a[i];
    int mx = 0;
    int x = n, y = 0;
    for(int i = 0; i < n;) {
      if (a[i] == 0) {
        i++;
        continue;
      }
      int j = i + 1;
      while(j < n && a[j]) j++;
      bool sgn = false;
      int cnt = 0;
      for(int p = i; p < j; p++) {
        if (a[p] < 0) sgn = !sgn;
        if (a[p] == 2 || a[p] == -2) cnt++;
      }
      if (!sgn) {
        if (chmax(mx, cnt)) x = i, y = n - j;
      } else {
        int c = cnt;
        for(int p = i; p < j; p++) {
          if (a[p] == 2 || a[p] == -2) c--;
          if (a[p] < 0) {
            if (chmax(mx, c)) x = p + 1, y = n - j;
            break;
          }
        }
        c = cnt;
        for(int p = j - 1; p >= i; p--) {
          if (a[p] == 2 || a[p] == -2) c--;
          if (a[p] < 0) {
            if (chmax(mx, c)) x = i, y = n - p;
            break;
          }
        }
      }
      i = j;
    }
    cout << x << ' ' << y << '\n';
  }
}