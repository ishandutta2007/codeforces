#include<bits/stdc++.h>
namespace {
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
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
    bool used = false;
    string ans;
    cin >> ans;
    rep(_, n - 3) {
      char c1, c2;
      cin >> c1 >> c2;
      if (ans.back() == c1) {
        ans += c2;
      } else {
        ans += c1;
        ans += c2;
        used = true;
      }
    }
    if (!used) ans += 'a';
    cout << ans << '\n';
  }
}