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
    VI b(n);
    rep(i, n) cin >> b[i], b[i]--;
    VI p(n);
    rep(i, n) cin >> p[i], p[i]--;
    bool ok = true;
    VI ans(n);
    VI dist(n, -1);
    rep(i, n) {
      int v = p[i];
      if (i == 0) {
        if (b[v] != v) {
          ok = false;
          break;
        }
        dist[v] = i;
      } else {
        int par = b[v];
        if (dist[par] == -1) {
          ok = false;
          break;
        }
        dist[v] = i;
        ans[v] = dist[v] - dist[par];
      }
    }
    if (!ok) {
      cout << -1 << '\n';
    } else {
      rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
  }
}