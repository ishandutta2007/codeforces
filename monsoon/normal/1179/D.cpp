#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

template<typename T>
inline void minimize(T& a, const T& b) { if (a > b) a = b; }

namespace cp {

struct tree {
  int n;
  vector<vector<int> > adj;

  vector<int> siz;

  void create(int _n) {
    n = _n;
    adj.resize(n);
    siz.resize(n);
  }

  void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  void dfs(int v, int p, int l) {
    siz[v] = 1;
    if (p != -1) {
      adj[v].erase(find(adj[v].begin(), adj[v].end(), p));
    }
    for (auto& i : adj[v]) {
      dfs(i, v, l+1);
      siz[v] += siz[i];
    }
  }

  void init() {
    dfs(0, -1, 0);
  }

};

}

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
const int typeinfo<int>::infty = 1000000000;
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

ll sq(int x) { return ll(x)*x; }

cp::tree t;
ll Ans;

ll dfs(int v) {
  ll dp = sq(t.siz[v]);

  envelope<ll> envel;

  for (auto u : t.adj[v]) {
    ll dpu = dfs(u);
    minimize(Ans, dpu + sq(t.n - t.siz[u]));
    minimize(dp, dpu + sq(t.siz[v] - t.siz[u]));

    if (!envel.empty()) {
      ll x = -2*(t.n - t.siz[u]);
      auto f = envel.eval(x);
      ll cost = dpu + sq(t.n - t.siz[u]) + -f.first * x + -f.second;
      minimize(Ans, cost);
    }
    envel.insert(-( t.siz[u] ), -( dpu + sq(t.siz[u]) ));
  }

  return dp;
}

int main() {
  int n; scanf("%d",&n);
  t.create(n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a;--b;
    t.add_edge(a,b);
  }
  t.init();

  Ans = sq(n);
  dfs(0);

  ll add = (sq(n) - Ans) / 2;
  ll ans = ll(n)*(n-1)/2 + add;
  printf("%lld\n",ans);
}