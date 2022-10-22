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
#define REPSZ(i, v) for (int i = 0; i < (int)(v.size()); i++)
#define REPLEN(i, line) for (int i = 0, l = strlen(line); i < l; i++)

typedef pair<int, int> pii;

const int MAXN = 105;
int before[MAXN];
int delta[MAXN];
int after[MAXN];

bool winBeforeChange(int ii, int jj) {
	int pi = before[ii], pj = before[jj];
	if (pi > pj) return true;
	if (pi == pj && ii < jj) return true;
	return false;
}

bool winAfterChange(int ii, int jj) {
	int pi = after[ii], pj = after[jj];
	if (pi > pj) return true;
	if (pi == pj && ii < jj) return true;
	return false;
}

bool winAfterBeforeChange(int ii, int jj) {
	int pi = after[ii], pj = before[jj];
	if (pi > pj) return true;
	if (pi == pj && ii < jj) return true;
	return false;
}

bool cmp_higher_place(const pii& a, const pii& b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

void solve() {
	int n; cin >> n;
	vector<pii> down, up;
	REP(i, n) {
		cin >> before[i] >> delta[i];
		after[i] = before[i] + delta[i];
		if (delta[i] < 0) {
			down.push_back(pii(before[i], i));
		}
		if (delta[i] > 0) {
			up.push_back(pii(before[i], i));
		}
	}
	sort(down.begin(), down.end(), cmp_higher_place);
	sort(up.rbegin(), up.rend(), cmp_higher_place);

	int r = 0;

	REP(i, n) {
		for (int j = i + 1; j < n; j++) {
			if (winBeforeChange(i, j) != winAfterChange(i, j)) {
				r++;
			}
		}
	}

	//cout << "temp = " << r << endl;

	REPSZ(i, down) {
		//cout << down[i].first << " " << down[i].second << endl;
		int ii = down[i].second;
		for (int j = i + 1; j < (int)(down.size()); j++) {
			int jj = down[j].second;
			if (!winAfterBeforeChange(ii, jj) && winAfterChange(ii, jj)) {
				r += 2;
			}
		}
	}

	//cout << "--" << endl;
	REPSZ(i, up) {
		//cout << up[i].first << " " << up[i].second << endl;
		int ii = up[i].second;
		for (int j = i + 1; j < (int)(up.size()); j++) {
			int jj = up[j].second;
			if (winAfterBeforeChange(ii, jj) && !winAfterChange(ii, jj)) {
				r += 2;
			}
		}
	}

	cout << r << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.out", "wt", stdout);
	#endif
	solve();
	return 0;
}