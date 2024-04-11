#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, d;
		scanf("%d %d", &n, &d);
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a.begin(), a.end());
		if (a[a.size() - 1] <= d) {
			printf("YES\n");
			continue;
		}
		else if (a[0] + a[1] <= d) {
			printf("YES\n");
		}
		else printf("NO\n");
		
	}
	return 0;
}