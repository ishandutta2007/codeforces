#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
typedef long long ll;


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


const int N = 1000100;
int n,x[N],y[N],idx[N];
ll a[N],dp[N];
envelope<ll> env;

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d%d%lld",&x[i],&y[i],&a[i]); }
  REP(i,n) { idx[i] = i; }
  sort(idx,idx+n, [](int i, int j) { return x[i] < x[j]; });
  dp[n] = 0;
  env.insert(0, 0);
  REPDN(_i,n) {
    int i = idx[_i];
    auto f = env.eval(x[i]);
    ll val = f.first * x[i] + f.second;
    dp[i] = ll(x[i])*y[i] - a[i] + val;
    env.insert(-y[i], dp[i]);
  }
  ll ans = *max_element(dp,dp+n);
  printf("%lld\n", ans);
}