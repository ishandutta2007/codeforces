#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	scanf("%d", &tc);
	int n, m;
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d %d", &n, &m);
		if (n <= 2) printf("1\n");
		else printf("%d\n", (n-3)/m + 2);
	}
	return 0;
}