#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> perm(n);
	for (int& i : perm) cin >> i;

	int low = 0;
	bool fail = false;
	for (int i = n-1; i >= 0; --i) {
		int j = i-1;
		for (j = i-1; j >= 0; --j) {
			if (perm[j] != perm[j+1] - 1) break;
		}
		++j;

		if (perm[i] - (i-j) != low + 1) fail = true;
		low = perm[i];
		i = j;
	}
	if (fail) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}