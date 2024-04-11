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

char c[10][10];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    rep(i, 8) cin >> c[i];
    for(int i = 1; i < 7; i++) {
      for(int j = 1; j < 7; j++) {
        if (
            c[i][j] == '#' &&
            c[i+1][j+1] == '#' &&
            c[i+1][j-1] == '#' &&
            c[i-1][j+1] == '#' &&
            c[i-1][j-1] == '#') {
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
      }
    }
  }
}