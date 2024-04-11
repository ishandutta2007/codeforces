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
    VI x(m), w(m);
    rep(i, m) cin >> x[i] >> w[i];
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return w[i] < w[j];
    });
    ord.resize(2 * n);
    int sm = 0;
    for(int i: ord) sm += w[i];
    cout << sm << '\n';
    sort(all(ord), [&](int i, int j) {
      return x[i] < x[j];
    });
    rep(i, n) cout << ord[i] + 1 << ' ' << ord[2 * n - 1 - i] + 1 << '\n';
  }
}