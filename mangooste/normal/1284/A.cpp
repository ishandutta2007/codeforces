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

	int n, m;
	cin >> n >> m;
	vector <string> d1(n), d2(m);
	for (int i = 0; i < n; i++) {
		cin >> d1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> d2[i];
	}

	int tt;
	cin >> tt;
	while (tt--) {
		int64 y;
		cin >> y;
		cout << d1[(y - 1) % n] << d2[(y - 1) % m] << '\n';
	}
}