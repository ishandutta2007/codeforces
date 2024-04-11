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
    auto f = [](char c) {
      return c - 'a' + 1;
    };
    int n = s.size();
    if (n == 1) {
      cout << "Bob " << f(s[0]) << '\n';
      continue;
    }
    int sm = 0;
    for(char c: s) sm += f(c);
    if (n % 2) sm -= 2 * min(f(s[0]), f(s[n - 1]));
    cout << "Alice " << sm << '\n';
  }
}