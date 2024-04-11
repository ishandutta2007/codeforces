#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int cnt[105];


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			ans = max(ans, cnt[i]);
			cnt[i] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}