#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int n;
		cin >> n;

		// Optimal strategy for T is to always play in the largest pile he can.
		// This way, he can always play in some pile with maximum number of remaining stones
		// T wins when
		// 	1. One pile is larger than the others combined
		//	2. The total amount of stones is odd

		int sum = 0, mx = 0;
		vector<int> as(n);
		for (int& a : as) {
			cin >> a;
			sum += a;
			mx = max(mx, a);
		}
		if ((mx > sum - mx) || (sum & 1)) cout << "T\n";
		else cout << "HL\n";

	}
}