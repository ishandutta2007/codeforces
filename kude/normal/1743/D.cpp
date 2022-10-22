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

using BS = bitset<1000000>;

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  BS b;
  cin >> b;
  int msb = n - 1;
  while(msb >= 0 && !b[msb]) msb--;
  if (msb == -1) {
    cout << 0 << '\n';
    return 0;
  }
  int last_zero = msb;
  while(last_zero >= 0 && b[last_zero]) last_zero--;
  if (last_zero == -1) {
    rrep(i, msb + 1) cout << b[i];
    cout << '\n';
    return 0;
  }
  BS ans = b;
  for(int k = 1; last_zero + k <= msb; k++) {
    auto nb = b | (b >> k);
    rrep(i, n) {
      if (nb[i] == ans[i]) continue;
      if (nb[i] > ans[i]) ans = nb;
      break;
    }
  }
  rrep(i, msb + 1) cout << ans[i];
  cout << '\n';
}