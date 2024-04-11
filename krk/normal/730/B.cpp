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

int readStatus() {
	char c; scanf(" %c", &c);
	if (c == '<') return -1;
	if (c == '>') return 1;
	return 0;
}

void solve() {
	int T; cin >> T;
	REP(t, T) {
		int n; cin >> n;
		int pmin = 0, pmax = 0;
		if (n == 1) {
			cout << "! 1 1" << endl;
			fflush(stdout);
			continue;
		}

		cout << "? 1 2" << endl;
		fflush(stdout);
		int status = readStatus();
		if (status < 0) {
			pmin = 1, pmax = 2;
		} else if (status > 0) {
			pmin = 2, pmax = 1;
		} else {
			pmin = pmax = 1;
		}

		for (int i = 3; i <= n; i += 2) {
			int tmin, tmax;
			if (i < n) {
				cout << "? " << i << " " << i + 1 << endl;
				fflush(stdout);
				status = readStatus();
				if (status < 0) {
					tmin = i, tmax = i + 1;
				} else if (status > 0) {
					tmin = i + 1, tmax = i;
				} else {
					tmin = tmax = i;
				}
			} else {
				tmin = tmax = i;
			}

			cout << "? " << tmin << " " << pmin << endl;
			fflush(stdout);
			status = readStatus();
			if (status < 0) {
				pmin = tmin;
			}

			cout << "? " << tmax << " " << pmax << endl;
			fflush(stdout);
			status = readStatus();
			if (status > 0) {
				pmax = tmax;
			}
		}

		cout << "! " << pmin << " " << pmax << endl;
		fflush(stdout);
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