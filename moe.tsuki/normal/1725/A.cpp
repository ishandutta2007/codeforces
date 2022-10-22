#include <bits/stdc++.h>

using namespace std;

signed main() {
	int64_t n, m;
	cin >> n >> m;
	if (m == 1) cout << n-1 << '\n';
	else cout << n * (m-1) << '\n';
}