#include <bits/stdc++.h>
using namespace std;

int t;
int x1, y1, x2, y2;
int ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		ans = abs(x1 - x2) + abs(y1 - y2);
		if (x1 != x2 && y1 != y2) ans += 2;
		printf("%d\n", ans);
	}
	return 0;
}