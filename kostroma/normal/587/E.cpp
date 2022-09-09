#pragma comment (linker, "/STACK:1280000000")
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

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
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

//const int C = 500500;

//int least_prime[C];

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


int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

//const int mod = 1000000007;

struct Node {
	vector<int> basis;
	vector<int> min_bits;
	vector<int> adds;
	int push_xor;
	Node() {
		push_xor = 0;
	}
	Node(int cur) {
		push_xor = 0;
		basis.clear();
		adds = vector<int>(1, cur);
	}
};


const int shift = 1 << 18;

Node tree[2 * shift + 6];

void push(int v) {
	for (int h = 0; h < 2; ++h) {
		tree[2 * v + h].push_xor ^= tree[v].push_xor;
	}
	tree[v].push_xor = 0;
}

const int L = 30;

pair<int, int> eliminate(int new_row, const vector<int>& rows, const vector<int>& min_bits) {
	for (int i = 0; i < rows.size(); ++i) {
		if (new_row & (1 << min_bits[i])) {
			new_row ^= rows[i];
		}
	}
	int min_bit = -1;
	for (int i = 0; i < L; ++i) {
		if (new_row & (1 << i)) {
			min_bit = i;
			break;
		}
	}
	return mp(new_row, min_bit);
}

Node merge(const Node& q, const Node& w) {
	Node res;
	vector<int> new_adds;
	vector<int> fromQ, fromW;
	for (int item : q.adds) {
		item ^= q.push_xor;
		new_adds.push_back(item);
		fromQ.push_back(item);
	}
	for (int item : w.adds) {
		item ^= w.push_xor;
		new_adds.push_back(item);
		fromW.push_back(item);
	}
	sort(all(new_adds));
	new_adds.erase(unique(all(new_adds)), new_adds.end());
	if (new_adds.size() > 2) {
		new_adds.resize(2);
	}
	res.adds = new_adds;

	res.basis = q.basis;
	res.min_bits = q.min_bits;
	for (int item : w.basis) {
		pair<int, int> add = eliminate(item, res.basis, res.min_bits);
		if (add.first) {
			res.basis.push_back(add.first);
			res.min_bits.push_back(add.second);
		}
	}
	for (int firstGood : fromQ) {
		for (int secondGood : fromW) {
			int new_row = firstGood ^ secondGood;
			if (new_row) {
				pair<int, int> add = eliminate(new_row, res.basis, res.min_bits);
				if (add.first) {
					res.basis.push_back(add.first);
					res.min_bits.push_back(add.second);
				}
			}
		}
	}

	return res;
}


void build(int v, int tl, int tr, const vector<int>& a) {
	if (tl + 1 == tr) {
		tree[v] = Node(a[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	build(2 * v, tl, tm, a);
	build(2 * v + 1, tm, tr, a);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

void make_xor(int v, int tl, int tr, int l, int r, int k) {
	if (r <= tl || tr <= l) {
		return;
	}
	if (l <= tl && tr <= r) {
		tree[v].push_xor ^= k;
		return;
	}
	int tm = (tl + tr) / 2;
	push(v);
	make_xor(2 * v, tl, tm, l, r, k);
	make_xor(2 * v + 1, tm, tr, l, r, k);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
}

Node get_node(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l) {
		return Node();
	}
	if (l <= tl && tr <= r) {
		return tree[v];
	}
	int tm = (tl + tr) / 2;
	push(v);
	Node res = merge(get_node(2 * v, tl, tm, l, r), get_node(2 * v + 1, tm, tr, l, r));
	tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	return res;
}


li get_rank(const Node& res) {
	int rk = res.basis.size();
	for (int item : res.adds) {
		item ^= res.push_xor;
		if (item && eliminate(item, res.basis, res.min_bits).first) {
			++rk;
			break;
		}
	}
	li ans = 1;
	for (int i = 0; i < rk; ++i) {
		ans = ans * 2;
	}
	return ans;
}

void solve() {
	int n, Q;
	cin >> n >> Q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	build(1, 0, n, a);

	while (Q--) {
		int type;
		cin >> type;
		int l, r;
		cin >> l >> r;
		--l;
		if (type == 1) {
			int k;
			cin >> k;
			make_xor(1, 0, n, l, r, k);
		}
		else {
			Node res = get_node(1, 0, n, l, r);
			cout << get_rank(res) << "\n";
		}
	}
}