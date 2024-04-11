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
    vector<string> s[3];
    map<string, int> cnt;
    rep(i, 3) rep(j, n) {
      string t;
      cin >> t;
      cnt[t]++;
      s[i].emplace_back(move(t));
    }
    rep(i, 3) {
      int p = 0;
      for(const string& t: s[i]) {
        int x = cnt[t];
        p += x == 1 ? 3 : x == 2 ? 1 : 0;
      }
      cout << p << " \n"[i + 1 == 3];
    }
  }
}