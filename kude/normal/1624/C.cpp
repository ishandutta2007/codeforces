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

int hist[51];

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) hist[i] = 0;
    rep(_, n) {
      int x;
      cin >> x;
      while(x > n) x /= 2;
      hist[x]++;
    }
    bool ok = true;
    for(int i = n; i >= 1; i--) {
      if (!hist[i]) {
        ok = false;
        break;
      }
      int r = hist[i] - 1;
      hist[i / 2] += r;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}