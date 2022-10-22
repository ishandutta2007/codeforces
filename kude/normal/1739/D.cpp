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
    int n, k; 
    cin >> n >> k;
    VI p(n);
    rep(i, n - 1) cin >> p[i+1], p[i+1]--;
    int l = 0, r = n;
    while(r - l > 1) {
      int c = (l + r) / 2;
      int cnt = 0;
      VI height(n);
      rrep(i, n) if (i) {
        if (height[i] + 1 + (p[i] != 0) > c) {
          cnt++;
        } else {
          chmax(height[p[i]], height[i] + 1);
        }
      }
      (cnt <= k ? r : l) = c;
    }
    cout << r << '\n';
  }
}