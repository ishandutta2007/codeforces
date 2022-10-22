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

template<int element_size>
struct array_set {
  int state[element_size];  // -1 if not in set else index in elems
  int elems[element_size];
  int size = 0;
  array_set() { memset(state, -1, sizeof(int) * element_size); }
  void insert(int x) {
    if (state[x] == -1) {
      state[x] = size;
      elems[size] = x;
      size++;
    }
  }
  bool contains(int x) { return state[x] != -1; }
  int* begin() { return elems; }
  int* end() { return elems + size; }
  void clear() { while(size) state[elems[--size]] = -1; }
  void erase(int x) {  // not tested
    int idx = state[x];
    if (idx != -1) {
      state[x] = -1;
      size--;
      if (idx != size) {
        int y = elems[size];
        state[y] = idx;
        elems[idx] = y;
      }
    }
  }
};

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  VVI to_inv(n);
  VI deg(n);
  rep(_, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u == n - 1) continue;
    deg[u]++;
    to_inv[v].emplace_back(u);
  }
  priority_queue<P, vector<P>, greater<P>> q;
  VI res(n, -1);
  res[n - 1] = 0;
  q.emplace(0, n - 1);
  vector<char> done(n);
  while(true) {
    while(q.size() && done[q.top().second]) q.pop();
    if (q.empty()) break;
    int d = q.top().first;
    // VI vs;
    static array_set<200100> vs;
    vs.clear();
    while(q.size() && q.top().first == d) {
      auto [dv, v] = q.top(); q.pop();
      if (done[v]) continue;
      done[v] = true;
      res[v] = d;
      vs.insert(v);
    }
    for(int v: vs) for(int u: to_inv[v]) if (!done[u]) {
      deg[u]--;
      q.emplace(deg[u] + 1 + d, u);
    }
  }
  cout << res[0] << '\n';
}