#pragma comment (linker, "/STACK:128000000")
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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
//void precalc();
clock_t start;
//int timer = 1;


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
    int t = 1;
	cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
    while (t--) {
		//cout << "Case #" << testNum++ << ": ";
        solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

struct my_map {
	int x[4];
	my_map() { memset(x, -1, sizeof x); }
	bool count(int v) {
		return x[v - 'A'] != -1;
	}
	int& operator [](int v) {
		return x[v - 'A'];
	}
};

struct state {
	int len, link;
	my_map next;
};

const int MAXLEN = 100000;
state st[MAXLEN*2];
int sz, last;

int dp[MAXLEN * 2][4];

void sa_init() {
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
	/*
	//   ,         :
	for (int i=0; i<MAXLEN*2; ++i)
		st[i].next.clear();
	*/
}

void sa_extend (char c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

bool used[2 * MAXLEN];

void dfs(int v) {
	if (used[v])
		return;
	used[v] = true;
	vector<int> haveNow(4, 0);
	for (int i = 0; i < 4; ++i) {
		if (!st[v].next.count(i + 'A'))
			continue;
		pair<char, int> it = mp('A' + i, st[v].next[i + 'A']);
		dfs(it.second);
		haveNow[it.first - 'A'] = 1;
		for (int i = 0; i < 4; ++i) {
			dp[v][i] = min(dp[v][i], 1 + dp[it.second][i]);
		}
	}
	for (char c = 'A'; c <= 'D'; ++c)
		if (!haveNow[c - 'A']) {
			dp[v][c - 'A'] = 1;
			for (int i = 0; i < 4; ++i)
				dp[v][i] = min(dp[v][i], 2);
		}
}

const li INF = 1000000000000000010;

vector<vector<li>> powers[70];

li mult(li q, li w) {
	if (q == 0)
		return 0;
	if (INF / q < w)
		return INF;
	li res = q * w;
	if (res > INF)
		res = INF;
	return res;
}

vector<vector<li>> mult (vector<vector<li>> q, vector<vector<li>> w) {
	vector<vector<li>> res(q.size(), vector<li>(q[0].size(), INF));
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				res[i][j] = min(res[i][j], q[i][k] + w[k][j]);
			}
			if (res[i][j] > INF)
				res[i][j] = INF;
		}
	return res;
}

li n;

bool good (vector<vector<li>> matrix, li step) {
	vector<vector<li>> res(4, vector<li>(4, 0));
	for (int i = 0; i < 70; ++i) {
		if (step & 1) {
			res = mult(res, powers[i]);
		}
		step >>= 1;
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			//cout << res[i][j] << ' ';
			if (res[i][j] < n)
				return false;
		}
		//cout << "\n";
	}
	return true;
}

void solve() {
	string t;

	cin >> n >> t;

	//n = 1000000000000000000LL;
	//t = string(25000, 'A') + string(25000, 'B') + string(25000, 'C') + string(25000, 'D');
	
	sa_init();
	for (int i = 0; i < t.length(); ++i)
		sa_extend(t[i]);

	vector<vector<li>> best(4, vector<li>(4));

	for (char c = 'A'; c <= 'D'; ++c) {
		for (int i = 0; i < sz; ++i)
			for (char z = 'A'; z <= 'D'; ++z)
				dp[i][z - 'A'] = 1000000000;

		memset(used, false, sizeof used);

		dfs(st[0].next[c]);
		
		for (char z = 'A'; z <= 'D'; ++z)
			best[z - 'A'][c - 'A'] = dp[st[0].next[c]][z - 'A'];
	}

	/*for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << best[i][j] << ' ';
		cout << "\n";
	}
	cout << "\n";*/

	powers[0] = best;
	for (int i = 1; i < 70; ++i) {
		powers[i] = mult(powers[i - 1], powers[i - 1]);

		/*if (i < 3) {
		for (int k = 0; k < 4; ++k) {
			for (int j = 0; j < 4; ++j)
				cout << powers[i][k][j] << ' ';
			cout << "\n";
		}
		cout << "\n";
		}*/

	}

	li l = 0, r = 1e18 + 5;

	while (l + 1 < r) {
		li m = (l + r) / 2;

		if (good(best, m))
			r = m;
		else
			l = m;

	}
	
	cout << r;


}