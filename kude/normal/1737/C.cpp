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
    int r[4], c[4];
    rep(i, 4) cin >> r[i] >> c[i], r[i]--, c[i]--;
    bool ok = false;
    bool corner = false;
    rep(_, 4) {
      rep(i, 4) {
        int nx = n - 1 - c[i], ny = r[i];
        r[i] = nx;
        c[i] = ny;
      }
      int b = 0;
      rep(i, 3) {
        if (r[i] == 0 && c[i] == 0) {
          b |= 1;
        } else if (r[i] == 1 && c[i] == 1) {
          b |= 2;
        }
      }
      if (b == 1) {
        corner = true;
        if (r[3] == 0 || c[3] == 0) ok = true;
        break;
      }
    }
    if (!corner) {
      rep(i, 3) {
        if (r[i] % 2 == r[3] % 2 && c[i] % 2 == c[3] % 2) {
          ok = true;
          break;
        }
      }
    }
    rep(i, 3) if (r[i] == r[3] && c[i] == c[3]) ok = true;
    cout << (ok ? "YES\n" : "NO\n");
  }
}