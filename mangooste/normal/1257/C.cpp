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
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		vector <int> pos(n, -1);
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			if (pos[a[i]] != -1) {
				ans = min(ans, i - pos[a[i]]);
			}
			pos[a[i]] = i;
		}
		cout << (ans == 1e9 ? -1 : ans + 1) << '\n';
	}
	return 0;
}