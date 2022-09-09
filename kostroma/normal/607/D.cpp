#pragma comment (linker, "/STACK:128000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <complex>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		++testNumber;
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

/*const int C = 7000500;

int least_prime[C];*/


void precalc() {

	/*for (int i = 2; i < C; ++i) {
		if (!least_prime[i]) {
			least_prime[i] = i;
			for (li j = i * 1LL * i; j < C; j += i) {
				least_prime[j] = i;
			}
		}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*catalan[0] = 1;
	for (int n = 0; n < 200500 - 1; ++n) {
	catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD * binpow(n + 2, MOD - 2, MOD) % MOD;
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/

	/*for (int i = 0; i < 100; ++i) {
	doubleC[i][i] = doubleC[i][0] = 1.0;
	for (int j = 1; j < i; ++j) {
	doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
	}
	}*/

}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}


#define int li

const int mod = 1000000007;

enum Type {
	ADD = 0,
	QUERY = 1
};

struct Event {
	Type type;
	int v;
	int p;
	int val;
	void scan() {
		int t;
		cin >> t;
		if (t == 1) {
			type = ADD;
			cin >> p >> val;
			--p;
		}
		else {
			type = QUERY;
			cin >> v;
			--v;
		}
	}
};

struct SegTree {
	int shift = 1 << 19;
	vector<int> tree;
	vector<int> add;
	SegTree() {
		tree.assign(2 * shift + 6, 0);
		add.assign(2 * shift + 6, 1);
	}

	void push(int v) {
		for (int h = 0; h < 2; ++h) {
			add[2 * v + h] *= add[v];
			add[2 * v + h] %= mod;
		}
		add[v] = 1;
	}

	void update(int v, int tl, int tr, int l, int r, int val) {
		if (r <= tl || tr <= l) {
			return;
		}
		if (l <= tl && tr <= r) {
			add[v] *= val;
			add[v] %= mod;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, l, r, val);
		update(2 * v + 1, tm, tr, l, r, val);
		tree[v] = (tree[2 * v] * add[2 * v] + tree[2 * v + 1] * add[2 * v + 1]) % mod;
	}

	void modify(int l, int r, int val) {
		update(1, 0, shift, l, r, val);
	}

	int rsq(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l) {
			return 0;
		}
		if (l <= tl && tr <= r) {
			return tree[v] * add[v] % mod;
		}
		push(v);
		int tm = (tl + tr) / 2;
		int res = (rsq(2 * v, tl, tm, l, r) + rsq(2 * v + 1, tm, tr, l, r)) % mod;
		tree[v] = (tree[2 * v] * add[2 * v] + tree[2 * v + 1] * add[2 * v + 1]) % mod;
		return res;
	}

	int get_sum(int l, int r) {
		return rsq(1, 0, shift, l, r);
	}

	void put_value(int v, int tl, int tr, int need, int val) {
		if (tr <= need || need < tl) {
			return;
		}
		if (tl + 1 == tr) {
			tree[v] = val;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		put_value(2 * v, tl, tm, need, val);
		put_value(2 * v + 1, tm, tr, need, val);
		tree[v] = (tree[2 * v] * add[2 * v] + tree[2 * v + 1] * add[2 * v + 1]) % mod;
	}

	void put(int v, int val) {
		put_value(1, 0, shift, v, val);
	}

};

vector<vector<int>> g;

vector<int> tin, tout;

int tim = 0;

vector<int> order;

void dfs(int v) {
	tin[v] = tim++;
	order.push_back(v);
	for (int to : g[v]) {
		dfs(to);
	}
	order.push_back(v);
	tout[v] = tim++;
}

void solve() {
	int v0;
	cin >> v0;
	int Q;
	cin >> Q;
	int n = 1;
	vector<Event> events(Q);

	vector<int> vals, rev_vals;
	vals.push_back(v0);

	for (int i = 0; i < Q; ++i) {
		events[i].scan();
		if (events[i].type == ADD) {
			events[i].v = n;
			vals.push_back(events[i].val);
			++n;
		}
	}

	rev_vals.resize(n);

	for (int i = 0; i < n; ++i) {
		rev_vals[i] = binpow(vals[i], mod - 2, mod);
	}

	vector<int> parents(n, -1);
	g.resize(n);
	for (int i = 0; i < Q; ++i) {
		if (events[i].type == ADD) {
			g[events[i].p].push_back(events[i].v);
			parents[events[i].v] = events[i].p;
		}
	}

	vector<int> children(n, 0);

	tin.resize(n);
	tout.resize(n);
	dfs(0);

	vector<pair<int, int>> segs(n);
	for (int i = 0; i < n; ++i) {
		segs[i] = mp(tin[i], tout[i]);	
	}

	
	SegTree tree;
	tree.put(tin[0], vals[0]);

	for (int i = 0; i < Q; ++i) {
		if (events[i].type == QUERY) {
			int cur_v = events[i].v;
			int res = tree.get_sum(segs[cur_v].first, segs[cur_v].second);
			if (parents[cur_v] != -1) {
				int par = parents[cur_v];
				int up_product = tree.get_sum(tin[par], tin[par] + 1);
				res = res * binpow(up_product, mod - 2, mod) % mod *
					vals[par] % mod;
			}
			res %= mod;
			cout << res << "\n";
		}
		else {
			int cur_v = events[i].v;
			int par = events[i].p;
			int add_val = (children[par] + 2) * binpow(children[par] + 1, mod - 2, mod) % mod;
			tree.put(tin[cur_v], vals[cur_v]);
			tree.modify(segs[par].first, segs[par].second, add_val);
			++children[par];
		}
	}

}