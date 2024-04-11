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
    vector<P> s;
    rep(i, n) {
      int l, r;
      cin >> l >> r;
      s.emplace_back(l - 1, r);
    }
    sort(all(s), [&](P x, P y){
      return x.second - x.first < y.second - y.first;
    });
    vector<tuple<int, int, int>> ans;
    vector<char> used(n);
    for(auto [l, r] : s) {
      int d = l;
      while(used[d]) d++;
      used[d] = true;
      ans.emplace_back(l, r, d);
    }
    reverse(all(ans));
    for(auto [l, r, d] : ans) {
      cout << l + 1 << ' ' << r << ' ' << d + 1 << '\n';
    }
  }
}