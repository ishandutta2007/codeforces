#include <bits/stdc++.h>
using namespace std;
 
int tc;
int n, k;
vector<int> a;
 
int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);
		a.clear(); a.resize(k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
		}
		int prev = 2012345678;
		bool pos = true;
		for (int i = k - 2; i >= 0; i--) {
			int dif = a[i+1] - a[i];
			if (dif > prev) {
				pos = false;
				break;
			}
			prev = dif;
		}
		if (a[0] > prev * (n - k + 1LL)) pos = false;
		if (!pos) {
			printf("No\n");
			continue;
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}