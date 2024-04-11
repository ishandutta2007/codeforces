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

vector<vector<int>> cycle_decomposition(const vector<int>& a) {
  const int n = a.size();
  vector<char> visited(n);
  vector<vector<int>> res;
  for(int i = 0; i < n; i++) if (!visited[i]) {
    res.emplace_back();
    auto& vs = res.back();
    int v = i;
    do {
      visited[v] = true;
      vs.push_back(v);
      v = a[v];
    } while (v != i);
  }
  return res;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    VI ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
      return a[i] < a[j];
    });
    bool dup = false;
    rep(i, n - 1) {
      if (a[ord[i]] == a[ord[i + 1]]) {
        dup = true;
        break;
      }
    }
    if (dup) {
      cout << "YES\n";
      continue;
    }
    bool ok = (n - cycle_decomposition(ord).size()) % 2 == 0;
    cout << (ok ? "YES\n" : "NO\n");
  }
}