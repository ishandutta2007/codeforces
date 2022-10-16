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

using Bits = bitset<1024>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "NONE\n";
		return 0;
	}
	vector<string> in(n);
	for (string &row : in) { cin >> row; }

	vector<Bits> eqs;

	vector<Bits> xrow(n);
	vector<Bits> this_row(n);
	for (int i = 0; i < n; ++i) {
		this_row[i][i / 2] = 1;
	}
	const int vars = n / 2;

	vector<int> values(vars, -1);

	vector<vi> which_var(n, vi(n, -1));
	vector<vi> which_flip(n, vi(n, -1));

	for (int r = 0; r < n; ++r) {
		if (r) {
			vector<Bits> prev_row(n);
			swap(this_row, prev_row);
			if (r == 1) {
				this_row[0] = prev_row[1];
				this_row[n - 1] = prev_row[n - 2];
				for (int c = 1; c < n - 1; ++c) {
					this_row[c] = prev_row[c - 1] ^ prev_row[c] ^ prev_row[c + 1];
					this_row[c][vars] = !this_row[c][vars];
				}
			} else {
				this_row[0] = prev_row[0] ^ prev_row[1] ^ xrow[0];
				this_row[0][vars] = !this_row[0][vars];
				this_row[n - 1] = prev_row[n - 1] ^ prev_row[n - 2] ^ xrow[n - 1];
				this_row[n - 1][vars] = !this_row[n - 1][vars];
				for (int c = 1; c < n - 1; ++c) {
					this_row[c] = prev_row[c - 1] ^ prev_row[c + 1] ^ xrow[c];
				}
			}
			xrow = prev_row;
		}

		for (int c = 0; c < n; ++c) {
			const int f = this_row[c][vars];
			const int x = this_row[c]._Find_first();
			which_flip[r][c] = f;
			which_var[r][c] = x;
			if (in[r][c] != '.') {
				const int rf = f ^ (in[r][c] == 'S');
				if (values[x] != -1 && values[x] != rf) {
					cout << "NONE\n";
					return 0;
				}
				values[x] = rf;
			}
		}
	}

	if (count(ALL(values), -1)) {
		cout << "MULTIPLE\n";
		return 0;
	}

	cout << "UNIQUE\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			const int val = values[which_var[i][j]] ^ which_flip[i][j];
			cout << (val == 1 ? "S" : "G");
		}
		cout << "\n";
	}
	
}