#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

bool run() {
	ll x, y;
	cin >> x >> y;
	if ((x - y) > 1)
		return true;
	else
		return false;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		if (run())
			cout << "YES\n";
		else
			cout << "NO\n";
	return 0;
}