#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef long long int64;
typedef long double ld;

template <class T> bool bmin(T& a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool bmax(T& a, T b) { return a < b ? (a = b, true) : false; }

const int64 INF64 = 1e18;
const int INF = 1e9;

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <char> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}

		vector <int> left(n);
		left[0] = -1;
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == 'P') {
				left[i] = left[i - 1];
			} else {
				left[i] = i - 1;
			}
		}

		int res = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'P' && left[i] != -1) {
				res = max(res, i - left[i]);
			}
		}

		cout << res << '\n';
	}
}