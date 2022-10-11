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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector <int> a(n);
	vector <pair <int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = -i;
		a[i] = v[i].first;
	}
	sort(v.rbegin(), v.rend());
	int m;
	cin >> m;
	while (m--) {
		int k, pos;
		cin >> k >> pos;
		vector <int> tmp(k);
		for (int i = 0; i < k; i++) {
			tmp[i] = -v[i].second;
		}
		sort(tmp.begin(), tmp.end());
		cout << a[tmp[pos - 1]] << '\n';
	}
	return 0;
}