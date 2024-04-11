#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	// If we know we are using k operations, what to do?
	// Calculate for each prefix lowest we can get it
	int low = 0;
	int high = m;
	while(low != high) {
		int mid = (low + high) >> 1;
		
		int res = 0;
		bool fail = false;
		for (int i = 0; i < n; ++i) {
			if (as[i] + mid >= m + res) res = res;
			else if (as[i] + mid >= res) res = max(res, as[i]);
			else fail = true;
		}
		if (fail) low = mid + 1;
		else high = mid;
	}
	cout << low << '\n';
}