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
    priority_queue<char, vector<char>, greater<char>> q;
    VI pmin(n);
    pmin[n - 1] = n - 1;
    rrep(i, n - 1) {
      if (s[i] <= s[pmin[i + 1]]) pmin[i] = i;
      else pmin[i] = pmin[i + 1];
    }
    string ans;
    rep(i, n) {
      while(q.size() && q.top() < s[pmin[i]]) {
        ans += q.top(); q.pop();
      }
      if (i != pmin[i]) q.emplace(min('9', char(s[i] + 1)));
      else ans += s[i];
    }
    while(q.size()) {
      ans += q.top(); q.pop();
    }
    cout << ans << '\n';
  }
}