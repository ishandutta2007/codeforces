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
    int n, m, k;
    cin >> n >> m >> k;
    string a, b;
    cin >> a >> b;
    sort(rall(a));
    sort(rall(b));
    int cnt = 0;
    string c;
    while(a.size() && b.size()) {
      if (cnt == k) {
        c += b.back(); b.pop_back();
        cnt = -1;
      } else if (cnt == -k) {
        c += a.back(); a.pop_back();
        cnt = 1;
      } else {
        if (a.back() < b.back()) {
          c += a.back(); a.pop_back();
          cnt = max(cnt + 1, 1);
        } else {
          c += b.back(); b.pop_back();
          cnt = min(cnt - 1, -1);
        }
      }
    }
    cout << c << '\n';
  }
}