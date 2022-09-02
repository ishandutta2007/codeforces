#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = n-1; i > 0; --i) as[i] -= as[i-1];
	vector<int> lens;
	for (int k = 1; k <= n; ++k) {
		bool can = true;
		for (int i = 0; i < n; ++i) can &= (as[i] == as[i % k]);
		if (can) lens.push_back(k);
	}

	cout << lens.size() << '\n';
	for (auto it : lens) cout << it << ' '; cout << '\n';
}