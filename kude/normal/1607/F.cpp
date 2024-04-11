#include<bits/stdc++.h>
namespace {
// #include<atcoder/scc>
using namespace std;
// using namespace atcoder;
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

int to[2000 * 2000];
int dp[2000 * 2000];
int visited[2000 * 2000];
VI vs;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    rrep(i, n * m) to[i] = -1;
    rep(i, n) rep(j, m) {
      char c;
      cin >> c;
      if (c == 'L') {
        if (j) {
          to[i * m + j] = i * m + j - 1;
        }
      } else if (c == 'R') {
        if (j + 1 < m) {
          to[i * m + j] = i * m + j + 1;
        }
      } else if (c == 'D') {
        if (i + 1 < n) {
          to[i * m + j] = (i + 1) * m + j;
        }
      } else {
        if (i) {
          to[i * m + j] = (i - 1) * m + j;
        }
      }
    }
    rrep(i, n * m) visited[i] = -1;
    rrep(i, n * m) if (visited[i] == -1) {
      vs.clear();
      int v = i;
      while(true) {
        if (visited[v] == -1) {
          vs.push_back(v);
          visited[v] = i;
        } else if (visited[v] != i) {
          int d = dp[v];
          int sz = vs.size();
          rrep(i, sz) {
            d++;
            dp[vs[i]] = d;
          }
          break;
        } else {
          int vi = -1;
          int sz = vs.size();
          rep(i, sz) if (vs[i] == v) {
            vi = i;
            break;
          }
          int d = sz - vi;
          for(int i = vi; i < sz; i++) {
            dp[vs[i]] = d;
          }
          rrep(i, vi) {
            d++;
            dp[vs[i]] = d;
          }
          break;
        }
        if (to[v] == -1) {
          int d = 0;
          int sz = vs.size();
          rrep(i, sz) dp[vs[i]] = ++d;
          break;
        } else v = to[v];
      }
    }
    int mx = 0;
    rrep(i, n * m) chmax(mx, dp[i]);
    rrep(i, n * m) if (dp[i] == mx) {
      int x = i / m, y = i % m;
      cout << x + 1 << ' ' << y + 1 << ' ' << dp[i] << '\n';
      break;
    }
  }
}