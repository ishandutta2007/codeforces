#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

#if 0
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


struct info_t {
  int val;
  static info_t single(int v) { return info_t{ v }; }
  static info_t join(const info_t& L, const info_t& R) { return info_t{ L.val + R.val }; }
};
#endif

const int N = 310000;
int n,m,p[N],pinv[N],cnt[N];
vector<int> pos[N];
//cp::segment_tree<info_t> t;

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d",&p[i]); --p[i]; }
  REP(i,n) pinv[p[i]] = i;
//  t.create(cnt,cnt+n);

  multiset<int> ms;
  ms.insert(n);

  REP(i,m) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    a = pinv[a];
    b = pinv[b];
    if (a > b) swap(a,b);
    ms.insert(b);
//    t.update(b, ++cnt[b]);
    pos[a].push_back(b);
  }

  ll ans = 0;
  REP(i,n) {
//    int end = t.longest_good_prefix([](const info_t& I) { return I.val == 0; });
//    ans += min(end, n) - i;
    ans += *ms.begin() - i;
    for (int b : pos[i]) {
//      t.update(b, --cnt[b]);
      ms.erase(ms.find(b));
    }
  }
  printf("%lld\n",ans);
}