#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

typedef pair<int, int> pii;

bool inside(int a, int b, int pa) {
	return (pa >= a && pa <= b);
}

bool check(int a, int b, const set<pii>& work) {
	for (set<pii>::iterator ii = work.begin(); ii != work.end(); ii++) {
		int pa = ii->first, pb = ii->first + ii->second - 1;

		if (inside(a, a + b - 1, pa) || inside(a, a + b - 1, pb)) return false;
		if (inside(pa, pb, a) || inside(pa, pb, a + b - 1)) return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;

	set<pii> work;
	vector<pii> ordered;

	REP(i, n) {
		int a, b; cin >> a >> b;
		if (check(a, b, work)) {
			work.insert(pii(a, b));
			ordered.push_back(pii(a, b));
			continue;
		}
	
		if (check(1, b, work)) {
			work.insert(pii(1, b));
			ordered.push_back(pii(1, b));
			continue;
		}

		bool found = false;
		for (set<pii>::iterator ii = work.begin(); !found && ii != work.end(); ii++) {
			if (check(ii->first + ii->second, b, work)) {
				work.insert(pii(ii->first + ii->second, b));
				ordered.push_back(pii(ii->first + ii->second, b));
				found = true;
			}
		}
	}

	REP(i, n) {
		printf("%d %d\n", ordered[i].first, ordered[i].first + ordered[i].second - 1);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	solve();
	return 0;
}