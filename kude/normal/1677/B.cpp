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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    VI row(n * m + 1);
    int now = 0;
    rep(i, n * m) {
      now += s[i] - '0';
      row[i+1] = now >= 1;
      if (i + 1 >= m) now -= s[i+1-m] - '0';
    }
    for(int i = m; i <= n * m; i++) row[i] += row[i - m];
    vector<char> col(m);
    int sm = 0;
    rep(i, n * m) {
      if (s[i] == '1') {
        int p = i % m;
        if (!col[p]) {
          col[p] = true;
          sm++;
        }
      }
      cout << row[i + 1] + sm << " \n"[i + 1 == n * m];
    }
  }
}