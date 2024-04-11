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
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    rep(i, n) cin >> g[i];
    rep(j, m) {
      int end = n - 1;
      rrep(i, n) {
        if (g[i][j] == 'o') {
          end = i - 1;
        } else if (g[i][j] == '*') {
          g[i][j] = '.';
          while(g[end][j] != '.') end--;
          g[end--][j] = '*';
        }
      }
    }
    rep(i, n) cout << g[i] << '\n';
  }
}