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
    string s, t;
    cin >> s >> t;
    auto f = [](const string& s) {
      if (s[0] == 'M') return 0;
      int d = 1;
      for(char c: s) {
        if (c == 'X') d++;
        else if (c == 'L') return d;
        else return -d;
      }
    };
    int r1 = f(s);
    int r2 = f(t);
    cout << (r1 == r2 ? '=' : r1 < r2 ? '<' : '>') << '\n';
  }
}