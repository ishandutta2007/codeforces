#pragma comment(linker, "/STACK:512000000")
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
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
//#include <unordered_map>
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
		//cerr << testNum << endl;
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
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
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

//#define int li

//const int mod = 1000000007;

bool is_prime(int cur) {
	for (int i = 2; i * i <= cur; ++i) {
		if (cur % i == 0) {
			return false;
		}
	}
	return true;
}

vector<int> primes;

vector<vector<int>> g;

vector<int> tin, tout;
vector<int> order;
int TIM = 0;

void dfs(int v, int p) {
	tin[v] = TIM++;
	order.push_back(v);
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v);
	}
	tout[v] = TIM;
}

typedef bitset<1024> Bitset;

int mod;

struct Node {
	Bitset cur_set;
	int pushed_val;
	Node(): pushed_val(0) {
	}
	Node(int val) {
		cur_set[val] = 1;
		pushed_val = 0;
	}
};

const int shift = 1 << 17;
vector<Node> tree(2 * shift);
Bitset ideal;

Bitset normalize(const Bitset& cur, int shift) {
	Bitset res = ((cur << shift) | (cur >> (mod - shift)));
	res &= ideal;
	return res;
}

void push(int v) {
	for (int h = 0; h < 2; ++h) {
		tree[2 * v + h].pushed_val = (tree[2 * v + h].pushed_val + tree[v].pushed_val) % mod;
		tree[2 * v + h].cur_set = normalize(tree[2 * v + h].cur_set, tree[v].pushed_val);
	}
	tree[v].pushed_val = 0;
}

Node merge(const Node& l, const Node& r) {
	Node res;
	res.cur_set = l.cur_set | r.cur_set;
	return res;
}

Node rmq(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l) {
		return Node();
	}
	if (l <= tl && tr <= r) {
		return tree[v];
	}
	push(v);
	int tm = (tl + tr) / 2;
	Node res = merge(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	return res;
}

Bitset get_set(int l, int r) {
	Node res = rmq(1, 0, shift, l, r);
	return normalize(res.cur_set, res.pushed_val);
}

void modify(int v, int tl, int tr, int l, int r, int val) {
	if (r <= tl || tr <= l) {
		return;
	}
	if (l <= tl && tr <= r) {
		tree[v].pushed_val = (tree[v].pushed_val + val) % mod;
		tree[v].cur_set = normalize(tree[v].cur_set, val);
		return;
	}
	push(v);
	int tm = (tl + tr) / 2;
	modify(2 * v, tl, tm, l, r, val);
	modify(2 * v + 1, tm, tr, l, r, val);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void update_shift(int l, int r, int val) {
	return modify(1, 0, shift, l, r, val);
}

void build(int v, int tl, int tr, const vector<int>& a, const vector<int>& order) {
	if (tl + 1 == tr) {
		if (tl < a.size()) {
			tree[v] = Node(a[order[tl]]);
		}
		else {
			tree[v] = Node();
		}
		return;
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm, a, order);
	build(2 * v + 1, tm, tr, a, order);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void solve() {
	int n;
	cin >> n >> mod;
	for (int cur = 2; cur < mod; ++cur) {
		if (is_prime(cur)) { 
			primes.push_back(cur);
		}
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] %= mod;
	}
	for (int i = 0; i < mod; ++i) {
		ideal[i] = 1;
	}
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tin.resize(n);
	tout.resize(n);
	dfs(0, 0);

	build(1, 0, shift, a, order);

	int Q;
	cin >> Q;
	while (Q--) {
		int type, v;
		cin >> type >> v;
		--v;
		if (type == 2) {
			int ans = 0;
			Bitset res = get_set(tin[v], tout[v]);
			for (int p : primes) {
				if (res[p]) {
					++ans;
				}
			}
			cout << ans << '\n';
		}
		else {
			int x;
			cin >> x;
			x %= mod;
			update_shift(tin[v], tout[v], x);
		}
	}
}