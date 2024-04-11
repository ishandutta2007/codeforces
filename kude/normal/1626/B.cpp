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
    string x;
    cin >> x;
    const int n = x.size();
    bool done = false;
    rrep(i, n - 1) {
      int x1 = x[i] - '0', x0 = x[i + 1] - '0';
      if (x1 + x0 >= 10) {
        done = true;
        x[i] = (x1 + x0) / 10 + '0';
        x[i + 1] = (x1 + x0) % 10 + '0';
        cout << x << '\n';
        break;
      }
    }
    if (done) continue;
    int d = (x[0] - '0') + (x[1] - '0');
    x[1] = '0' + d;
    x.erase(x.begin());
    cout << x << '\n';
  }
}