#pragma GCC optimize("Ofast")
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <random>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int & 
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;

const double PI = 2 * acos(0.0);

template<class T>
void show(const vector<T> &a) {
	for (T x : a)
		cout << x << " ";
	cout << endl;
}


const ll M = 998244353;
const ll MM = M * M * 4;
inline ll TMOD(ll a) {
    return a >= MM ? a - MM : a;
}
inline ll MOD(ll a) {
	if (a >= 0) return a >= M ? a % M : a;
	if (a <= -M) a %= M;
	return a ? a + M : a;
}

inline ll FMOD(ll a) {
    return a < M ? a : a - M;
}
inline ll RMOD(ll a) {
    return a < 0 ? a + M : a;
}

const int N = 5003;
const int K = 77;
const int T = 10;

vi g[2][N];
int n[2];
int k;
array<ll, K> dp[2][N];

template<class T>
void up(T &a, int n) {
	for (int i = n - 1; i >= 1; i--) {
		a[i] = a[i - 1];
	}
	a[0] = 0;
}

template<class T>
void do_shit(T &a, int n) {
	ll b[K] = {};
	ll sum[K] = {};
	for (int i = 0; i < n; ++i) {
	    b[i] = a[i];
	}
	for (int i = 0; i < n; ++i) {
	    sum[i] = a[i];
	}
	fori(iter, k + 2) {
	    ll new_a[K] = {};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				new_a[i] = TMOD(new_a[i] + a[j] * b[i - j]);
			}
		}
		for (int i = 0; i < n; ++i) {
		    a[i] = new_a[i] % M;
		}
		for (int i = 0; i < n; ++i) {
			sum[i] += a[i];
		}
	}
	for (int i = 0; i < n; ++i) {
	    a[i] = sum[i] % M;
	}
}

void dfs1(int z, int v, int par) {
    for (int i = 0; i < k + 1; ++i) {
	    dp[z][v][i] = 0;
    }
	for (int to : g[z][v]) if (to != par) {
		dfs1(z, to, v);
		auto cur = dp[z][to];
		up(cur, k + 1);
		//cout << "upped[" << to << "] = "; show(cur);
		fori(i, k + 1)
			dp[z][v][i] = FMOD(dp[z][v][i] + cur[i]);
	}
	do_shit(dp[z][v], k + 1);
	dp[z][v][0] = 1;
	//cout << "dp[" << z << "][" << v << "] = "; show(dp[z][v]);
}

void dfs2(int z, int v, int par, vl updp, vl &res) {
	up(updp, k + 1);
	vl sum = updp;
	for (int to : g[z][v]) if (to != par) {
		auto cur = dp[z][to];
		up(cur, k + 1);
		fori(i, k + 1)
			sum[i] = FMOD(sum[i] + cur[i]);
	}
	vl cur_res = sum;
	do_shit(cur_res, k + 1);
	cur_res[0] = 1;
	fori(i, k + 1)
		res[i] = FMOD(res[i] + cur_res[i]);
	for (int to : g[z][v]) if (to != par) {
		auto cur = dp[z][to];
		up(cur, k + 1);
		fori(i, k + 1)
			sum[i] = RMOD(sum[i] - cur[i]);
		cur_res = sum;
		do_shit(cur_res, k + 1);
		cur_res[0] = 1;
		dfs2(z, to, v, cur_res, res);
		fori(i, k + 1)
			sum[i] = FMOD(sum[i] + cur[i]);
	}
}

vl solve(int z) {
	dfs1(z, 1, -1);
	vl dummy(k + 1, 0);
	vl res(k + 1, 0);
	dfs2(z, 1, -1, dummy, res);
	return res;
}

ll c[K][K];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	c[0][0] = 1;
	for (int i = 1; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			c[i][j] = c[i - 1][j];
			if (j) c[i][j] = FMOD(c[i][j] + c[i - 1][j - 1]);
		}
	}

	cin >> n[0] >> n[1] >> k;
	if (k & 1) {
		cout << "0";
		return 0;
	}
	k >>= 1;

	for (int z : {0, 1})
		fori(iter, n[z] - 1) {
		int u, v;
		cin >> u >> v;
		g[z][u].pb(v);
		g[z][v].pb(u);
	}
	vl a = solve(0);
	vl b = solve(1);
	ll ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans = MOD(ans + MOD(a[i] * b[k - i]) * c[k << 1][i << 1]);
	}
	cout << ans << endl;
}