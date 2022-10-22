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
    string s;
    cin >> s;
    int n = s.size();
    vector<char> acc_f(n + 1, true), acc_b = acc_f;
    rep(i, n) {
      if (s[i] == '0') acc_f[i+1] = false;
      else acc_f[i+1] = acc_f[i];
    }
    rrep(i, n) {
      if (s[i] == '1') acc_b[i] = false;
      else acc_b[i] = acc_b[i+1];
    }
    int ans = 0;
    rep(i, n) ans += acc_f[i] && acc_b[i+1];
    cout << ans << '\n';
  }
}