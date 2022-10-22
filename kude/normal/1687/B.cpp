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
  int n, m;
  cin >> n >> m;
  VI l(m);
  string s(m, '0');
  rep(i, m) {
    s[i] = '1';
    cout << "? " << s << endl;
    cin >> l[i];
    s[i] = '0';
  }
  vector<int> ord(m);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    return l[i] < l[j];
  });
  rep(i, m) s[i] = '0';
  int ans = 0;
  for(int i: ord) {
    s[i] = '1';
    cout << "? " << s << endl;
    int r;
    cin >> r;
    if (ans + l[i] == r) {
      ans = r;
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << ans << endl;
}