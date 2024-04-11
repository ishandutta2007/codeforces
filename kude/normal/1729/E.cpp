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

ll ask(ll a, ll b) {
  cout << "? " << a << ' ' << b << endl;
  ll res;
  cin >> res;
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll mx = -1;
  int nxt = 4;
  rep(_, 25) {
    ll r1 = ask(1, nxt);
    if (r1 == -1) {
      mx = nxt - 1;
      break;
    }
    ll r2 = ask(nxt, 1);
    if (r1 != r2) {
      mx = r1 + r2;
      break;
    }
    nxt++;
  }
  cout << "! " << mx << endl;
}