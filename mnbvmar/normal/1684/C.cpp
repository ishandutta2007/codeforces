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
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

void Test() {
	int n, m;
	cin >> n >> m;

	vector<vi> tab(n, vi(m));
	vector<int> num_bad(n);
	for (auto &row : tab) {
		for (int &x : row) { cin >> x; }
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			num_bad[i] += (tab[i][j] > tab[i][j + 1]);
		}
	}

	vi to_check;
	for (const auto &row : tab) {
		if (is_sorted(ALL(row))) { continue; }
		int ptr = 0;
		while (row[ptr] <= row[ptr + 1]) { ++ptr; }
		to_check = {ptr, ptr + 1};
		break;
	}


	if (to_check.empty()) {
		to_check.push_back(0);
	}

	auto PutVal = [&](int r, int c, int val) {
		if (c) { num_bad[r] -= (tab[r][c - 1] > tab[r][c]); }
		if (c < m - 1) { num_bad[r] -= (tab[r][c] > tab[r][c + 1]); }
		tab[r][c] = val;
		if (c) { num_bad[r] += (tab[r][c - 1] > tab[r][c]); }
		if (c < m - 1) { num_bad[r] += (tab[r][c] > tab[r][c + 1]); }
	};

	auto IsOK = [&](int c1, int c2) {
		bool ok = true;
		for (int r = 0; r < n; ++r) {
			int last_bad = num_bad[r];
			const int v1 = tab[r][c1];
			const int v2 = tab[r][c2];
			PutVal(r, c1, v2);
			PutVal(r, c2, v1);
			ok &= (num_bad[r] == 0);
			PutVal(r, c1, v1);
			PutVal(r, c2, v2);
			assert(last_bad == num_bad[r]);
		}
		return ok;
	};

	for (int c1 : to_check) {
		for (int c2 = 0; c2 < m; ++c2) {
			if (IsOK(c1, c2)) {
				cout << c1 + 1 << " " << c2 + 1 << "\n";
				return;
			}
		}
	}

	cout << "-1\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	int t;
	cin >> t;
	while (t--) {
		Test();
	}
}