#include <bits/stdc++.h>
using namespace std;

int t;
int x, y;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &x, &y);
		int mx = max(x, y);
		if (x == y) printf("%d\n", mx * 2);
		else printf("%d\n", mx * 2 - 1);
	}
	return 0;
}