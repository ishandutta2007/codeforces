//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
	//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int n, m, t;
char board[1024][1024];
ll first_flip[1024][1024];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m >> t;
	const ll kInf = 3e18;
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
		for (int j = 0; j < m; ++j) {
			first_flip[i][j] = kInf;
		}
	}

	queue<pii> q;

	auto Put = [&](int r, int c, int dist) {
		if (first_flip[r][c] == kInf) {
			first_flip[r][c] = dist;
			q.emplace(r, c);
		}
	};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int d = 0; d < 4; ++d) {
				int ni = i + dr[d];
				int nj = j + dc[d];
				if (ni < 0 || nj < 0 || ni >= n || nj >= m) { continue; }
				if (board[i][j] == board[ni][nj]) {
					Put(i, j, 0);
					Put(ni, nj, 0);
				}
			}
		}
	}

	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();

		for (int d = 0; d < 4; ++d) {
			int ni = r + dr[d];
			int nj = c + dc[d];
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) { continue; }
			Put(ni, nj, first_flip[r][c] + 1);
		}
	}

	for (int tid = 0; tid < t; ++tid) {
		int r, c;
		ll tm;
		cin >> r >> c >> tm;
		--r; --c;

		debug() << imie(r) << imie(c) << imie(tm) << imie(first_flip[r][c]);

		if (tm < first_flip[r][c]) {
			cout << board[r][c] << "\n";
		} else {
			char ans = board[r][c];
			if ((tm - first_flip[r][c]) % 2 == 1) {
				ans ^= 1;
			}
			cout << ans << "\n";
		}
	}
}