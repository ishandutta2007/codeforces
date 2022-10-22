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
    priority_queue<int> q;
    ll ans = 0;
    rep(i, n) {
      if (s[i] == 'L') {
        ans += i;
        int d = n - 1 - i - i;
        if (d > 0) q.emplace(d);
      } else {
        ans +=  n - 1 - i;
        int d = i - (n - 1 - i);
        if (d > 0) q.emplace(d);
      }
    }
    rep(i, n) {
      if (!q.empty()) {
        ans += q.top(); q.pop();
      }
      cout << ans << " \n"[i + 1 == n];
    }
  }
}