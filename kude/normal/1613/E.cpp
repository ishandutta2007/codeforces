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

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

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
    int il = -1, jl = -1;
    rep(i, n) rep(j, m) if (g[i][j] == 'L') {
      il = i, jl = j;
      g[i][j] = '.';
    }
    VVI cnt(n, VI(m));
    rep(i, n) rep(j, m - 1) if (g[i][j] == '.' && g[i][j + 1] == '.') cnt[i][j]++, cnt[i][j + 1]++;
    rep(j, m) rep(i, n - 1) if (g[i][j] == '.' && g[i + 1][j] == '.') cnt[i][j]++, cnt[i + 1][j]++;
    constexpr int INF = 1001001001;
    rep(i, n) rep(j, m) if (g[i][j] == '#') cnt[i][j] = INF;
    vector<vector<char>> added(n, vector<char>(m));
    queue<P> q;
    q.emplace(il, jl);
    added[il][jl] = true;
    while(q.size()) {
      auto [i, j] = q.front(); q.pop();
      rep(k, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || added[ni][nj]) continue;
        cnt[ni][nj]--;
        if (cnt[ni][nj] <= 1) {
          q.emplace(ni, nj);
          added[ni][nj] = true;
        }
      }
    }
    rep(i, n) rep(j, m) if (added[i][j]) g[i][j] = '+';
    g[il][jl] = 'L';
    rep(i, n) cout << g[i] << '\n';
  }
}