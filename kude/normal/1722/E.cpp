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

ll d[1001][1001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    memset(d, 0, sizeof(d));
    int n ,q;
    cin >> n >> q;
    rep(_, n) {
      int h, w;
      cin >> h >> w;
      d[h][w] += h * w;
    }
    rep(i, 1000) rep(j, 1001) d[i+1][j] += d[i][j];
    rep(i, 1001) rep(j, 1000) d[i][j+1] += d[i][j];
    rep(i, q) {
      int hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      ll ans = d[hb-1][wb-1] - d[hb-1][ws] - d[hs][wb-1] + d[hs][ws];
      cout << ans << '\n';
    }
  }
}