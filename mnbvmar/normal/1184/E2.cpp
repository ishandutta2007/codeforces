#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug & operator<<
#define eni(x) sim>typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim> struct rge { c b, e; };
sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim> auto dud(c*x) -> decltype(cerr<<*x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor (pair<b,c> d) {
  ris<<"("<<d.first<<", "<<d.second<<")";
}
sim dor(rge<c> d) {
  *this<<"[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris <<" ]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int n, m;

const int MaxN = 1e5 + 100;
const int LgMaxN = 18;

int fu_parent[MaxN];
vector<pii> tree_adj[MaxN];
int parent[LgMaxN][MaxN];
int max_edge[LgMaxN][MaxN];
int depth[MaxN];

int FuFind(int v) {
  if (v == fu_parent[v]) { return v; }
  return fu_parent[v] = FuFind(fu_parent[v]);
}

bool FuUnion(int a, int b) {
  a = FuFind(a); b = FuFind(b);
  if (a != b) { fu_parent[a] = b; return true; }
  return false;
}

void DfsTree(int v, int p) {
  parent[0][v] = p;
  for (int i = 1; i < LgMaxN; ++i) {
    const int g = parent[i-1][v];
    parent[i][v] = parent[i-1][g];
    max_edge[i][v] = max(max_edge[i-1][v], max_edge[i-1][g]);
  }
  
  for (auto &&[s, c] : tree_adj[v]) {
    if (s == p) { continue; }
    max_edge[0][s] = c;
    depth[s] = depth[v] + 1;
    DfsTree(s, v);
  }
}

int LCA(int a, int b) {
  if (depth[a] > depth[b]) { swap(a, b); }
  const int d = depth[b] - depth[a];
  for (int i = 0; i < LgMaxN; ++i) {
    if (d & (1 << i)) { b = parent[i][b]; }
  }
  if (a == b) { return a; }
  for (int i = LgMaxN - 1; i >= 0; --i) {
    const int pa = parent[i][a];
    const int pb = parent[i][b];
    if (pa != pb) { a = pa; b = pb; }
  }
  return parent[0][a];
}

int MaxPathUp(int a, int v) {
  const int d = depth[a] - depth[v];
  int ans = 0;
  for (int i = 0; i < LgMaxN; ++i) {
    if ((d >> i) & 1) {
      ans = max(ans, max_edge[i][a]);
      a = parent[i][a];
    }
  }
  return ans;
}

int GetAns(int a, int b) {
  const int L = LCA(a, b);
  return max(MaxPathUp(a, L), MaxPathUp(b, L));
}

int main() {
  scanf("%d%d", &n, &m);
  map<int, int> cost_map;
  
  vector<tuple<int, int, int>> edges(m);
  
  for (int i = 0; i < m; ++i) {
    auto &[c, a, b] = edges[i];
    scanf("%d%d%d", &a, &b, &c);
    cost_map[c] = i;
  }
  sort(edges.begin(), edges.end());
  
  iota(fu_parent, fu_parent + n + 1, 0);
  vi answers(m, -1);
  vector<bool> need_ans(m);
  
  for (int i = 0; i < m; ++i) {
    auto &&[c, a, b] = edges[i];
    if (FuUnion(a, b)) {
      tree_adj[a].emplace_back(b, c);
      tree_adj[b].emplace_back(a, c);
    } else {
      need_ans[i] = true;
    }
  }
  
  DfsTree(1, 1);
  
  for (int i = 0; i < m; ++i) {
    if (need_ans[i]) {
      auto &&[c, a, b] = edges[i];
      debug() << imie(c) << imie(a) << imie(b);
      answers[cost_map[c]] = GetAns(a, b);
    }
  }
  
  for (int i = 0; i < m; ++i) {
    if (answers[i] != -1) { printf("%d\n", answers[i]); }
  }
}