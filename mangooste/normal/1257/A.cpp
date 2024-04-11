#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>
#include <ctime>

typedef long long ll;
typedef long double ld;

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		int k1 = a - 1, k2 = n - b;
		cout << min(b - a + min(k1 + k2, x), n - 1) << '\n';
	}
	return 0;
}