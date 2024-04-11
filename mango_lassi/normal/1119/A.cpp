#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i] != c[0]) res = max(res, abs(i - 0));
		if (c[i] != c[n-1]) res = max(res, abs(i - (n-1)));
	}
	cout << res << '\n';
}