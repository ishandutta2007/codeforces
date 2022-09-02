#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 500;
const int M = 2 * (int)1e5;
const int N = 2 * (int)1e5;
int val[K + 1][K];
int add[M + 1];

int xs[N];
int ys[N];
int ts[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> xs[i] >> ys[i];
		ts[i] = -1;
	}

	int cur = 0;
	for (int t = 0; t < m; ++t) {
		// Move between maintenance / operation
		for (int k = 1; k <= K; ++k) cur += val[k][t % k];
		cur += add[t];

		// Add / Remove train
		int op, j;
		cin >> op >> j;
		--j;

		int k = xs[j] + ys[j];
		int mult = (op == 1 ? 1 : -1);
		if (op == 2) {
			int dt = (t - ts[j]) % k;
			if (dt >= xs[j]) --cur; // Was in maintenance
		} else {
			ts[j] = t;
		}

		if (k <= K) {
			val[k][ts[j] % k] -= mult;
			val[k][(ts[j] + xs[j]) % k] += mult;
		} else {
			for (int x = ts[j]; x < m; x += k) add[x] -= mult;
			for (int x = ts[j] + xs[j]; x < m; x += k) add[x] += mult;
		}

		// Print
		cout << cur << '\n';
	}
	
}