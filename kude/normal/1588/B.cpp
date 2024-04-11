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

ll query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r << endl;
  ll res;
  cin >> res;
  return res;
}

void answer(int i, int j, int k) {
  cout << "! " << i + 1 << ' ' << j + 1 << ' ' << k << endl;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    ll tot = query(0, n);
    int l = 0, r = n;
    while(r - l > 1) {
      int c = (l + r) / 2;
      if (query(0, c) == tot) {
        r = c;
      } else {
        l = c;
      }
    }
    int tmp = query(0, r - 1);
    ll diff = tot - tmp;
    int j = r - diff - 1;
    ll len2 = r - j;
    ll t1 = tot - len2 * (len2 - 1) / 2;

    auto f = [](ll x) { return x * (x - 1) / 2; };
    ll lb = 0, ub = 1;
    while(f(ub) < t1) lb = ub, ub *= 2;
    while(ub - lb > 1) {
      ll c = (ub + lb) / 2;
      if (f(c) < t1) {
        lb = c;
      } else {
        ub = c;
      }
    }
    assert(f(ub) == t1);
    ll len1 = ub;
    int i = j - len1;
    answer(i, j, r);
  }
}