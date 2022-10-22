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
  int n;
  ll x;
  cin >> n >> x;
  map<ll, int> dp{{x, 0}};
  constexpr int INF = 1001001001;
  int ans = INF;
  bool b[10];
  for(auto [k, v]: dp) {
    auto s = to_string(k);
    if ((int)s.size() >= n) {
      if ((int)s.size() == n) chmin(ans, v);
      continue;
    }
    memset(b, 0, sizeof(b));
    for(char c: s) b[c - '0'] = true;
    for(int i = 2; i < 10; i++) if (b[i]) {
      if (auto it = dp.find(k * i); it != dp.end()) {
        chmin(it->second, v + 1);
      } else {
        dp.emplace(k * i, v + 1);
      }
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << '\n';
}