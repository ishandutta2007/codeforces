//#pragma comment (linker, "/STACK:128000000")
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
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

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
	cin.tie(0);
	precalc();
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

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int mod = 1000000007;

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int n, m;

int a[100500];

struct segment {
	int l, r;
	ld p;
	int id;
	void scan() {
		cin >> l >> r >> p;
		--l;
		--r;
	}
};

bool cmp1(const segment& q, const segment& w) {
	return q.r > w.r || q.r == w.r && q.id < w.id;
}

bool cmp2(const segment& q, const segment& w) {
	return q.l > w.l || q.l == w.l && q.id > w.id;
}

segment segs[5050];

vector<segment> add[100500], erase[100500];

vector<int> g[5050];

int number[5050];

int maxTree[5050];

void dfs1(int v) {
	maxTree[v] = number[v];
	for (int to : g[v]) {
		dfs1(to);
		maxTree[v] = max(maxTree[v], maxTree[to]);
	}
}

ld dp[5050][5050];

const int C = 5001;

void dfs2(int v) {
	for (int to : g[v]) {
		dfs2(to);
	}
	for (int i = 0; i < C; ++i) {
		ld pr = 1.0;
		int bound = maxTree[v] + i;
		for (int to : g[v]) {
			int cur = maxTree[to];
			if (bound - cur < C)
				pr *= dp[to][bound - cur];
		}
		dp[v][i] += pr * (1.0 - segs[v].p);
		if (i + 1 < C) {
			dp[v][i + 1] += pr * segs[v].p;
		}
	}
	//cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	segs[0] = {0, n, 0.0};
	segs[0].id = 0;

	for (int i = 0; i < m; ++i) {
		segs[i + 1].scan();
		segs[i + 1].id = i + 1;
	}

	++m;

	for (int i = 0; i < m; ++i) {
		add[segs[i].l].push_back(segs[i]);
		erase[segs[i].r].push_back(segs[i]);
	}

	for (int i = 0; i < n; ++i) {
		sort(all(add[i]), cmp1);
		sort(all(erase[i]), cmp2);
	}

	stack<int> st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < add[i].size(); ++j) {
			segment item = add[i][j];
			st.push(item.id);
			//cerr << "ins " << item.id << "\n";
		}

		number[st.top()] = max(number[st.top()], a[i]);

		for (int j = 0; j < erase[i].size(); ++j) {
			segment item = erase[i][j];
			int cur = st.top();

			//cerr << "era " << item.id << endl;

			assert(cur == item.id);
			st.pop();
			if (!st.empty()) {
				g[st.top()].push_back(cur);
			}
		}

	}


	dfs1(0);

	dfs2(0);

	ld ans = dp[0][0] * maxTree[0];
	for (int i = 1; i < C; ++i) {
		ld p = dp[0][i] - dp[0][i - 1];
		ans += p * (maxTree[0] + i);
	}

	cout << ans << "\n";

}