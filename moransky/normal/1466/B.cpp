#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, cnt[N * 2], b[N * 2];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n + 1; i++) b[i] = cnt[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			cnt[x]++;
		}
		int ans = 0;
		for (int i = 1; i <= 2 * n; i++) {
			if (cnt[i] && !b[i]) {
				cnt[i]--;
				b[i]++;
				ans++;
			}
			if (cnt[i] && !b[i + 1]) {
				cnt[i]--;
				b[i + 1]++;
				ans++;
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}