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

bool f2(int c0, int c1, int p);
bool f(int c0, int c1, int p) {
  static bool valid[110][110][2]{};
  static bool memo[110][110][2]{};
  if (!c0 && !c1) return p == 0;
  if (valid[c0][c1][p]) return memo[c0][c1][p];
  valid[c0][c1][p] = true;
  if (c0 && f2(c0-1, c1, p)) return memo[c0][c1][p] = true;
  if (c1 && f2(c0, c1-1, 1^p)) return memo[c0][c1][p] = true;
  return memo[c0][c1][p] = false;
}

bool f2(int c0, int c1, int p) {
  static bool valid[110][110][2]{};
  static bool memo[110][110][2]{};
  if (!c0 && !c1) return p == 0;
  if (valid[c0][c1][p]) return memo[c0][c1][p];
  valid[c0][c1][p] = true;
  if (c0 && !f(c0-1, c1, p)) return memo[c0][c1][p] = false;
  if (c1 && !f(c0, c1-1, p)) return memo[c0][c1][p] = false;
  return memo[c0][c1][p] = true;
}


} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int cnt[2]{};
    rep(i, n) {
      int x;
      cin >> x;
      cnt[x & 1]++;
    }
    cout << (f(cnt[0], cnt[1], 0) ? "Alice\n" : "Bob\n");
  }
}