#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, l, r, x, mask, i;
	cin >> n >> l >> r >> x;
	vector<ll> diff(n);
	for (i = 0; i < n; i++)
		cin >> diff[i];

	ll res = 0, cnt, sum, low, high;
	for (mask = 0; mask < (1 << n); mask++) {
		cnt = 0;
		sum = 0;
		low = 1e+9;
		high = 0;
		for (i = 0; i < n; i++)
			if ((mask >> i) & 1) {
				cnt++;
				sum += diff[i];
				low = min(low, diff[i]);
				high = max(high, diff[i]);
			}
		if ((cnt > 1) && (sum >= l) && (sum <= r) && (high - low >= x))
			res++;
	}

	cout << res;
	return 0;
}