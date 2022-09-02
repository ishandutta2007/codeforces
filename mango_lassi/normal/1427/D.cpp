#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> ops;

vector<int> apply(vector<int> vec, vector<int> splits) {
	vector<int> tmp;
	for (auto v : splits) {
		if (v != 0) tmp.push_back(v);
	}
	splits = tmp;

	if (splits.size() > 1) ops.push_back(splits);
	reverse(splits.begin(), splits.end());

	int n = vec.size(), sum = 0;
	vector<int> res(n);
	for (auto v : splits) {
		for (int i = 0; i < v; ++i) res[i + sum] = vec[n - v - sum + i];
		sum += v;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	// 1. Apply operation to [...] [1 ...] -> 1 ...
	// 2. Apply operation to [1] [...] [n ...] -> n ... 1
	// 3. Apply operation to [n] [...] [2 ...] [1] -> 1 2 ... n
	// 4. Apply operation to [1 2] [...] [n-1 ...] [n] -> n n-1 ... 1 2
	// 5. Apply operation to [n n-1] [...] [3 ...] [1 2] -> 1 2 3 ... n n-1
	// ...

	// 1. 1 ? ? ?
	// 2. 4 ? ? 1
	// 3. 1 2 3 4

	// 1. 1 ? ? ? ?
	// 2. 5 ? ? ? 1
	// 3. 1 2 ? ? 5
	// 4. 5 4 ? 1 2
	// 5. 1 2 3 4 5

	// 1. 1 ? ? ? ? ?
	// 2. 6 ? ? ? ? 1
	// 3. 1 2 ? ? ? 6
	// 4. 6 5 ? ? 1 2
	// 5. 1 2 3 ? 6 5


	int a = 0;
	int b = 0;
	for (int i = 0; i < n; ++i) {
		int tar = ((i & 1) ? n-b : 1+a);
		int j = 0;
		for (; j < n; ++j) {
			if (vals[j] == tar) break;
		}

		if (i & 1) {
			vals = apply(vals, {a, j - a, n - b - j, b});
			++b;
		} else {
			if (b) vals = apply(vals, {b-1, 1, j - b, n - a - j, a});
			else vals = apply(vals, {j, n - a - j, a});
			++a;
		}
		/*
		cerr << i << " (" << j << "): ";
		for (auto v : vals) cerr << v << ' '; cerr << "\n";
		*/
		if ((n % 2 == 0) && (i == n-2)) break;
		
	}

	cout << ops.size() << '\n';
	for (const vector<int>& vec : ops) {
		cout << vec.size();
		for (auto v : vec) cout << ' ' << v; cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
	
}