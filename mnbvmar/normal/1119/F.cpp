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

const int MaxN = 3e5;

struct KnownSet {
  VI elems;
  int N;

  struct Node {
    int size;
    LL total;
    Node() : size(0), total(0) {}
  };
  int base;
  vector<Node> data;

  KnownSet() {}
  KnownSet(VI els) : elems(els) {
    debug(els);
    N = SZ(els);
    base = 1;
    while (base < N + 1) { base *= 2; }
    data.resize(base * 2);
  }

  void Add(int v, int c) {
    debug("Add", v, c);
    const int el = elems[v];
    v += base;
    while (v) {
      data[v].size += c;
      data[v].total += c * el;
      v /= 2;
    }
    debug(data[1].size);
  }

  LL GetMaxK(int k) {
    int v = 1;
    LL ans = 0;

    while (v < base) {
      if (data[v * 2].size > k) {
        v *= 2;
      } else {
        ans += data[v * 2].total;
        k -= data[v * 2].size;
        v = v * 2 + 1;
      }
    }
    debug("Get", k, ans);
    return ans;
  }

  int Count() {
    return data[1].size;
  }
};

vector<PII> adj[MaxN];
VI deg_order[MaxN];
VI rev[MaxN];
VI cost_loc[MaxN];
int degs[MaxN];
bool is_active[MaxN];
vector<int> active_list;
KnownSet outgoing[MaxN];
bool visited[MaxN];
int N;

LL total_cost;
LL take_cost;
LL dp_exact[MaxN];
LL dp_almost[MaxN];

void MakeCostDfs(int v, int p, int max_deg) {
  visited[v] = true;
  LL coef = 0;
  vector<LL> changes;

  for (int i = 0; i < SZ(adj[v]); ++i) {
    auto &e = adj[v][deg_order[v][i]];
    if (!is_active[e.st]) { break; }
    if (e.st == p) { continue; }
    MakeCostDfs(e.st, v, max_deg);
    
    coef += dp_exact[e.st];
    changes.PB(dp_almost[e.st] + e.nd - dp_exact[e.st]);
  }

  sort(ALL(changes), greater<LL>());

  dp_exact[v] = dp_almost[v] = 0;

  debug(v, p, coef, changes, max_deg);

  /*int cur_have;
  auto Update = [&]() {
    if (cur_have < max_deg) {
      maxi(dp_almost[v], coef);
    }
    if (cur_have <= max_deg) {
      maxi(dp_exact[v], coef);
    }
  };

  //auto iter = outgoing[v].rbegin();
  for (LL v : changes) { coef += v; }
  cur_have = SZ(changes);

  debug(cur_have, coef);*/

  for (int get_deg : {max_deg - 1, max_deg}) {
    if (get_deg < 0) { continue; }

    LL &upd = get_deg == max_deg ? dp_exact[v] : dp_almost[v];
    LL upd_coef = coef;

    for (int i = 0; i <= SZ(changes) && i <= get_deg; ++i) {
      if (i) { upd_coef += changes[i - 1]; }
      maxi(upd, upd_coef + outgoing[v].GetMaxK(get_deg - i));
    }
  }

  /*for (int i = SZ(changes); i >= 0; --i) {
    if (i != SZ(changes)) { coef -= changes[i]; --cur_have; }

    Update();
  }*/
  /*for (int i = 0; i <= SZ(changes); ++i) {
    if (i) { coef += changes[i - 1]; }
    new_coef = coef;
    cur_have = i;
    for (auto iter = outgoing[v].rbegin(); iter != outgoing[v].rend(); ++iter) {
      Update();
      if (cur_have == max_deg) {
        break;
      }
      ++cur_have;
      new_coef += *iter;
    }
    Update();
  }*/

  debug(v, dp_almost[v], dp_exact[v]);
}

LL GetCost(int max_deg) {
  LL ans = 0;
  for (int v : active_list) {
    if (!visited[v]) {
      MakeCostDfs(v, -1, max_deg);
      ans += dp_exact[v];
    }
  }

  for (int v : active_list) {
    visited[v] = false;
  }
  return take_cost - ans;
}

void Activate(int v) {
  is_active[v] = true;
  active_list.PB(v);

  for (int i = 0; i < SZ(adj[v]); ++i) {
    auto &e = adj[v][i];
    if (!is_active[e.st]) {
      outgoing[v].Add(cost_loc[v][i], 1);
      //outgoing[v].insert(e.nd);
      take_cost += e.nd;
    } else {
      const int j = rev[v][i];
      outgoing[e.st].Add(cost_loc[e.st][j], -1);
      //outgoing[e.st].erase(outgoing[e.st].find(e.nd));
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    rev[u].PB(SZ(adj[v]));
    rev[v].PB(SZ(adj[u]));
    adj[u].emplace_back(v, c);
    adj[v].emplace_back(u, c);
    ++degs[u]; ++degs[v];
  }

  vector<VI> at_deg(N);
  for (int i = 1; i <= N; ++i) {
    deg_order[i].resize(SZ(adj[i]));
    iota(ALL(deg_order[i]), 0);
    sort(ALL(deg_order[i]), [&](int lhs, int rhs) {
          return degs[adj[i][lhs].st] > degs[adj[i][rhs].st];
        });

    at_deg[degs[i]].PB(i);
    /*sort(ALL(adj[i]), [&](const PII &lhs, const PII &rhs) {
          return degs[lhs.st] > degs[rhs.st];
        });*/

    VI cost_order(SZ(adj[i]));
    iota(ALL(cost_order), 0);
    sort(ALL(cost_order), [&](int lhs, int rhs) {
          return adj[i][lhs].nd > adj[i][rhs].nd;
        });

    cost_loc[i].resize(SZ(adj[i]));
    for (int x = 0; x < SZ(adj[i]); ++x) {
      cost_loc[i][cost_order[x]] = x;
    }

    VI costs;
    for (int x = 0; x < SZ(cost_order); ++x) {
      costs.PB(adj[i][cost_order[x]].nd);
    }
    outgoing[i] = KnownSet(costs);
  }

  vector<LL> answers(N);
  for (int cost = N - 2; cost >= 0; --cost) {
    for (int v : at_deg[cost + 1]) {
      Activate(v);
    }

    answers[cost] = GetCost(cost);
  }

  for (LL v : answers) { cout << v << " "; }
  cout << "\n";
}