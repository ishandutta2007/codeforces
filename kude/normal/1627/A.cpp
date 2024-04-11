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

int dist[53][53];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  constexpr int INF = 1001001001;
  while(tt--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--, c--;
    rep(i, n) rep(j, m) {
      char c;
      cin >> c;
      if (c == 'B') {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
      }
    }
    while(true) {
      bool updated = false;

      rep(i, n) rep(j, m) if (dist[i][j] != INF) {
        int nd = dist[i][j] + 1;
        rep(i2, n) {
          if (nd < dist[i2][j]) {
            dist[i2][j] = nd;
            updated = true;
          }
        }
        rep(j2, m) {
          if (nd < dist[i][j2]) {
            dist[i][j2] = nd;
            updated = true;
          }
        }
      }

      if (!updated) break;
    }
    int ans = dist[r][c];
    if (ans == INF) ans = -1;
    cout << ans << '\n';
  }
}