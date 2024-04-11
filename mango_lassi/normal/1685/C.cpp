#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isValid(string str) {
	int cur = 0;
	for (auto c : str) {
		cur += (c == '(' ? 1 : -1);
		if (cur < 0) return false;
	}
	return cur == 0;
}

string flipRange(string str, int a, int b) {
	for (int i = 0; a+i < b-i; ++i) swap(str[a + i], str[b - i]);
	return str;
}

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	if (isValid(str)) {
		cout << 0 << '\n';
	} else {
		// Must make all prefix sums nonnegative
		// Take longest negative prefix, swap that 

		// Say the largest prefix sum is at position i. Flip that prefix
		// Now, all prefix sums up until that point are 

		// 2 operations is always enough!
		//	Flip prefix ending at i, where i is the rightmost position where the maximum prefix sum is
		// 	Flip the suffix starting at i + 1

		// How to check if 1 operation is sufficient?
		// Let i be the largest prefix sum before we go negative, and j the smallest suffix sum before we go positive. Flip [i, j]?
		

		vector<int> prefs(2*n + 1, 0);
		for (int i = 0; i < 2*n; ++i) prefs[i + 1] = prefs[i] + (str[i] == '(' ? 1 : -1);

		pair<int, int> le = {-1, -1};
		for (int i = 0; i < 2 * n; ++i) {
			if (prefs[i + 1] < 0) break;
			le = max(le, {prefs[i + 1], i});
		}

		pair<int, int> ri = {-1, 2*n};
		for (int i = 2*n - 1; i >= 0; --i) {
			if (prefs[i] < 0) break;
			ri = max(ri, {prefs[i], i});
		}
		
		/*
		cerr << le.first << ' ' << le.second << '\n';
		cerr << ri.first << ' ' << ri.second << '\n';
		cerr << "Test flipping range " << le.second + 1 << ' ' << ri.second - 1 << '\n';
		*/

		if (isValid(flipRange(str, le.second + 1, ri.second - 1))) {
			cout << 1 << '\n';
			cout << le.second + 2 << ' ' << ri.second << '\n';
		} else {
			le = {-1, 0};
			for (int i = 0; i < 2*n; ++i) le = max(le, {prefs[i + 1], i});
	
			int x = le.second;
			assert(x + 2 < 2 * n);
			assert(isValid(flipRange(flipRange(str, 0, x), x + 1, 2*n - 1)));
		
			cout << 2 << '\n';
			cout << 1 << ' ' << le.second + 1 << '\n';
			cout << le.second + 2 << ' ' << 2*n << '\n';
		}
	}
	// cerr << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}