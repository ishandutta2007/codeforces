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
 
using ll=long long;
#define int ll
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct Matching {
  vector<vi> adj;
  vector<bool> vis;
  vi match_left, match_right;
  int n;

  Matching(int L, int R) {
    adj.resize(L);
    match_left.resize(L, -1);
    match_right.resize(R, -1);
    vis.resize(L);
    n = L;
  }

  void Add(int L, int R) {
    adj[L].push_back(R);
  }

  bool Dfs(int v) {
    if (vis[v]) { return false; }
    vis[v] = true;
    for (int s : adj[v]) {
      if (match_right[s] == -1 || Dfs(match_right[s])) {
        match_left[v] = s;
        match_right[s] = v;
        return true;
      }
    }
    return false;
  }

  int Match() {
	srand(time(NULL));
    for (auto &row : adj) { random_shuffle(ALL(row)); }
    int sz = 0;
    bool changed;
    do {
      changed = false;
      fill(ALL(vis), false);
      for (int i = 0; i < n; ++i) {
        if (match_left[i] == -1 && !vis[i] && Dfs(i)) {
          changed = true;
          ++sz;
        }
      }
    } while (changed);
    return sz;
  }
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	int n, m;
	cin >> n >> m;

	vi large_nums, small_nums;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (2 * x > m) {
			cout << "-1\n";
			return 0;
		}
		if (3 * x > m) {
			large_nums.push_back(x);
		} else {
			small_nums.push_back(x);
		}
	}

	const int L = SZ(large_nums);
	const int R = SZ(small_nums);
	Matching match(L, R);
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < R; ++j) {
			const int num_i = large_nums[i];
			const int num_j = small_nums[j];
			if (num_i * 2 + num_j <= m && num_i % num_j == 0) {
				match.Add(i, j);
			}
		}
	}

	const int sz = match.Match();
	if (sz < L) {
		cout << "-1\n";
		return 0;
	}


	vector<pii> nums;
	for (int i = 0; i < L; ++i) {
		int x = large_nums[i];
		int y = small_nums[match.match_left[i]];
		nums.emplace_back(2 * x + y, x + y);
	}

	for (int i = 0; i < R; ++i) {
		if (match.match_right[i] == -1) {
			const int y = small_nums[i];
			nums.emplace_back(3 * y, 2 * y);
		}
	}

	cout << SZ(nums) << "\n";
	for (auto [x, y] : nums) {
		cout << x << " " << y << "\n";
	}
}