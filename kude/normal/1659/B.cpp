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
    string s;
    cin >> s;
    if (k % 2) for(char& c: s) c ^= '1' ^ '0';
    VI cnt(n);
    rep(i, n) if (s[i] == '0' && k) {
      s[i] = '1';
      cnt[i]++;
      k--;
    }
    if (k % 2) s[n - 1] = '0';
    cnt[n - 1] += k;
    cout << s << '\n';
    rep(i, n) cout << cnt[i] << " \n"[i + 1 == n];
  }
}