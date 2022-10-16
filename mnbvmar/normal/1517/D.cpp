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

const int kInf = 1e9;
const int kMaxN = 700;

int n, m, k;
int horiz[kMaxN][kMaxN]; // (i,j)--(i,j+1)
int vert[kMaxN][kMaxN];  // (i,j)--(i+1,j)
int ans[11][kMaxN][kMaxN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      cin >> horiz[i][j];
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> vert[i][j];
    }
  }
  if (k % 2 == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << "-1 ";
      }
      cout << "\n";
    }
    return 0;
  }

  k /= 2;
  for (int x = 1; x <= k; ++x) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[x][i][j] = kInf;
        if (i > 0) {
          ans[x][i][j] = min(ans[x][i][j], ans[x-1][i-1][j] + 2 * vert[i-1][j]);
        }
        if (j > 0) {
          ans[x][i][j] = min(ans[x][i][j], ans[x-1][i][j-1] + 2 * horiz[i][j-1]);
        }
        if (i < n - 1) {
          ans[x][i][j] = min(ans[x][i][j], ans[x-1][i+1][j] + 2 * vert[i][j]);
        }
        if (j < m - 1) {
          ans[x][i][j] = min(ans[x][i][j], ans[x-1][i][j+1] + 2 * horiz[i][j]);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[k][i][j] << " ";
    }
    cout << "\n";
  }

}