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

priority_queue<P, vector<P>, greater<P>> q;
bool seen[100010];
int nxt[100010];
int top[100010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    while(!q.empty()) q.pop();
    memset(seen, 0, sizeof(seen));
    memset(top, -1, sizeof(top));
    int mx = 0;
    rep(_, n) {
      int x;
      cin >> x;
      if (seen[x]) continue;
      seen[x] = true;
      int v = x / k;
      chmax(mx, v);
      nxt[x] = top[v];
      top[v] = x;
    }
    int ans = 100010;
    bool cont = true;
    for(int v = 0; cont; v++) {
      chmin(ans, mx - v);
      for(int x = top[v]; x != -1;) {
        if (x == v) {
          cont = false;
          break;
        }
        int nx = nxt[x];
        int nv = x / (x / (v + 1));
        chmax(mx, nv);
        nxt[x] = top[nv];
        top[nv] = x;
        x = nx;
      }
    }
    cout << ans << '\n';
  }
}