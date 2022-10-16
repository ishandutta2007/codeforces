#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;
int n, a[N];
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		int v1 = 0, v2 = 2e9;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
		    if (i + 1 <= n && a[i] != -1 && a[i + 1] != -1) ans = max(ans, abs(a[i + 1] - a[i]));
			if (a[i] == -1) {
				if (i - 1 >= 1 && a[i - 1] != -1) v1 = max(v1, a[i - 1]), v2 = min(v2, a[i - 1]);
				if (i + 1 <= n && a[i + 1] != -1) v1 = max(v1, a[i + 1]), v2 = min(v2, a[i + 1]);
			}
		}
	    int k = (v1 + v2) >> 1;
	    ans = max(ans, max(v1 - k, k - v2));
		printf("%d %d\n", ans, k);
	}
}