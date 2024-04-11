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

int ask(int w) {
  cout << "? " << w << endl;
  int res;
  cin >> res;
  return res;
}

void answer(int x) {
  cout << "! " << x << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int l = 0, r = 2000 * n;
    while(r - l > 1) {
      int c = (l + r) / 2;
      int h = ask(c);
      if (h == 1) r = c;
      else l = c;
    }
    int ans = r;
    for(int d = 2; d <= n; d++) {
      int w = r / d;
      int h = ask(w);
      if (h) chmin(ans, h * w);
    }
    answer(ans);
  }
}