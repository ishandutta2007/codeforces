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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

vector<vector<int>> g;
vector<int> used;
vector<int> haveOne;

void dfs(int v, int num, int turn) {
	if (used[v] != -1) {
		if ((turn ^ used[v]) & 1) {
			cout << "IMPOSSIBLE\n";
			exit(0);
		}
		return;
	}
	used[v] = 2 * num + turn;
	for (int to : g[v]) {
		dfs(to, num, turn ^ 1);
	}
}

enum {
	CHANGE = 0, ASK = 1
};

struct Event {
	int x;
	int type;
	int compId;
	Event(int x, int type, int compId) :x(x), type(type), compId(compId) {}
	bool operator < (const Event& other) const {
		if (x != other.x)
			return x < other.x;
		return type < other.type;
	}
};

void solve() {
	int minT, maxT;
	cin >> minT >> maxT;
	int n, m;
	cin >> n >> m;
	g.resize(n);
	vector<pair<int, int>> need(n);
	for (int i = 0; i < n; ++i) {
		cin >> need[i].first >> need[i].second;
	}
	
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int comps = 0;
	used.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (used[i] == -1) {
			dfs(i, comps++, 0);
		}
	}

	comps *= 2;

	haveOne.assign(comps, 0);
	for (int i = 0; i < n; ++i) {
		haveOne[used[i]] = 1;
	}

	vector<pair<int, int>> segs(comps, mp(0, 1e9 + 5));
	for (int i = 0; i < n; ++i) {
		segs[used[i]].first = max(segs[used[i]].first, need[i].first);
		segs[used[i]].second = min(segs[used[i]].second, need[i].second);
	}

	for (int i = 0; i < comps; ++i) {
		if (segs[i].first > segs[i].second) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	int maxCoor = 1e9 + 5;

	int relevantComps = 0;
	vector<Event> events;
	for (int i = 0; i < comps; ++i) {
		if (!haveOne[i]) {
			continue;
		}
		++relevantComps;
		maxCoor = min(maxCoor, segs[i].second);

		events.push_back(Event(segs[i].first, ASK, i));
		events.push_back(Event(segs[i].second, ASK, i));
		events.push_back(Event(max(maxT - segs[i].first, 0), ASK, i));
		events.push_back(Event(max(0, minT - segs[i].first), ASK, i));
		events.push_back(Event(max(0, maxT - segs[i].second), ASK, i));
		events.push_back(Event(max(0, minT - segs[i].second), ASK, i));
	}

	for (int i = 0; i < comps; i += 2) {
		if (!haveOne[i]) {
			events.push_back(Event(segs[i + 1].first, CHANGE, i + 1));
			continue;
		}
		if (!haveOne[i + 1]) {
			events.push_back(Event(segs[i].first, CHANGE, i));
			continue;
		}
		if (segs[i] <= segs[i + 1]) {
			events.push_back(Event(segs[i].first, CHANGE, i));
			if (segs[i].first < segs[i + 1].first && segs[i].second > segs[i + 1].second) {
				events.push_back(Event(segs[i + 1].first, CHANGE, i + 1));
			}
		}
		else {
			events.push_back(Event(segs[i + 1].first, CHANGE, i + 1));
			if (segs[i + 1].first < segs[i].first && segs[i + 1].second > segs[i].second) {
				events.push_back(Event(segs[i].first, CHANGE, i));
			}
		}
	}

	sort(all(events));

	multiset<int> lefts, rights;

	vector<int> smaller(comps, 0);
	int smallSegs = 0;

	for (int i = 0; i < comps; ++i) {
		if (haveOne[i] && !haveOne[i ^ 1]) {
			lefts.insert(segs[i].first);
			rights.insert(segs[i].second);
			smaller[i ^ 1] = 1;
		}
	}

	for (auto item : events) {
		if (item.x > maxCoor) {
			break;
		}
		if (item.type == ASK) {
			if (smallSegs + lefts.size() == relevantComps) {
				int n2 = maxT - item.x;
				if (n2 < 0) {
					continue;
				}
				if (!lefts.empty()) {
					int R = *rights.begin();
					int L = *lefts.rbegin();
					if (L > R || item.x + L > maxT || item.x + R < minT) {
						continue;
					}
					if (minT <= item.x + R && minT >= item.x + L) {
						n2 = minT - item.x;
					}
					else
					if (maxT <= item.x + R && maxT >= item.x + L) {
						n2 = maxT - item.x;
					}
					else {
						n2 = L;
					}
				}
				
				cout << "POSSIBLE\n";
				cout << item.x << ' ' << n2 << "\n";
				for (int i = 0; i < n; ++i) {
					int cur = used[i];
					if (smaller[cur]) {
						cout << "1";
					}
					else {
						cout << "2";
					}
				}

				return;
			}
		}
		else {

			int now = item.compId;
			if (smaller[now ^ 1]) {
				smaller[now ^ 1] = 0;
				if (!haveOne[now ^ 1]) {
					++smallSegs;
				}
				if (haveOne[now]) {
					auto itL = lefts.find(segs[now].first);
					lefts.erase(itL);
					auto itR = rights.find(segs[now].second);
					rights.erase(itR);
				}
			}
			else {
				++smallSegs;
			}

			smaller[now] = 1;
			if (haveOne[now ^ 1]) {
				lefts.insert(segs[now ^ 1].first);
				rights.insert(segs[now ^ 1].second);
			}
		}
	}

	cout << "IMPOSSIBLE\n";

}