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

#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//ld eps = 1e-9;

int n, m;

int a[100500];

vector<int> primes[200];

vector<int> ids[200];

pair<int, int> good[200];

vector<int> g[5000];

int mt[5000];

char used[5000];

bool dfs(int v) {
	if (used[v])
		return false;
	used[v] = true;
	for (int to : g[v]) {
		if (mt[to] == -1 || dfs(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int now = a[i];
		for (int j = 2; j * j <= now; ++j) {
			while (now % j == 0) {
				primes[i].push_back(j);
				now /= j;
			}
		}
		if (now > 1) {
			primes[i].push_back(now);
		}
	}

	int cnt[2];
	cnt[0] = cnt[1] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < primes[i].size(); ++j) {
			ids[i].push_back(cnt[i & 1]++);
		}
	}

	for (int i = 0; i < m; ++i) {
		cin >> good[i].first >> good[i].second;
		--good[i].first;
		--good[i].second;
		if (good[i].first % 2)
			swap(good[i].first, good[i].second);
	}
	
	for (int i = 0; i < m; ++i) {
		int cur1 = good[i].first, cur2 = good[i].second;
		for (int j = 0; j < primes[cur1].size(); ++j) {
			int p1 = primes[cur1][j];
			for (int k = 0; k < primes[cur2].size(); ++k) {
				int p2 = primes[cur2][k];
				if (p1 == p2) {
					g[ids[cur1][j]].push_back(ids[cur2][k]);
				}
			}
		}
	}

	memset(mt, -1, sizeof mt);
	
	int ans = 0;

	for (int i = 0; i < cnt[0]; ++i) {
		memset(used, false, sizeof used);
		if (dfs(i))
			++ans;
	}

	cout << ans << "\n";

}