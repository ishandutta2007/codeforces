#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
int cou[2*N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		ll x;
		cin >> n >> x;
		string str;
		cin >> str;

		if (x < 0) {
			x = -x;
			for (int i = 0; i < n; ++i) {
				str[i] = (str[i] == '1' ? '0' : '1');
			}
		}
		
		for (int i = 0; i < 2*n+1; ++i) cou[i] = 0;

		ll s = 0;
		for (int i = 0; i < n; ++i) {
			++cou[n + s];
			s += (str[i] == '0' ? 1 : -1);
		}
		
		// Count for amounts x, x-s, x-2s, ...
		ll res = 0;
		if (s == 0) {
			if (x < n) res = (cou[n + x] ? -1 : 0);
		} else if (s < 0) {
			for (; x < n; x -= s) res += cou[n + x];
		} else {
			if (x > (n-1)) x -= ((x - (n-1) + (s-1)) / s) * s;
			for (; x > -n; x -= s) res += cou[n + x];
		}
		cout << res << '\n';
	}
}