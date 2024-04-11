#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug & operator<<
#define eni(x) sim>typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim> struct rge { c b, e; };
sim> rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim> auto dud(c*x) -> decltype(cerr<<*x, 0);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor (pair<b,c> d) {
  ris<<"("<<d.first<<", "<<d.second<<")";
}
sim dor(rge<c> d) {
  *this<<"[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris <<" ]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const int MaxN = 3e5 + 100;

struct Tree {
  struct Node {
    int max_val;
    int push;
    Node() : max_val(0), push(0) {}
  };
  
  vector<Node> nodes;
  int base;
  
  Tree(int n) : base(1) {
    while (base < n + 2) { base *= 2; }
    nodes.resize(base * 2);
  }
  
  int lq, rq, valq;
  
  void Touch(int v) {
    if (v < base) {
      for (int s : {v*2, v*2+1}) {
        nodes[s].max_val += nodes[v].push;
        nodes[s].push += nodes[v].push;
      }
    }
    nodes[v].push = 0;
  }
  
  void AddIntvRec(int lbase, int rbase, int v) {
    if (lbase >= rq || rbase <= lq) { return; }
    Touch(v);
    if (lq <= lbase && rbase <= rq) {
      nodes[v].max_val += valq;
      nodes[v].push += valq;
      return;
    }
    
    const int mid = (lbase + rbase) / 2;
    AddIntvRec(lbase, mid, v * 2);
    AddIntvRec(mid, rbase, v * 2 + 1);
    nodes[v].max_val = max(nodes[v*2].max_val, nodes[v*2+1].max_val);
  }
  
  void AddIntv(int L, int R, int val) {
    lq = L; rq = R; valq = val; AddIntvRec(0, base, 1);
  }
  
  int GetMax() {
    return nodes[1].max_val;
  }
};

struct Action {
  int t, y1, y2, delta;
  bool operator<(const Action &a) {
    if (t == a.t) {
      return delta > a.delta;
    }
    return t < a.t;
  }
};

int n, r;
pii pts[MaxN];

int main() {
  scanf("%d%d", &n, &r);
  
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    pts[i] = pii{x + y, y - x};
  }
  
  vector<Action> actions;
  for (int i = 0; i < n; ++i) {
    const int x = pts[i].first;
    const int y = pts[i].second;
    debug() << imie(x) << imie(y);
    actions.push_back(Action{x, y - r, y + r, 1});
    actions.push_back(Action{x + 2 * r, y - r, y + r, -1});
  }
  
  sort(actions.begin(), actions.end());
  
  const int M = 1e6 + 100;
  
  Tree tree(4 * M);
  int ans = 0;
  for (auto &a : actions) {
    ans = max(ans, tree.GetMax());
    
    debug() << imie(a.t) << imie(a.y1) << imie(a.y2) << imie(a.delta);
    tree.AddIntv(a.y1 + M, a.y2 + M + 1, a.delta);
  }
  
  printf("%d\n", ans);
}