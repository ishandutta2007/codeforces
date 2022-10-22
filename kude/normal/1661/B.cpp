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

int d[1 << 15];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  d[(1 << 15) - 1] = 1;
  rrep(i, (1 << 15) - 1) if (i) {
    d[i] = min(d[i+1] + 1, 15 - __builtin_ctz(i));
  }
  int n;
  cin >> n;
  rep(i, n) {
    int x;
    cin >> x;
    cout << d[x] << " \n"[i + 1 == n];
  }
}