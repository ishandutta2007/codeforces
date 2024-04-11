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
    priority_queue<int> q1, q2;
    rep(_, 2) {
      rep(i, n) {
        int x;
        cin >> x;
        q1.emplace(x);
      }
      swap(q1, q2);
    }
    int ans = 0;
    auto get_len = [](int x) {
      int res = 0;
      while(x) {
        res++;
        x /= 10;
      }
      return res;
    };
    while(q1.size()) {
      int x = q1.top(); q1.pop();
      int y = q2.top(); q2.pop();
      if (x == y) continue;
      ans++;
      if (x > y) x = get_len(x);
      else y = get_len(y);
      q1.emplace(x);
      q2.emplace(y);
    }
    cout << ans << '\n';
  }
}