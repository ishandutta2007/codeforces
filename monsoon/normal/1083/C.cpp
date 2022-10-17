#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100;
int n,p[N],q,revp[N],lev[N],tin[N],tout[N],T;
vector<int> adj[N];

void dfs(int v, int l) {
  tin[v] = T++;
  lev[v] = l;
  for (auto u : adj[v]) {
    dfs(u, l+1);
  }
  tout[v] = T;
}

bool desc(int v, int w) {
  return tin[v] <= tin[w] && tout[w] <= tout[v];
}

int child(int v, int w) {
  assert(desc(v, w) && v != w);
  int ans = *prev(upper_bound(adj[v].begin(), adj[v].end(), w,
        [](int i, int j) { return tin[i] < tin[j]; }));
  assert(desc(ans, w));
  return ans;
}

bool islca(int va, int vb, int w) {
  return desc(w, va) && desc(w, vb)
    && (w == va || !desc(child(w, va), vb));
}

bool onpath(int va, int vb, int w) {
  return (desc(w, va) ^ desc(w, vb)) || islca(va, vb, w);
}

struct info_t {
  int a,b;
  info_t() : a(-1), b(-1) { }
  info_t(int a, int b) : a(a), b(b) { }
};

info_t single(int v) {
  return info_t(v, v);
}

info_t join(const info_t& L, const info_t& R) {
  if (L.a != -1 && R.a != -1) {
    const int v[] = { L.a, L.b, R.a, R.b };
    REP(ia,4) REP(ib,ia) {
      int cnt = 0;
      REP(x,4) if (onpath(v[ia], v[ib], v[x])) ++cnt;
      if (cnt == 4) {
        return info_t(v[ia], v[ib]);
      }
    }
  }
  return info_t();
}

template<typename T>
struct segment_tree {
  int n,base;
  vector<T> tree;

  template<typename ForwardIterator>
  segment_tree(ForwardIterator first, ForwardIterator last) {
    n = last - first;
    base = 1;
    while (base < n) base *= 2;
    tree.resize(2*base);
    REP(i,n) { tree[base+i] = single(*first++); }
    for(int i=base-1; i>=1; --i) { fix(i); }
  }

  void fix(int x) {
    tree[x] = join(tree[2*x], tree[2*x+1]);
  }

  template<typename U>
  void update(int x, const U& val) {
    x += base;
    tree[x] = single(val);
    while (x > 1) { fix(x /= 2); }
  }

  template<typename Predicate>
  int longest_good_prefix(Predicate pred_good) {
    // answers x such that [0,x) satisfies predicate but
    // [0,x+1) does not; must be monotonic
    bool empty = true;
    if (pred_good(tree[1])) { return base; }
    T t;
    int x = 1;
    while (x < base) {
      T t2 = empty ? tree[2*x] : join(t, tree[2*x]);
      if (pred_good(t2)) {
        empty = false;
        t = t2;
        x = 2*x+1;
      } else {
        x = 2*x;
      }
    }
    return x - base;
  }
};


int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&p[i]);
  REP(i,n-1) {
    int a; scanf("%d",&a); --a;
    adj[a].push_back(i+1);
  }

  dfs(0, 0);

  REP(i,n) revp[p[i]] = i;
  segment_tree<info_t> tree(revp, revp+n);

  scanf("%d",&q);
  REP(i,q) {
    int t; scanf("%d",&t);

    if (t == 1) {
      int a,b; scanf("%d%d",&a,&b); --a; --b;
      swap(p[a], p[b]);
      swap(revp[p[a]], revp[p[b]]);
      tree.update(p[a], revp[p[a]]);
      tree.update(p[b], revp[p[b]]);
    } else {
      int ans = tree.longest_good_prefix(
            [](const info_t& info) { return info.a != -1; });
      printf("%d\n",ans);
    }
  }
}