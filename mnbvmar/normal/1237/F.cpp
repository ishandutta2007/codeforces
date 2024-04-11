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

const int mod = 998244353;
const int MAXN = 5000;

int binom[MAXN][MAXN];
int fact[MAXN];

void Preproc() {
	binom[0][0] = 1;
	for (int n = 1; n < MAXN; ++n) {
		binom[n][0] = 1;
		for (int k = 1; k <= n; ++k) {
			binom[n][k] = (binom[n-1][k-1] + binom[n-1][k]) % mod;
		}
	}
	
	fact[0] = 1;
	for (int n = 1; n < MAXN; ++n) {
		fact[n] = (ll)fact[n-1] * n % mod;
	}
}

int h, w, n;

int dp[2][2][MAXN];

void MakeDP(bool bad[MAXN], int ans[MAXN], int sz) {
	memset(dp, 0, sizeof(dp));
	dp[1][bad[0]][0] = 1;
	for (int i = 2; i <= sz; ++i) {
		int to = i % 2;
		int from = to ^ 1;
		memset(dp[to], 0, sizeof(dp[to]));
		
		if (bad[i-1]) {
			for (int j = 0; j <= h; ++j) {
				dp[to][1][j] = (dp[from][0][j]+dp[from][1][j]) % mod;
			}
		} else {
			for (int j = 0; j <= h; ++j) {
				dp[to][0][j] = (dp[from][0][j]+dp[from][1][j]) % mod;
				if (j) {
					dp[to][1][j] = dp[from][0][j-1];
				}
			}
		}
	}
	
	int where = sz % 2;
	for (int i = 0; i <= sz; ++i) {
		ans[i] = (dp[where][0][i] + dp[where][1][i]) % mod;
	}
}

bool bad_row[MAXN], bad_col[MAXN];

int cov_row[MAXN];
int cov_col[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	Preproc();
	cin >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --c1; --r2; --c2;
		bad_row[r1] = bad_row[r2] = true;
		bad_col[c1] = bad_col[c2] = true;
	}
	
	int remrow = 0, remcol = 0;
	for (int i = 0; i < h; ++i) { remrow += !bad_row[i]; }
	for (int i = 0; i < w; ++i) { remcol += !bad_col[i]; }
	
	MakeDP(bad_row, cov_row, h);
	MakeDP(bad_col, cov_col, w);
	
	int ans = 0;
	
	for (int hor = 0; hor * 2 <= remcol; ++hor) {
		for (int ver = 0; ver * 2 <= remrow; ++ver) {
			int opts_cols = binom[remcol - 2 * hor][ver];
			if (!opts_cols) { continue; }
			int opts_rows = binom[remrow - 2 * ver][hor];
			if (!opts_rows) { continue; }
			
			opts_cols = (ll)opts_cols * cov_col[hor] % mod;
			opts_rows = (ll)opts_rows * cov_row[ver] % mod;
			
			int coef = (ll)opts_cols * opts_rows % mod;
			coef = (ll)coef * fact[hor] % mod;
			coef = (ll)coef * fact[ver] % mod;
			ans = (ans + coef) % mod;
		}
	}
	
	cout << ans << "\n";
	
	//~ cov_row[1][bad_row[0]][0] = 1;
	//~ for (int i = 2; i <= h; ++i) {
		//~ int to = i % 2;
		//~ int from = to ^ 1;
		//~ memset(cov_row[to], 0, sizeof(cov_row[to]));
		
		//~ if (bad_row[i-1]) {
			//~ for (int j = 0; j <= h; ++j) {
				//~ cov_row[to][1][j] = (cov_row[from][0][j]+cov_row[from][1][j]) % mod;
			//~ }
		//~ } else {
			//~ for (int j = 0; j <= h; ++j) {
				//~ cov_row[to][0][j] = (cov_row[from][0][j]+cov_row[from][1][j]) % mod;
				//~ if (j) {
					//~ cov_row[to][1][j] = cov_row[from][0][j-1];
				//~ }
			//~ }
		//~ }
	//~ }
}