#include <bits/stdc++.h>
using namespace std;

int tc;

int main() {
	scanf("%d", &tc);
	int n, m;
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d %d", &n, &m);
		bool good = false;
		int i1, i2, i3, i4;
		for (int i = 0; i < n; i++) {
			scanf("%d %d\n%d %d", &i1, &i2, &i3, &i4);
			if (i2 == i3) good = true;
		}
		if (good && m%2 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}