#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		vector <int> a;
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (x) {
				a.push_back(i);
			}
		}
		n = a.size();
		int m  = n/2, ans = 0;
		for (int i = 1; i < n; i++) {
			ans += abs(a[i] - a[i - 1] - 1);
		}
		printf("%d\n", ans);
	}


}