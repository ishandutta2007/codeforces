#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, x, y;
	cin >> n >> x >> y;
	int64 d = x / __gcd(x, y) * y;
	int64 fx = d / x, fy = d / y;

	// cout << fx << " " << fy << endl;

	for (int i = 0; i < n; ++i){
		int64 c; cin >> c;
		int64 lo = 0;
		int64 hi = 1;

		while (hi / fx + hi / fy < c) hi *= 2;
		
		while (lo + 1 < hi){
			int64 mid = (lo + hi) / 2;
			if (mid / fx + mid / fy < c)
				lo = mid;
			else
				hi = mid;
		}

		// cout << hi << endl;
		// cout << hits(x, fx, hi) << " " << hits(y, fy, hi) << endl;
		// cout << hits(x, fx, hi - 1) << " " << hits(y, fy, hi - 1) << endl;

		bool vanya = hi % fx == 0;
		bool vova = hi % fy == 0;

		if (vanya && vova) cout << "Both" << endl;
		else if (vanya) cout << "Vanya" << endl;
		else cout << "Vova" << endl;
	}	

	return 0;
}