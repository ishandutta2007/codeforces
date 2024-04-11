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

int ask(int i, int j) {
  cout << "? " << i + 1 << ' ' << j + 1 << endl;
  int res;
  cin >> res;
  return res;
}

void answer(int i) {
  cout << "! " << i + 1 << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI d(1 << n);
    iota(all(d), 0);
    VI nd;
    while(n > 1) {
      n -= 2;
      nd.clear();
      for(int i = 0; i < (1 << (n + 2)); i += 4) {
        int r = ask(d[i], d[i + 2]);
        if (r == 0) {
          nd.emplace_back(d[ask(d[i + 1], d[i + 3]) == 1 ? i + 1 : i + 3]);
        } else if (r == 1) {
          nd.emplace_back(d[ask(d[i], d[i + 3]) == 1 ? i : i + 3]);
        } else {
          nd.emplace_back(d[ask(d[i + 1], d[i + 2]) == 1 ? i + 1 : i + 2]);
        }
      }
      swap(d, nd);
    }
    if (n == 1) {
      int r = ask(d[0], d[1]);
      assert(r != 0);
      if (r == 2) swap(d[0], d[1]);
      d.pop_back();
    }
    int ans = d[0];
    answer(ans);
  }
}