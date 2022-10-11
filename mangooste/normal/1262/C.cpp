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

int find_open(int start, vector <int>& v) {
	while (v[start] != 1) {
		start++;
	}
	return start;
}

int find_close(int start, vector <int>& v) {
	while (v[start] != -1) {
		start++;
	}
	return start;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		v[i] = (tmp == '(' ? 1 : -1);
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < (k - 1) * 2; i++) {
		if (i % 2 == 0) {
			if (v[i] != 1) {
				int now = find_open(i, v);
				ans.push_back({ i, now });
				swap(v[i], v[now]);
			}
		}
		else {
			if (v[i] != -1) {
				int now = find_close(i, v);
				ans.push_back({ i, now });
				swap(v[i], v[now]);
			}
		}
	}
	int s = (k - 1) * 2;
	int del = n - s;
	for (int i = (k - 1) * 2; i < s + del / 2; i++) {
		if (v[i] != 1) {
			int now = find_open(i, v);
			ans.push_back({ i, now });
			swap(v[i], v[now]);
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
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