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
  VI g(51);
  for(int i = 1; i <= 50; i++) {
    VI d(100);
    for(int j = 1, k = i - 1; j <= k; j++, k--) {
      d[g[j] ^ g[k]] = true;
    }
    int mex = 0;
    while(d[mex]) mex++;
    g[i] = mex;
  }
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int t = 0;
    rep(_, n) {
      int x;
      cin >> x;
      t ^= g[x];
    }
    cout << (t ? "errorgorn\n" : "maomao90\n");
  }
}