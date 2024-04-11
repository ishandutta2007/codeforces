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
    VI x(n);
    rep(i, n) {
      int a;
      cin >> a;
      x[i] = -a;
    }
    rep(i, n) {
      int a;
      cin >> a;
      x[i] += a;
    }
    sort(all(x));
    int ans = 0;
    for(int i = n - 1, j = 0; j < i; i--, j++) {
      while(j < i && x[j] + x[i] < 0) j++;
      if (j == i) break;
      ans++;
    }
    cout << ans << '\n';
  }
}