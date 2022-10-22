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

VI d[1001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 1; i <= 1000; i++) {
    for(int j = 1; j <= 1000; j++) {
      if (gcd(i, j) == 1) d[i].emplace_back(j);
    }
  }
  int tt;
  cin >> tt;
  int last[1001];
  while(tt--) {
    int n;
    cin >> n;
    rep(i, 1001) last[i] = -1;
    int ans = -1;
    for(int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      last[x] = i;
      for(int y: d[x]) if (last[y] != -1) chmax(ans, last[y] + i);
    }
    cout << ans << '\n';
  }
}