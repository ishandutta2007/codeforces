#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstring>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <complex>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define mp make_pair
#define all(a) a.begin(), a.end()

typedef long long li;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long double ld;

void precalc();
void solve();
int main() {
#ifdef VKCUP
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	cout.precision(20);
	cout << fixed;
	cout.sync_with_stdio(0);
	cin.tie(0);
	clock_t start = clock();

	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
#ifdef VKCUP
	cerr << endl << (clock() - start) / 1.0 / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}

void precalc() {

}

vector<pair<string, int>> s[2];
vector<char> used[2];

vector<pair<int, int>> res;

void rec(int pref, int L1, int R1, int L2, int R2) {
	if (L1 == R1 || L2 == R2) {
		return;
	}
	int lef[2];
	int rig[2];
	lef[0] = L1;
	lef[1] = L2;
	rig[0] = R1;
	rig[1] = R2;
	int pointers[2];
	for (int i = 0; i < 2; ++i) {
		pointers[i] = lef[i];
		while (pointers[i] < rig[i] && s[i][pointers[i]].first.size() == pref) {
			++pointers[i];
		}
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		int nexLef[2], nexRig[2];
		for (int i = 0; i < 2; ++i) {
			while (pointers[i] < rig[i] && s[i][pointers[i]].first[pref] < c) {
				++pointers[i];
			}
			nexLef[i] = pointers[i];
			nexRig[i] = nexLef[i];
			while (nexRig[i] < rig[i] && s[i][nexRig[i]].first[pref] == c) {
				++nexRig[i];
			}
		}
		rec(pref + 1, nexLef[0], nexRig[0], nexLef[1], nexRig[1]);
	}

	int j = L2;
	for (int i = L1; i < R1; ++i) {
		if (!used[0][i]) {
			while (j < R2 && used[1][j]) {
				++j;
			}
			if (j < R2) {
				used[0][i] = true;
				used[1][j] = true;
				res.push_back(mp(i, j));
			}
		}
	}
}

int getLcp(const string& s, const string& q) {
	int ans = 0;
	while (ans < s.length() && ans < q.length() && s[ans] == q[ans]) {
		++ans;
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2; ++i) {
		used[i].resize(n, false);
		s[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> s[i][j].first;
			s[i][j].second = j;
		}
		sort(all(s[i]));
	}

	rec(0, 0, n, 0, n);

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int fs = res[i].first, sc = res[i].second;
		ans += getLcp(s[0][fs].first, s[1][sc].first);
	}

	cout << ans << "\n";

	for (int i = 0; i < n; ++i) {
		int fs = res[i].first, sc = res[i].second;
		cout << s[0][fs].second + 1 << ' ' << s[1][sc].second + 1 << "\n";
	}

}