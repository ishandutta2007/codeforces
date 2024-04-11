#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 2e5 + 100;

struct Tree {
  struct Node {
    int min_value;
    int count_min;
    int push_add;

    Node() : min_value(1), count_min(1), push_add(0) {}
  };

  int Base;
  vector<Node> data;

  Tree(int N) : Base(1) {
    while (Base < N + 3) { Base *= 2; }
    data.resize(Base * 2);

    for (int i = Base - 1; i > 0; --i)
      data[i].count_min = data[i * 2].count_min + data[i * 2 + 1].count_min;
  }

  void Push(int v) {
    if (v < Base) {
      for (int s : {v * 2, v * 2 + 1}) {
        data[s].push_add += data[v].push_add;
        data[s].min_value += data[v].push_add;
      }
      data[v].push_add = 0;
    }
  }

  int q_left, q_right, q_val;

  void AddIntvRec(int l_base, int r_base, int v) {
    if (r_base <= q_left || l_base >= q_right) { return; }
    Push(v);
    if (q_left <= l_base && r_base <= q_right) {
      data[v].min_value += q_val;
      data[v].push_add += q_val;
      return;
    }

    const int m = (l_base + r_base) / 2;
    AddIntvRec(l_base, m, v * 2);
    AddIntvRec(m, r_base, v * 2 + 1);

    data[v].min_value = min(data[v * 2].min_value, data[v * 2 + 1].min_value);
    data[v].count_min = 0;
    for (int s : {v * 2, v * 2 + 1})
      if (data[v].min_value == data[s].min_value)
        data[v].count_min += data[s].count_min;
  }

  void AddIntv(int left, int right, int val) {
    debug("AddIntv", left, right, val);
    q_left = left;
    q_right = right;
    q_val = val;

    AddIntvRec(0, Base, 1);
  }

  PII GetMin() const {
    debug(data[1].min_value, data[1].count_min);
    return {data[1].min_value, data[1].count_min};
  }
};

int N, Q;

vector<int> adj[MaxN];
int tree_size[MaxN];
int parent[MaxN];
vector<int> children[MaxN];
vector<int> children_preorders[MaxN];
int path_idx[MaxN], path_loc[MaxN];
int path_parent[MaxN];
int num_paths = 0;

int preorder[MaxN], postorder[MaxN];
int cur_time = 0;

void DfsPreorder(int v, int p) {
  preorder[v] = cur_time++;
  for (int s : adj[v]) {
    if (s == p) { continue; }
    children[v].push_back(s);
    DfsPreorder(s, v);
    children_preorders[v].push_back(preorder[s]);
  }
  postorder[v] = cur_time;
}

void DfsSize(int v, int p) {
  tree_size[v] = 1;
  parent[v] = p;
  for (int s : adj[v]) {
    if (s == p) { continue; }
    children[v].push_back(s);
    DfsSize(s, v);
    tree_size[v] += tree_size[s];
  }
}

void MakePaths(int v, int idx, int loc) {
  path_idx[v] = idx;
  path_loc[v] = loc;
  if (!loc)
    path_parent[idx] = v;
  int best_val = -1;
  int best_who = -1;

  for (int s : children[v]) {
    if (tree_size[s] > best_val) {
      best_val = tree_size[s];
      best_who = s;
    }
  }

  if (best_val == -1) { return; }

  MakePaths(best_who, idx, loc + 1);
  for (int s : children[v])
    if (s != best_who) {
      const int new_idx = num_paths++;
      MakePaths(s, new_idx, 0);
    }
}

int cur_num_good;
Tree *tree;



void AddEdge(int u, int v, int coef) {
  if (preorder[u] > preorder[v]) { swap(u, v); }

  if (postorder[u] >= postorder[v]) {
    auto &ch = children[u];
    auto &pres = children_preorders[u];
    auto iter = upper_bound(ALL(pres), preorder[v]) - 1;
    int next_child = ch[iter - pres.begin()];
    debug(next_child);
    tree->AddIntv(preorder[next_child], postorder[next_child], coef);
    tree->AddIntv(preorder[v], postorder[v], -coef);
  } else {
    tree->AddIntv(0, N, coef);
    tree->AddIntv(preorder[u], postorder[u], -coef);
    tree->AddIntv(preorder[v], postorder[v], -coef);
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> Q;
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  DfsPreorder(1, 1);

  /* DfsSize(1, 1);
  MakePaths(1, num_paths++, 0); */

  set<PII> cur_edges;

  tree = new Tree(N + 2);
  tree->AddIntv(0, N, -1);
  tree->GetMin();

  for (int i = 0; i < Q; ++i) {
    int u, v;
    cin >> u >> v;
    if (u > v) { swap(u, v); }

    if (cur_edges.count(make_pair(u, v))) {
      AddEdge(u, v, -1);
      cur_edges.erase(make_pair(u, v));
    } else {
      AddEdge(u, v, 1);
      cur_edges.insert(make_pair(u, v));
    }

    auto good_info = tree->GetMin();

    const int num_good = good_info.st == 0 ? good_info.nd : 0;

    cout << num_good << "\n";
  }

  delete tree;
}