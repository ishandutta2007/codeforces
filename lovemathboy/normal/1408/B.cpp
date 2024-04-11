#include <bits/stdc++.h>
using namespace std;

int tc;
int n, k;

int main() {
	scanf("%d", &tc);
	for (int cas = 1; cas <= tc; cas++) {
		scanf("%d %d", &n, &k);
		int sum = 1;
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i-1]) sum++;
		}
		if (sum > k) {
			if (k == 1) printf("-1\n");
			else printf("%d\n", (sum - k - 1)/(k-1) + 2);
		}
		else printf("1\n");
	}
}