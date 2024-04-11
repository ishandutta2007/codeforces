#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;


template<class T>
struct centroid_decomposition {
  const T& t;
  vector<int> siz, ms, vis;
  vector<int> clev, cpar;
  int croot;

  centroid_decomposition(const T& t) : t(t), siz(t.n), ms(t.n), clev(t.n, -1), cpar(t.n) {
    croot = centroid(0, t.n, 0);
  }

  void dfs(int v, int par) {
    siz[v] = 1; ms[v] = 0;
    vis.push_back(v);
    for (auto u : t.adj[v]) if (u != par && clev[u] == -1) {
      dfs(u, v);
      siz[v] += siz[u];
      ms[v] = max(ms[v], siz[u]);
    }
  }

  int centroid(int v, int par, int lev) {
    vis.clear();
    cpar[v] = par;
    dfs(v, -1);
    pair<int,int> best = { siz[v], -1 };
    for (auto u : vis) {
      best = min(best, { max(ms[u], siz[v]-siz[u]), u });
    }
    int c = best.second;
    clev[c] = lev;
    for (auto u : t.adj[c]) if (clev[u] == -1) {
      centroid(u, c, lev+1);
    }
    return c;
  }
};


template<typename T>
inline T ceil_div(const T& a, const T& b) {
  assert(b > 0);
  if (a < 0) return -( (-a)/b );
  else return (a + b-1) / b;
}

template<typename T>
struct typeinfo {
  static const T infty;
};

template<>
const ll typeinfo<ll>::infty = 4000000000000000000LL;

template<typename T>
struct line {
  T a, b;
  mutable T xl;

  bool operator<(const line& other) const {
    if (max(a, other.a) == typeinfo<T>::infty+1) {
      return xl < other.xl;
    } else {
      return make_pair(a, b) < make_pair(other.a, other.b);
    }
  }

  T inters(const line& prev) const {
    return ceil_div(prev.b - b, a - prev.a);
  }

  bool valid(const line& prev, const line& next) const {
    return inters(prev) < next.inters(*this);
  }

  void update(const line& prev) const {
    xl = inters(prev);
  }
};

template<typename T>
struct envelope {
  set<line<T> > s;

  void insert(const T& a, const T& b) {
    assert(max(abs(a), abs(b)) <= typeinfo<T>::infty);

    auto it = s.insert({ a, b, -2*typeinfo<T>::infty }).first;

    if (next(it) != s.end() && a == next(it)->a) {
      s.erase(it);
      return;
    }
    if (it != s.begin() && prev(it)->a == a) {
      s.erase(prev(it));
    }

    if (it != s.begin() && next(it) != s.end() && !it->valid(*prev(it), *next(it))) {
      s.erase(it);
      return;
    }

    if (it != s.begin()) {
      auto pit = prev(it);
      while (pit != s.begin() && !pit->valid(*prev(pit), *it)) {
        s.erase(pit);
        pit = prev(it);
      }
      it->update(*pit);
    }

    if (next(it) != s.end()) {
      auto nit = next(it);
      while (next(nit) != s.end() && !nit->valid(*it, *next(nit))) {
        s.erase(nit);
        nit = next(it);
      }
      nit->update(*it);
    }
  }

  bool empty() const { return s.empty(); }
  void clear() { s.clear(); }

  pair<T,T> eval(const T& x) const {
    auto it = prev(s.upper_bound({ typeinfo<T>::infty+1, 0, x }));
    return make_pair(it->a, it->b);
  }
};


const int N = 151000;
int n,val[N];
vector<pair<ll,ll> > up[N],dn[N];
  // up = (cost,sum)
  // dn = (cost,len)
ll ans;

template<typename T>
inline void purge(vector<T>& c) { vector<T>().swap(c); }


struct tree {
  vector<vector<int> > adj;
  int n;

  tree(int n) : n(n), adj(n) { }

  void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
};


tree* t;
centroid_decomposition<tree>* cd;


void dfs(int v, int par, int _clev, int root, ll up_cost, ll dn_cost, ll sum, int len) {
  ll new_up_cost = up_cost + val[v]*ll(len+1);
  ll new_dn_cost = dn_cost + sum + val[v];
  ll new_sum = sum + val[v];
  int new_len = len + 1;
  up[root].push_back({ new_up_cost, new_sum });
  dn[root].push_back({ new_dn_cost, new_len });

  for (auto u : t->adj[v]) if (u != par && cd->clev[u] > _clev) {
    dfs(u, v, _clev, root, new_up_cost, new_dn_cost, new_sum, new_len);
  }
}

void calculate(int v) {
  envelope<ll> UP;
  vector<int> vis;

  for (auto u : t->adj[v]) if (cd->clev[u] > cd->clev[v]) {
    dfs(u, v, cd->clev[v], u, 0, 0, 0, 0);

    vis.push_back(u);

    for (auto p : dn[u]) {
      ll cost = p.first, len = p.second;
      ll new_cost = cost + val[v]*(len+1);
      ans = max(ans, new_cost);
      if (!UP.empty()) {
        pair<ll,ll> fun = UP.eval(len);
        ans = max(ans, fun.first*len + fun.second + cost);
      }
    }
    for (auto p : up[u]) {
      ll cost = p.first, sum = p.second;
      ll new_cost = cost + sum + val[v];
      ll new_sum = sum + val[v];
      ans = max(ans, new_cost);
      UP.insert(new_sum, new_cost);
    }
  }

  UP.clear();

  reverse(vis.begin(), vis.end());
  for (auto u : vis) {
    for (auto p : dn[u]) {
      ll cost = p.first, len = p.second;
      if (!UP.empty()) {
        pair<ll,ll> fun = UP.eval(len);
        ans = max(ans, fun.first*len + fun.second + cost);
      }
    }
    for (auto p : up[u]) {
      ll cost = p.first, sum = p.second;
      ll new_cost = cost + sum + val[v];
      ll new_sum = sum + val[v];
      ans = max(ans, new_cost);
      UP.insert(new_sum, new_cost);
    }
  }

  for (auto u : vis) {
    purge(up[u]);
    purge(dn[u]);
  }

  ans = max(ans, ll(val[v]));
}

int main() {
  scanf("%d",&n);
  t = new tree(n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    t->add_edge(a, b);
  }
  REP(i,n) scanf("%d",&val[i]);

  cd = new centroid_decomposition<tree>(*t);

  REP(i,n) calculate(i);

  printf("%lld\n", ans);
}