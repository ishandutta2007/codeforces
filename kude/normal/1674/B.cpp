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

int d[26][26];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int id = 1;
  rep(i, 26) rep(j, 26) if (i != j) d[i][j] = id++;
  int tt;
  cin >> tt;
  while(tt--) {
    char c1, c2;
    cin >> c1 >> c2;
    cout << d[c1 - 'a'][c2 - 'a'] << '\n';
  }
}