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
    string s;
    cin >> s;
    const int n = s.size();
    VI idx;
    rep(i, n) if (s[i] == '1') idx.emplace_back(i);
    int cnt = idx.size();    
    int l = -1, r = cnt;
    while(r - l > 1) {
      int c = l + r >> 1;
      int rest = cnt - c;
      bool ok = false;
      rep(i, cnt - rest + 1) {
        int cost = idx[i + rest - 1] - idx[i] + 1 - rest;
        if (cost <= c) {
          ok = true;
          break;
        }
      }
      (ok ? r : l) = c;
    }
    cout << r << '\n';
  }
}