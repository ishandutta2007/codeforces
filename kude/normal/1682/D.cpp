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
    string s;
    cin >> s;
    int si = -1;
    char parity = 0;
    rep(i, n) if (s[i] == '1') {
      parity ^= 1;
      si = i;
    }
    if (si == -1 || parity) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<P> ans;
    VI ones;
    int ti = (si + n - 1) % n;
    for(int i = si;; i = (i + 1) % n) {
      if (s[i] == '1') {
        ones.emplace_back(i);
      } else {
        ans.emplace_back(ones.back(), i);
        ones.back() = i;
      }
      if (i == ti) break;
    }
    int root = ones.back(); ones.pop_back();
    for(int i: ones) ans.emplace_back(root, i);
    for(auto [i, j]: ans) cout << i + 1 << ' ' << j + 1 << '\n';
  }
}