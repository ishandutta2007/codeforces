#include <bits/stdc++.h>

using namespace std;

template <class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')
    cerr<<*sdbg++;
  cerr<<"="<<h<<","; 
  _dbg(sdbg+1, a...);
}

template<class T> ostream & operator<<(ostream & os, vector<T> V){
  os<<"[";
  for(auto vv: V) os << vv <<",";
  return os << "]";
}
template<class L, class R> ostream & operator <<(ostream & os, pair<L,R> P){
  return os <<"("<<P.first <<","<<P.second <<")";
}

#ifdef DEBUG
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

typedef long long ll;

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

LineContainer hull;

const int N = 150005;

int n, a, b, val[N];
vector<int> V[N];
bool wasCen[N];
long long ans;
int subSize[N];
int biggest[N];
vector<int> nodes;


void DFS(int w, int par = -1) {
    nodes.push_back(w);
    subSize[w] = 1;
    biggest[w] = 0;
    for (int u : V[w]) {
        if (par == u || wasCen[u]) continue;
        DFS(u, w);
        subSize[w] += subSize[u];
        biggest[w] = max(biggest[w], biggest[u]);
    }
}

void DFS2(int w, int par, int depth, long long totalSum, long long sumPref) {
    sumPref += val[w];
    totalSum += sumPref;
    ans = max(ans, totalSum + hull.query(depth));
    for (int u : V[w]) {
        if (par == u || wasCen[u]) {
            continue;
        }
        DFS2(u, w, depth + 1, totalSum, sumPref);
    }
}

void DFS3(int w, int par, int depth, long long totalSum, long long sumPref) {
    sumPref += val[w];
    totalSum += (long long)val[w] * depth;
    hull.add(sumPref, totalSum);
    
    for (int u : V[w]) {
        if (par == u || wasCen[u]) {
            continue;
        }
        DFS3(u, w, depth + 1, totalSum, sumPref);
    }
}

void decomp(int r) {
    nodes.clear();
    DFS(r);
    int centroid = -1;
    for (int w : nodes) {
        if (2 * biggest[w] <= nodes.size() && 2 * (nodes.size() - subSize[w]) <= nodes.size()) {
            centroid = w;
        }
    }
    
    for (int reps = 0; reps < 2; reps++) {
        
        hull.clear();
        hull.add(val[centroid], val[centroid]);
        for (int v : V[centroid]) {
            if (wasCen[v]) continue;
            DFS2(v, centroid, 1, 0, 0);
            DFS3(v, centroid, 2, val[centroid], val[centroid]);
            ans = max(ans, hull.query(0));
        }
        
        
        reverse(V[centroid].begin(), V[centroid].end());
    }
    
    
    wasCen[centroid] = true;
    for (int u : V[centroid]) {
        if (wasCen[u]) continue;
        decomp(u);
    }
    
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    
    decomp(1);
    
    printf("%lld\n", ans);
    
    return 0;
}