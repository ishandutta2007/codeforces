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

//int mod = 1000000007;

//#define int li

int n, c;

int l[1000100], r[1000100];

vector<int> lefts[1000100], rights[1000100];

enum {
	LEFT = 1, RIGHT = 2
};

struct Event {
	int id;
	int pos;
	int type;
	Event(int id, int pos, int type) :id(id), pos(pos), type(type) {}
};

void solve() {
	memset(l, -1, sizeof l);
	memset(r, -1, sizeof r);

	cin >> n >> c;
	for (int i = 0; i < c; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if (a >= b) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		string s;
		cin >> s;
		if (s[0] == 'L') {
			l[a] = max(l[a], b);
			lefts[a].push_back(b);
		}
		else {
			r[a] = max(r[a], b);
			rights[a].push_back(b);
		}
	}

	stack<Event> st;
	
	vector<int> ans;

	for (int i = 0; i < n; ++i) {
		if (l[i] != -1) {
			st.push(Event(i, l[i], LEFT));
		}
		else {
			ans.push_back(i);
			if (r[i] != -1) {
				st.push(Event(i, r[i], RIGHT));
			}
		}

		while (!st.empty()) {
			Event cur = st.top();
			if (cur.pos <= i) {
				st.pop();
				if (cur.type == LEFT) {
					ans.push_back(cur.id);
					if (r[cur.id] != -1) {
						st.push(Event(cur.id, r[cur.id], RIGHT));
						break;
					}
				}
			}
			else {
				break;
			}
		}

	}

	assert(ans.size() == n);

	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		pos[ans[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		for (int lef : lefts[i]) {
			if (pos[lef] > pos[i]) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
		for (int rig : rights[i]) {
			if (pos[rig] < pos[i]) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] + 1 << ' ';
	}
	

}