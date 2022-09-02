#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> cou(n);
	for (int i = 0; i < n; ++i) cin >> cou[i];
	sort(cou.begin(), cou.end());

	// We can make all piles have different amounts iff
	// 1. There is at most one pair s.t. cou[i] == cou[i+1]
	// 2. There is no triple s.t. cou[i] + 1 == cou[i+1] == cou[i+2], since then we can't make the piles not equal
	int eqs = 0;
	for (int i = 0; i+1 < n; ++i) {
		if (cou[i] == cou[i+1]) {
			++eqs;
			if ((cou[i] == 0) || (i > 0 && cou[i-1] == cou[i] - 1)) {
				++eqs;
			}
		}
	}

	ll tar = (ll)n * (n-1) / 2;
	ll steps = 0;
	for (int i = 0; i < n; ++i) steps += cou[i];
	steps -= tar;

	bool fail = false;
	if (eqs >= 2) fail = true;
	else if (steps < 0) fail = true;
	else if (steps % 2 == 0) fail = true;
	
	if (fail) cout << "cslnb\n";
	else cout << "sjfnb\n";
}