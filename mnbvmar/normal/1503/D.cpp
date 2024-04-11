//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
  *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
#define int ll
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct SegTree {
  struct Node {
    ll min_val;
    ll add_val;

    Node() : min_val{0}, add_val{0} {}
  };

  vector<Node> nodes;
  int base;

  SegTree(int n) : base{1} {
    while (base < n + 2) { base *= 2; }
    nodes.resize(base * 2);
  }

  int lq, rq;
  ll valq;

  void Touch(int v) {
    if (v < base) {
      for (int s : {v * 2, v * 2 + 1}) {
        nodes[s].min_val += nodes[v].add_val;
        nodes[s].add_val += nodes[v].add_val;
      }
      nodes[v].add_val = 0;
    }
  }

  void AddValRec(int lb, int rb, int v) {
    if (lb >= rq || rb <= lq) { return; }
    if (lq <= lb && rb <= rq) {
      nodes[v].min_val += valq;
      nodes[v].add_val += valq;
      return;
    }
    Touch(v);
    const int mid = (lb + rb) / 2;
    AddValRec(lb, mid, v * 2);
    AddValRec(mid, rb, v * 2 + 1);
    nodes[v].min_val = min(nodes[v*2].min_val, nodes[v*2+1].min_val);
  }

  void AddVal(int L, int R, ll val) {
    lq = L; rq = R; valq = val;
    AddValRec(0, base, 1);
  }

  void MinWithVal(int loc, int val) {
    ll cur_val = GetMin(loc, loc + 1);
    if (val < cur_val) {
      AddVal(loc, loc + 1, val - cur_val);
    }
  }

  ll GetMinRec(int lb, int rb, int v) {
    if (lb >= rq || rb <= lq) { return 1e18; }
    if (lq <= lb && rb <= rq) { return nodes[v].min_val; }
    Touch(v);
    const int mid = (lb + rb) / 2;
    return min(GetMinRec(lb, mid, v * 2), GetMinRec(mid, rb, v * 2 + 1));
  }

  ll GetMin(int L, int R) {
    lq = L; rq = R;
    return GetMinRec(0, base, 1);
  }

  void Dbg() {
    for (int i = 0; i < base; ++i) {
      cerr << GetMin(i, i + 1) << " ";
    }
    cerr << "\n";
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int n;
  cin >> n;
  // if (n == 1) {
  //   cout << "0\n";
  //   return 0;
  // }
  
  vector<pii> cards(n);
  for (int i = 0; i < n; ++i) {
    cin >> cards[i].first >> cards[i].second;
  }
  
  // cards.emplace_back(0, 2 * n);
  sort(ALL(cards), [](const pii &lhs, const pii &rhs) {
    return lhs.first < rhs.first;
  });
  debug() << imie(cards);

  bool sorted = true;
  for (int i = 1; i < n; ++i) {
    if (abs(cards[i].nd) > abs(cards[i - 1].nd)) {
      sorted = false;
      break;
    }
  }
  if (sorted) {
    cout << "0\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (cards[i].first > cards[i].second) {
      swap(cards[i].first, cards[i].second);
      cards[i].second = -cards[i].second;
    }
  }
  sort(ALL(cards), [](const pii &lhs, const pii &rhs) {
    return lhs.first < rhs.first;
  });
  debug() << imie(cards);

  SegTree tree0(2 * n + 5), tree1(2 * n + 5);
  tree0.AddVal(0, 2 * n + 5, 1e9);
  tree1.AddVal(0, 2 * n + 5, 1e9);
  tree0.MinWithVal(2 * n + 1, 0);
  tree1.MinWithVal(2 * n + 1, 0);

  int last_b = 2 * n + 1;
  for (auto [a, tmpb] : cards) {
    const int b = abs(tmpb);
    const bool was_flipped = (tmpb < 0);

    const ll min0 = tree0.GetMin(b, 2 * n + 2);
    const ll min1 = tree1.GetMin(b, 2 * n + 2);
    debug() << imie(min0) << imie(min1);
    if (b < last_b) {
      (was_flipped ? tree0 : tree1).AddVal(0, 2 * n + 5, 1);
    } else {
      tree0.AddVal(0, 2 * n + 5, 1e9);
      tree1.AddVal(0, 2 * n + 5, 1e9);
    }
    tree1.MinWithVal(last_b, min0 + (!was_flipped));
    tree0.MinWithVal(last_b, min1 + was_flipped);
    last_b = b;

    #ifdef LOCAL
    tree0.Dbg();
    tree1.Dbg();
    #endif
  }

  auto Agree = [&](pii a, pii b) {
    return b.st < abs(a.nd) && abs(b.nd) > a.st;
  };

  ll ans = 1e9;
  for (int i = 0; i < n - 1; ++i) {
    if (Agree(cards[i], cards[n - 1])) {
      const int y = abs(cards[i].second);
      debug() << i << imie(y);
      ans = min(ans, tree0.GetMin(y, y + 1));
      ans = min(ans, tree1.GetMin(y, y + 1));
    }
  }

  if (ans > 1e6) { ans = -1; }
  // const ll ans = min(tree0.GetMin(0, 2 * n + 2), tree1.GetMin(0, 2 * n + 2));
  cout << ans << "\n";
}