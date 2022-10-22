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

bool solve() {
  int n;
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i];
  int p = 0, q = n - 1;
  for(; p < q; p++, q--) {
    if (a[p] != a[q]) break;
  }
  if (p >= q) return true;
  for(int x: {a[p], a[q]}) {
    VI b; b.reserve(n);
    for(int ai: a) if (ai != x) b.push_back(ai);
    bool ok = true;
    for(int i = 0, j = (int)b.size() - 1; i < j; i++, j--) {
      if (b[i] != b[j]) {
        ok = false;
        break;
      }
    }
    if (ok) return true;
  }
  return false;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}