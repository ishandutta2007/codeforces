#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = 0;
	vector<ll> adds(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		adds[i] = b - a;
		res += (ll)a * (n-1);
	}

	sort(adds.begin(), adds.end());
	for (int i = 0; i < n; ++i) {
		res += adds[i] * (n-1-i);
	}
	cout << res << '\n';
}