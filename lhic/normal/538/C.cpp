#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int n, m;

int main() {
	cin >> n >> m;
	int lst = 0;
	int lsth = 0;
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		int d, h;
		cin >> d >> h;
		ans = max(ans, h);
		if (lst == 0) {
			ans = max(ans, h + d - 1);
		}
		else {
			if (abs(d - lst) < abs(h - lsth)) {
				cout << "IMPOSSIBLE";
				return 0;
			}
			int x = d - lst - abs(h - lsth);
			ans = max(ans, max(h, lsth) + x / 2);
		}
		lst = d;
		lsth = h;
	}
	ans = max(ans, lsth + n - lst);
	cout << ans;
	return 0;
}