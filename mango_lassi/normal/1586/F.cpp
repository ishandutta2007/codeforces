#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getStat(int mask, int c, int k) {
	vector<int> res(c);
	for (int j = 0; j < c; ++j) {
		res[j] = mask % k;
		mask /= k;
	}
	return res;
}

void solve() {
	int k, n;
	cin >> n >> k;

	// k = 2:
	//	Every node has a set of out-colours
	//	Every node before it has to have a out-colour not in its set
	//	-> with c colours, can have n <= 2^c
	// k > 2:
	//	-> with c colours, can have n <= k^c

	ll cur = 1;
	int c = 0;
	while(cur < n) {
		cur *= k;
		++c;
	}

	cout << c << '\n';
	for (int i = 0; i < n; ++i) {
		vector<int> stat = getStat(n-1-i, c, k);
		for (int t = i + 1; t < n; ++t) {
			vector<int> stat2 = getStat(n-1-t, c, k);

			bool found = 0;
			for (int j = 0; j < c; ++j) {
				if (stat[j] > stat2[j]) {
					found = 1;
					cout << j + 1 << ' ';
					break;
				}
			}
			assert(found);
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}