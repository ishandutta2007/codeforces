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
    int k;
    cin >> k;
    bool special[26]{};
    rep(i, k) {
      char c;
      cin >> c;
      special[c - 'a'] = true;
    }
    int ans = 0;
    for(int i = 0; i < n;) {
      int j = i;
      while(j < n && !special[s[j] - 'a']) j++;
      if (j == n) break;
      if (i) chmax(ans, j - i + 1);
      else chmax(ans, j);
      i = j + 1;
    }
    cout << ans << '\n';
  }
}