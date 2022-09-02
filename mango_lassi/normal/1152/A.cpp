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
	int c0 = 0;
	int c1 = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v % 2 == 0) ++c0;
		else ++c1;
	}
	int d0 = 0;
	int d1 = 0;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		if (v % 2 == 0) ++d0;
		else ++d1;
	}
	int res = min(c0, d1) + min(c1, d0);
	cout << res << '\n';
}