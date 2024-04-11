#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1 << 20;
int vals[N];
vector<int> res;

void recSolve(int i, int n, int m) {
	while(vals[i] > 0) {
		int j = i;
		while(2*j < n) {
			int x = 2*j;
			if (vals[x^1] > vals[x]) x ^= 1;
			if (vals[x] > 0) j = x;
			else break;
		}

		if (j < m) break;
		res.push_back(i);

		for (int x = i; x != j;) {
			x *= 2;
			if (vals[x^1] > vals[x]) x ^= 1;
			vals[x >> 1] = vals[x];
		}
		vals[j] = 0;
	}
	if (i < m) {
		recSolve(2*i, n, m);
		recSolve(2*i+1, n, m);
	}
}

void solve() {
	// Number of increasing arrays with increasing prefix xors
	// Each number has to have a higher first bit than the previous, everything else is arbitrary

	int h, g;
	cin >> h >> g;
	int n = (1 << h);
	int m = (1 << g);

	for (int i = 1; i < n; ++i) cin >> vals[i];

	recSolve(1, n, m);
	
	ll sum = 0;
	for (int i = 0; i < n; ++i) sum += vals[i];

	cout << sum << '\n';
	for (auto i : res) cout << i << ' '; cout << '\n';

	res.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Greedily remove root while possible, then recurse to both children

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}