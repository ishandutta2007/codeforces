#pragma comment(linker, "/STACK:1024000000")
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
#include <functional>
/*#ifndef room111
#include <sys/resource.h>
#endif*/
#include <unordered_set>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

bool stress = false;

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
	/*#ifndef room111
	const rlim_t kStackSize = 128L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
	if (rl.rlim_cur < kStackSize)
	{
	rl.rlim_cur = kStackSize;
	result = setrlimit(RLIMIT_STACK, &rl);
	if (result != 0)
	{
	fprintf(stderr, "setrlimit returned result = %d\n", result);
	}
	}
	}
	#endif*/

	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve(true);
		++testNumber;
		//++timer;
	}
#ifdef room1111
	while (true)
		solve(false);
#endif

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

#define int li

//const int mod = 1000000007;

const int INF = 2e18;

class Treap {
public:
	typedef struct _node {
		int key;
		int cnt;
		int prior;
		int val;
		int sum;
		_node* l;
		_node* r;
		_node(int key, int val) :key(key), val(val), l(nullptr), r(nullptr), cnt(1), sum(val) { prior = (rand() << 16) | rand(); }

		void push() {

		}

		void recalc() {
			sum = val;
			cnt = 1 + Cnt(l) + Cnt(r);
			if (l) {
				sum += l->sum;
				if (sum > INF) {
					sum = INF;
				}
			}
			if (r) {
				sum += r->sum;
				if (sum > INF) {
					sum = INF;
				}
			}
		}

		static int Cnt(_node* v) {
			if (!v)
				return 0;
			return v->cnt;
		}
	}*node;

	static int Cnt(node v) {
		if (!v)
			return 0;
		return v->cnt;
	}

	static int Sum(node v) {
		if (!v)
			return 0;
		return v->sum;
	}

	node root;

	size_t Size;

	node merge(node l, node r) {
		if (!l)
			return r;
		if (!r)
			return l;
		if (l->prior < r->prior) {
			l->push();
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else {
			r->push();
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	void split(node v, int key, node& l, node& r) {
		l = r = nullptr;
		if (!v)
			return;
		v->push();
		if (v->key < key) {
			l = v;
			split(l->r, key, l->r, r);
			l->recalc();
		}
		else {
			r = v;
			split(r->l, key, l, r->l);
			r->recalc();
		}
	}

public:
	Treap() {
		root = nullptr;
		Size = 0;
	}

	size_t size() const {
		return Size;
	}

	int get_count(int sum) {
		node v = root;
		int res = 0;
		while (v) {
			int lef = Sum(v->l);
			if (lef <= sum) {
				res += Cnt(v->l);
				sum -= lef;
				if (v->val <= sum) {
					sum -= v->val;
					++res;
					v = v->r;
				}
				else {
					break;
				}
			}
			else {
				v = v->l;
			}
		}
		return res;
	}

	void insert(int key, int val) { //insert at the idx - position
		node l = nullptr, r = nullptr;
		split(root, key, l, r);
		node cur_node = new _node(key, val);
		root = merge(merge(l, cur_node), r);
		++Size;
	}

	node operator [] (int key) {
		node l = nullptr, m = nullptr, r = nullptr;
		split(root, key, l, r);
		split(r, key + 1, m, r);
		if (m == nullptr) {
			throw runtime_error("IndexTreapOutOfBound");
		}
		root = merge(merge(l, m), r);
		return m;
	}
};

typedef Treap::node Node;

void solve(bool read) {
	int n;
	cin >> n;
	//n = 300000;
	--n;
	vector<pair<int, int>> a(n);
	int T, W;
	cin >> T >> W;
	/*T = rand() * 100 + rand();
	W = rand() * 10000 + rand();*/
	for (int i = 0; i < n; ++i) {
		/*a[i].first = rand() * 100 + rand();
		a[i].second = rand() * 10000 + rand();*/
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));
	reverse(all(a));

	int res = n;
	Treap tree;
	for (int i = 0; i < n; ++i) {
		int cur = a[i].second - a[i].first + 1;
		if (a[i].first > T) {
			tree.insert(cur, cur);
			continue;
		}
		if (i > 0 && a[i].first == a[i - 1].first) {
			tree.insert(cur, cur);
			continue;
		}
		int can_give = T - a[i].first;
		res = min(res, i - tree.get_count(can_give));
		tree.insert(cur, cur);
	}

	res = min(res, n - tree.get_count(T));

	cout << res + 1 << "\n";

}