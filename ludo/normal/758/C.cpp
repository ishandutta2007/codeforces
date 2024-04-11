#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, k, x, y;

ll timesat(ll r, ll c)
{
	if (n == 1) return (k - c + m - 1) / m;

	ll repeat = (2 * n - 2) * m;

	ll ret = k / repeat;
	if (r != 0 && r != n - 1) {
		ret *= 2;
	}

	ll rem = k % repeat;

	// cerr << "REMAINDER " << r << ", " << c << ": " << rem << endl;

	ll fpass = m * r + c;
	if (rem > fpass) {
		ret++;
		if (r != 0 && r != n - 1) {
			ll spass = m * (2 * n - 2 - r) + c;
			if (rem > spass) ret++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k >> x >> y;
	// sergei is at:
	// row: x, col: y

	// max person is at:
	// row: 1, col: 0
	// or
	// row: n-2, col: 0

	// min person is at:
	// row: 0, col: m-1
	// or
	// row: n-1, col: m-1

	ll maxT = timesat(0, 0);
	ll minT = min(timesat(0, m - 1), timesat(n - 1, m - 1));
	if (n > 2) {
		maxT = max(maxT, timesat(1, 0));
		maxT = max(maxT, timesat(n - 2, 0));
		// cerr << timesat(0, 0) << " | " << timesat(1, 0) << " | " << timesat(n - 2, 0) << endl;
	}
	ll serg = timesat(x - 1, y - 1);

	cout << maxT << " " << minT << " " << serg << endl;
	return 0;
}