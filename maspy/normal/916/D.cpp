#line 1 "/home/maspy/compro/library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define FOR4_R(i, a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) \
  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    if (check(x)) {
      ok = x;
    } else {
      ng = x;
    }
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi s_to_vi(const string &S, char first_char) {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename CNT, typename T>
vc<CNT> bincount(const vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(const vector<T> &A) {
  // stable
  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  int n = len(A);
  assert(len(I) == n);
  vc<T> B(n);
  FOR(i, n) B[i] = A[I[i]];
  return B;
}
#line 1 "/home/maspy/compro/library/other/io2.hpp"
#define INT(...) \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...) \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...) \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...) \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...) \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S> void read(pair<T, S> &p) { read(p.first), read(p.second); }
template <class T> void read(vector<T> &a) {for(auto &i : a) read(i);}
template <class T> void read(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
  read(head);
  IN(tail...);
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
  cout.flush();
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 1 "/home/maspy/compro/library/pds/segtree.hpp"
template <typename Monoid, int NODES>
struct Persistent_SegTree {
  using X = typename Monoid::value_type;

  struct Node {
    Node *l, *r;
    X x;
  };

  using np = Node *;

  const int n;
  Node *pool;
  int pid;

  Persistent_SegTree(int n) : n(n), pid(0) { pool = new Node[NODES]; }

  Node *new_node(const X x = Monoid::unit()) {
    pool[pid].l = pool[pid].r = nullptr;
    pool[pid].x = x;
    return &(pool[pid++]);
  }

  Node *new_node(const vc<X> &dat) {
    assert(len(dat) == n);
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      if (l == r) return nullptr;
      if (r == l + 1) return new_node(dat[l]);
      int m = (l + r) / 2;
      Node *l_root = dfs(dfs, l, m);
      Node *r_root = dfs(dfs, m, r);
      X x = Monoid::op(l_root->x, r_root->x);
      Node *root = new_node(x);
      root->l = l_root, root->r = r_root;
      return root;
    };
    return dfs(dfs, 0, len(dat));
  }

  X prod(Node *root, int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    X x = Monoid::unit();
    prod_rec(root, 0, n, l, r, x);
    return x;
  }

  Node *set(Node *root, int i, const X &x) {
    assert(0 <= i && i < n);
    return set_rec(root, 0, n, i, x);
  }

  vc<X> restore(Node *root) {
    vc<X> res;
    auto dfs = [&](auto &dfs, Node *c, int node_l, int node_r) -> void {
      if (node_r - node_l == 1) {
        res.eb(c->x);
        return;
      }
      int node_m = (node_l + node_r) / 2;
      prop(c);
      dfs(dfs, c->l, node_l, node_m);
      dfs(dfs, c->r, node_m, node_r);
    };
    dfs(dfs, root, 0, n);
    return res;
  }

  void reset() { pid = 0; }

private:
  Node *copy_node(Node *n) {
    if (!n) return nullptr;
    pool[pid].l = n->l;
    pool[pid].r = n->r;
    pool[pid].x = n->x;
    return &(pool[pid++]);
  }

  Node *set_rec(Node *c, int node_l, int node_r, int i, const X &x) {
    if (node_r == node_l + 1) { return new_node(x); }
    if(!c) c = new_node();
    int node_m = (node_l + node_r) / 2;
    c = copy_node(c);
    if (i < node_m) {
      c->l = set_rec(c->l, node_l, node_m, i, x);
    } else {
      c->r = set_rec(c->r, node_m, node_r, i, x);
    }
    X xl = (c->l ? c->l->x : Monoid::unit());
    X xr = (c->r ? c->r->x : Monoid::unit());
    c->x = Monoid::op(xl, xr);
    return c;
  }

  void prod_rec(Node *c, int node_l, int node_r, int l, int r, X &x) {
    if(!c) return;
    chmax(l, node_l);
    chmin(r, node_r);
    if (l >= r) return;
    if (l == node_l && r == node_r) {
      x = Monoid::op(x, c->x);
      return;
    }
    int node_m = (node_l + node_r) / 2;
    prod_rec(c->l, node_l, node_m, l, r, x);
    prod_rec(c->r, node_m, node_r, l, r, x);
  }
};
#line 2 "/home/maspy/compro/library/pds/array.hpp"

template <typename T, int shift = 4>
struct PersistentArray {
  struct node;
  using np = node*;
  struct node {
    T data;
    np ch[1 << shift] = {};
  };

  static constexpr int mask = (1 << shift) - 1;
  np root = nullptr;
  PersistentArray() {}
  np get_root() { return root; }
  T get(np t, int idx) {
    if (!t) return 0;
    if (idx == 0) {
      return t->data;
    } else {
      return get(t->ch[idx & mask], idx >> shift);
    }
  }

  void destructive_set(np& t, int idx, T val) {
    // 
    if (!t) t = new node();
    if (idx == 0)
      t->data = val;
    else {
      destructive_set(t->ch[idx & mask], idx >> shift, val);
    }
  }

  np set(const np& t, int idx, T val) {
    // set  root node pointer 
    np res = new node();
    if (t) {
      memcpy(res->ch, t->ch, sizeof(t->ch));
      res->data = t->data;
    }
    if (idx == 0) {
      res->data = val;
    } else {
      res->ch[idx & mask] = set(res->ch[idx & mask], idx >> shift, val);
    }
    return res;
  }
};
#line 2 "/home/maspy/compro/library/alg/group_add.hpp"

template <typename E>
struct Group_Add {
  using X = E;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }
  static constexpr X inverse(const X &x) noexcept { return -x; }
  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }
  static constexpr X unit() { return X(0); }
  static constexpr bool commute = true;
};
#line 6 "main.cpp"

void solve() {
  LL(Q);

  // string -> idx
  map<string, int> IDX;

  // string idx -> pri
  PersistentArray<int> A;
  using np1 = typename decltype(A)::np;
  vc<np1> A_root(Q + 1);
  A_root[0] = A.get_root();
  FOR(q, Q) A_root[0] = A.set(A_root[0], q, -1);

  ll LIM = 1'000'000'100;
  // pri -> count 
  Persistent_SegTree<Group_Add<int>, 10'000'000> seg(LIM);
  using np2 = typename decltype(seg)::np;
  vc<np2> seg_root(Q + 1);
  seg_root[0] = seg.new_node();

  FOR(q, Q) {
    auto& a_root = A_root[q + 1];
    auto& s_root = seg_root[q + 1];
    a_root = A_root[q];
    s_root = seg_root[q];

    STR(t);
    if (t == "query") {
      STR(S);
      if (!IDX.count(S)) {
        print(-1);
        continue;
      }
      int idx = IDX[S];
      ll pri = A.get(a_root, idx);
      if (pri == -1)
        print(-1);
      else {
        print(seg.prod(s_root, 0, pri));
      }
    }
    if (t == "remove") {
      STR(S);
      if (!IDX.count(S)) continue;
      int idx = IDX[S];
      int now = A.get(a_root, idx);
      a_root = A.set(a_root, idx, -1);
      if (now != -1) {
        ll cnt = seg.prod(seg_root[q], now, now + 1);
        s_root = seg.set(s_root, now, cnt - 1);
      }
    }
    if (t == "set") {
      STR(S);
      LL(to);
      if (!IDX.count(S)) {
        IDX[S] = len(IDX);
        a_root = A.set(a_root, IDX[S], -1);
      }
      int idx = IDX[S];
      int now = A.get(a_root, idx);
      assert(a_root);
      a_root = A.set(a_root, idx, to);
      if (now != -1) {
        ll cnt = seg.prod(s_root, now, now + 1);
        s_root = seg.set(s_root, now, cnt - 1);
      }
      assert(s_root);
      ll cnt = seg.prod(s_root, to, to + 1);
      s_root = seg.set(s_root, to, cnt + 1);
    }
    if (t == "undo") {
      LL(n);
      a_root = A_root[q - n];
      s_root = seg_root[q - n];
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}