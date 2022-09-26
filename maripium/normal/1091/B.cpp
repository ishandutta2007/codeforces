#include <bits/stdc++.h>
using namespace std;

int n;
int x[1005], y[1005];
int a[1005], b[1005];
map<pair<int,int>,int> mp;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", x + i, y + i);
		mp[{x[i], y[i]}] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", a + i, b + i);
	}
	for (int i = 1; i <= n; ++i) {
		int xx = x[1] + a[i], yy = y[1] + b[i];
		bool found = false;
		for (int j = 1; j <= n; ++j) if (j != i) {
			if (!mp.count({xx - a[j], yy - b[j]})) {
				found = true; 
				break;
			}
		}
		if (!found) {
			return !printf("%d %d\n", xx, yy);
		}
	}
}