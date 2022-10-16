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

const int kMaxN = 6e5;

int fu_parent[kMaxN];
bool fu_single[kMaxN];

int FuFind(int v) {
	if (v == fu_parent[v]) { return v; }
	return fu_parent[v] = FuFind(fu_parent[v]);
}

bool FuUnion(int a, int b) {
	a = FuFind(a); b = FuFind(b);
	if (a == b) { return false; }
	if (fu_single[a] && fu_single[b]) { return false; }
	fu_parent[a] = b;
	fu_single[b] |= fu_single[a];
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(14);
	cerr << fixed << setprecision(6);

	int n, m;
	cin >> n >> m;
	iota(fu_parent, fu_parent + m + 1, 0);

	const int mod = 1000 * 1000 * 1000 + 7;
	vector<int> leq;
	int ans1 = 1, ans2 = 0;

	auto Add = [&](int row) {
		leq.push_back(row);
		ans1 = (ans1 * 2) % mod;
		++ans2;
	};

	for (int i = 1; i <= n; ++i) {
		int sz;
		cin >> sz;
		if (sz == 1) {
			int a;
			cin >> a;
			a = FuFind(a);
			if (!fu_single[a]) {
				fu_single[a] = true;
				Add(i);
			}
		} else {
			int a, b;
			cin >> a >> b;
			if (FuUnion(a, b)) {
				Add(i);
			}
		}
	}

	cout << ans1 << " " << ans2 << "\n";
	for (int x : leq) { cout << x << " "; }
	cout << "\n";
}