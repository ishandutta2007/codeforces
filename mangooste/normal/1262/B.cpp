#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> pr(n);
	for (int i = 0; i < n; i++) {
		cin >> pr[i];
	}
	vector <int> a(n);
	vector <char> used(n + 1, 0);
	used[pr[0]] = 1;
	a[0] = pr[0];
	int ind = (a[0] == 1 ? 2 : 1);
	for (int i = 1; i < n; i++) {
		if (pr[i] != pr[i - 1]) {
			a[i] = pr[i];
			used[a[i]] = 1;
			continue;
		}
		if (ind > pr[i]) {
			cout << "-1\n";
			return;
		}
		while (ind < n && used[ind]) ind++;
		if (ind > pr[i]) {
			cout << "-1\n";
			return;
		}
		a[i] = ind;
		ind++;
		used[a[i]] = 1;
	}
	for (auto i : a) cout << i << ' ';
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}