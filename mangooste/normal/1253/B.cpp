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

const int N = int(1e6) + 1;

int was[N];

signed main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set <int> s;
	vector <int> ans;
	int last = -1;
	for (int i = 0; i < N; i++) {
		was[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int num = abs(a[i]);
		if (a[i] > 0) {
			if (s.find(num) != s.end() || was[num] == ans.size()) {
				cout << "-1\n";
				return 0;
			}
			was[num] = ans.size();
			s.insert(num);
		}
		else {
			if (s.find(num) == s.end()) {
				cout << "-1\n";
				return 0;
			}
			s.erase(num);
		}
		if (s.size() == 0) {
			ans.push_back(i - last);
			last = i;
		}
	}
	if (s.size() != 0) {
		cout << "-1\n";
		return 0;
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}
/*
8
1 -1 1 2 -2 2 -2 -1
*/