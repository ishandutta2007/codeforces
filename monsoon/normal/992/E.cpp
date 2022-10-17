#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

namespace cp {

template<typename T>
struct segment_tree {
  int n;
  int base;
  vector<T> tree;

  template<typename ForwardIterator>
  void create(ForwardIterator first, ForwardIterator last) {
    n = last - first;
    base = 1;
    while (base < n) base *= 2;
    tree.resize(2*base);
    REP(i,n) { tree[base + i] = T::single(*first++); }
    for (int i = base-1; i >= 1; --i) { fix(i); }
  }

  void fix(int x) {
    tree[x] = T::join(tree[2*x], tree[2*x+1]);
  }

  template<typename U>
  void update(int x, const U& val) {
    x += base;
    tree[x] = T::single(val);
    while (x > 1) { fix(x /= 2); }
  }

  T query(int xl, int xr) {

    assert(xl != xr);
    xl += base;
    xr += base-1;
    T tl = tree[xl];
    if (xl == xr) { return tl; }
    T tr = tree[xr];
    while (xl/2 != xr/2) {
      if (~xl&1) { tl = T::join(tl, tree[xl+1]); }
      if (xr&1) { tr = T::join(tree[xr-1], tr); }
      xl /= 2;
      xr /= 2;
    }
    return T::join(tl, tr);
  }

  template<typename Predicate>
  int longest_good_prefix(Predicate pred_good) {

    bool empty = true;
    if (pred_good(tree[1])) { return base; }
    T t;
    int x = 1;
    while (x < base) {
      T t2 = empty ? tree[2*x] : T::join(t, tree[2*x]);
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

  template<typename Predicate>
  int __longest_good_prefix(T t, int x, Predicate pred_good) {
    while (x < base) {
      T tj = T::join(t, tree[2*x]);
      if (pred_good(tj)) {
        t = tj;
        x = 2*x+1;
      } else {
        x = 2*x;
      }
    }
    return x - base;
  }

  template<typename Predicate>
  int longest_good_prefix(int xl, Predicate pred_good) {

    xl += base;
    T t = tree[xl];
    if (!pred_good(t)) { return xl - base; }
    while (xl > 1) {
      if (~xl&1) {
        T tj = T::join(t, tree[xl+1]);
        if (!pred_good(tj)) {
          return __longest_good_prefix(t, xl+1, pred_good);
        } else {
          t = tj;
        }
      }
      xl /= 2;
    }
    return base;
  }
};

}


const int infty = 1000000010;

struct info {
  int sum,max;
  info() : sum(0), max(0) { }
  info(int sum, int max) : sum(sum), max(max) { }

  static info single(int x) {
    return info(x, x);
  }

  static info join(const info& L, const info& R) {
    return info(min(L.sum + R.sum, infty), ::max(L.max, R.max));
  }
};

const int N = 210000;
int n,q,a[N];
cp::segment_tree<info> st;

int main() {
  scanf("%d%d",&n,&q);
  REP(i,n) scanf("%d",&a[i]);
  st.create(a, a+n);
  REP(i,q) {
    int x,av; scanf("%d%d",&x,&av);
    a[--x] = av;
    st.update(x, av);
    int ok = a[0] == 0 ? 0 : -1;
    int len = 1;
    while (ok == -1) {
      int sum = st.query(0, len).sum;
      int cand = st.longest_good_prefix(len,
          [sum](const info& I) { return I.max < sum; });
      if (cand >= n) break;
      int sum2 = st.query(0, cand).sum;
      if (sum2 == a[cand]) ok = cand;
      len = cand+1;
    }
    printf("%d\n", ok == -1 ? -1 : ok+1);
  }
}