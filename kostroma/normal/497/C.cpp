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

int n;

enum {
	INSERT = 1, ERASE = 3, SEGMENT = 2
};

struct event {
	int r;
	int id;
	int type;
	event(int r, int id, int type) : r(r), id(id), type(type) {}
	bool operator < (const event& ot) const {
		return type < ot.type || type == ot.type && (r < ot.r || r == ot.r && id < ot.id);
	}
};

map<int, vector<event>> segments;

int have[100500];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		segments[a].push_back(event(b, i, SEGMENT));
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		have[i] = c;
		segments[a].push_back(event(b, i, INSERT));
		segments[b].push_back(event(b, i, ERASE));
	}

	set<pair<int, int>> segs;

	vector<int> ans(n);

	for (auto item : segments) {
		sort(all(item.second));
		for (event cur : item.second) {
			if (cur.type == INSERT) {
				segs.insert(mp(cur.r, cur.id));
			}

			if (cur.type == ERASE) {
				segs.erase(mp(cur.r, cur.id));
			}

			if (cur.type == SEGMENT) {
				auto it = segs.lower_bound(mp(cur.r, 0));
				if (it == segs.end()) {
					cout << "NO\n";
					return;
				}
				ans[cur.id] = it->second;
				--have[it->second];
				if (have[it->second] == 0) {
					segs.erase(it);
				}
			}
		}
	}


	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i] + 1 << ' ';
	}
	
}