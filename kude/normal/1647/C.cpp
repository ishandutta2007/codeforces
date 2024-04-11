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
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    if (s[0][0] == '1') {
      cout << -1 << '\n';
      continue;
    }
    vector<tuple<int, int, int, int>> ans;
    rrep(i, n) rrep(j, m) if (s[i][j] == '1') {
      if (i) ans.emplace_back(i - 1, j, i, j);
      else ans.emplace_back(i, j - 1, i, j);
    }
    int sz = ans.size();
    cout << sz << '\n';
    for(auto [i, j, k, l]: ans) {
      cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' ' << l + 1 << '\n';
    }
  }
}