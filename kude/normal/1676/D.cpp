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

const int di[] = {1, -1, -1, 1};
const int dj[] = {1, 1, -1, -1};

int a[210][210];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j];
    int ans = 0;
    auto idxchk = [&](int i, int j) { return 0 <= i && i < n && 0 <= j && j < m; };
    rep(i, n) rep(j, m) {
      int v = a[i][j];
      rep(k, 4) {
        int x = i + di[k], y = j + dj[k];
        while(idxchk(x, y)) {
          v += a[x][y];
          x += di[k];
          y += dj[k];
        }
      }
      chmax(ans, v);
    }
    cout << ans << '\n';
  }
}