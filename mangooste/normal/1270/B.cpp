#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef int64_t int64;
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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int64> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		bool ok = false;
		for (int i = 0; i < n - 1 && !ok; i++) {
			if (abs(a[i + 1] - a[i]) > 1) {
				cout << "YES\n";
				cout << i + 1 << ' ' << i + 2 << '\n';
				ok = true;
			}
		}
		if (!ok) {
			cout << "NO\n";
		}
	}
}