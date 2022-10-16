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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int contents[150][150];

void Put(int r, int c, int val) {
  cout << val << " " << r << " " << c << endl;
  contents[r][c] = val;
}

int main() {
  int n;
  cin >> n;

  vector<pii> cells1, cells2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if ((i + j) % 2 == 0) {
        cells1.emplace_back(i, j);
      } else {
        cells2.emplace_back(i, j);
      }
    }
  }

  while (!cells1.empty() && !cells2.empty()) {
    int a;
    cin >> a;

    if (a != 1) {
      auto [r, c] = cells1.back();
      cells1.pop_back();
      Put(r, c, 1);
    } else {
      assert(a != 2);
      auto [r, c] = cells2.back();
      cells2.pop_back();
      Put(r, c, 2);
    }
  }

  auto rem_cells = cells1.empty() ? cells2 : cells1;

  while (!rem_cells.empty()) {
    int a;
    cin >> a;

    auto [r, c] = rem_cells.back();
    rem_cells.pop_back();
    vector<bool> forbidden(4);
    forbidden[0] = true;
    forbidden[a] = true;
    for (int dr = -1; dr <= 1; ++dr) {
      for (int dc = -1; dc <= 1; ++dc) {
        if (abs(dr) + abs(dc) == 1) {
          forbidden[contents[r + dr][c + dc]] = true;
        }
      }
    }

    assert(count(ALL(forbidden), false) >= 1);
    int item = 1;
    while (forbidden[item]) { ++item; }
    Put(r, c, item);
  }

}