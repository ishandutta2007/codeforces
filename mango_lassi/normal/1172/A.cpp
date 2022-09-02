#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> tim(n);

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		--vals[i];
		if (vals[i] != -1) tim[vals[i]] = 0;
	}

	vector<int> pile(n);
	for (int i = 0; i < n; ++i) {
		cin >> pile[i];
		--pile[i];
		if (pile[i] != -1) tim[pile[i]] = i+1;
	}

	// Case 1: We have to put 1 into the pile
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, tim[i] - i);
	}
	res += n;
	// Case 2: We don't put 1 into the pile
	if (tim[0] > 0) {
		bool seq = true;
		int k = n+1 - tim[0];
		for (int i = 1; i < k; ++i) {
			if (tim[i] != tim[i-1] + 1) seq = false;
		}
		if (seq) {
			bool fail = false;
			for (int i = k; i < n; ++i) {
				if (tim[i] > i-k) fail = true;
			}
			if (! fail) res = min(res, n-k);
		}
	}

	cout << res << '\n';
}