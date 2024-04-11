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
    VI b;
    for(int i = 0; i < 2 * n; i += 2) {
      if (s[i] != s[i + 1]) {
        int p = (b.size() % 2) ^ (s[i] - '0') ? i : i + 1;
        b.emplace_back(p);
      }
    }
    if (b.size() % 2) {
      cout << -1 << '\n';
      continue;
    }
    int m = b.size();
    cout << m << '\n';
    rep(i, m) cout << b[i] + 1 << " \n"[i + 1 == m];
    rep(i, n) cout << 2 * i + 1 << " \n"[i + 1 == n];
  }
}