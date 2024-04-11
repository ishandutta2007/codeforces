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

bool is_square[200010];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 0; i * i < 200010; i++) is_square[i * i] = true;
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI ans(n);
    for(int i = n - 1; i >= 0; i--) {
      int x = 2 * i;
      while(!is_square[x]) x--;
      int ni = x - i;
      assert(ni >= 0 && ni <= i);
      for(int p = i, q = ni; p >= ni; p--, q++) {
        ans[p] = q;
      }
      i = ni;
    }
    rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
  }
}