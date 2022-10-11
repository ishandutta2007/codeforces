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
#include <ctime>

typedef long long ll;
typedef long double ld;

using namespace std;

ll get(int l, int r, vector <ll>& pref) {
	if (l == 0) {
		return pref[r];
	}
	return pref[r] - pref[l - 1];
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector <ll> pref(n);
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	vector <ll> ans(n);
	ans[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (i < m) {
			ans[i] = pref[i];
			continue;
		}
		ans[i] = ans[i - m] + pref[i - m];
		ans[i] += get(i - m + 1, i, pref);
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}