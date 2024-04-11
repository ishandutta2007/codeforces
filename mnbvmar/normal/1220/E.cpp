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

const int kMaxN = 3e5 + 100;

ll score[kMaxN];
ll ins[kMaxN];
vi adj[kMaxN];
int deg[kMaxN];
int n, m, start;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> score[i];
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> start;
	
	queue<int> q;
	
	for (int i = 1; i <= n; ++i) {
		deg[i] = SZ(adj[i]);
		if (deg[i] == 1 && i != start) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int v = q.front(); q.pop();
		deg[v] = -1;
		for (int s : adj[v]) {
			if (deg[s] < 0) { continue; }
			--deg[s];
			ins[s] = max(ins[s], ins[v] + score[v]);
			if (deg[s] == 1 && s != start) {
				q.push(s);
			}
		}
	}
	
	ll totus = 0, totthem = 0;
	for (int i = 1; i <= n; ++i) {
		if (deg[i] < 0) { continue; }
		totus += score[i];
		totthem = max(totthem, ins[i]);
	}
	cout << totus + totthem << "\n";
}