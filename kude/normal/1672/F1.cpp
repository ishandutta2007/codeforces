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
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i], a[i]--;
    VVI d(n);
    rep(i, n) d[a[i]].emplace_back(i);
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return d[i].size() < d[j].size();
    });
    auto dests = d;
    auto dest_ord = ord;
    VI b(n);
    int di = 0;
    rotate(ord.begin(), ord.begin() + n - 1, ord.end());
    for(int i: ord) {
      int cnt = d[i].size();
      while(cnt) {
        while(dests[dest_ord[di]].empty()) di++;
        b[dests[dest_ord[di]].back()] = i;
        dests[dest_ord[di]].pop_back();
        cnt--;
      }
    }
    rep(i, n) cout << b[i] + 1 << " \n"[i + 1 == n];
  }
}