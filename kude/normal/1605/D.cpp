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
    VVI to(n);
    rep(_, n - 1) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      to[u].push_back(v);
      to[v].push_back(u);
    }
    VI col(n, -1);
    col[0] = 0;
    VI st{0};
    while(st.size()) {
      int u = st.back(); st.pop_back();
      for(int v: to[u]) if (col[v] == -1) {
        col[v] = col[u] ^ 1;
        st.push_back(v);
      }
    }
    VI v0, v1;
    rep(i, n) {
      if (col[i] == 0) v0.push_back(i);
      else v1.push_back(i);
    }
    if (v0.size() < v1.size()) swap(v0, v1);
    int k = 0;
    while((1 << (k + 1)) <= n) k++;
    VI p(n);
    for(int i = 1 << k; i <= n; i++) {
      int v = v0.back(); v0.pop_back();
      p[v] = i;
    }
    rrep(d, k) {
      bool flipped = v0.size() < v1.size();
      if (flipped) swap(v0, v1);
      for(int i = 1 << d; i < (1 << (d + 1)); i++) {
        int v = v0.back(); v0.pop_back();
        p[v] = i;
      }
      if (flipped) swap(v0, v1);
    }
    assert(v0.size() == 0 && v1.size() == 0);
    rep(i, n) cout << p[i] << " \n"[i + 1 == n];
  }
}