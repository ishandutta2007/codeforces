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
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		vector <int> a(k1), b(k2);
		for (int i = 0; i < k1; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < k2; i++) {
			cin >> b[i];
		}
		if (*max_element(a.begin(), a.end()) > * max_element(b.begin(), b.end())) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}