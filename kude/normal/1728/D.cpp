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

signed char dp[2001][2001];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    const int n = s.size();
    auto f = [&](char ca, char cb, int l, int r) {
      int d = dp[l][r];
      if (d) return d;
      if (ca < cb) return 1;
      else if (ca > cb) return -1;
      else return 0;
    };
    rep(r, n + 1) {
      dp[r][r] = 0;
      for(int l = r - 2; l >= 0; l -= 2) {
        dp[l][r] =  max(
                      min(
                        f(s[l], s[l+1], l+2, r),
                        f(s[l], s[r-1], l+1, r-1)
                      ),
                      min(
                        f(s[r-1], s[l], l+1, r-1),
                        f(s[r-1], s[r-2], l, r-2)
                      )
                    );
      }
    }
    int r = dp[0][n];
    cout << (r == 1 ? "Alice\n" : r == 0 ? "Draw\n" : "Bob\n");
  }
}