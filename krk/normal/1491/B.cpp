#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, u, v;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &u, &v);
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (i > 1) mx = max(mx, abs(a[i] - a[i - 1]));
		}
		int res = 0;
		if (mx == 0) res = min(2 * v, u + v);
		else if (mx == 1) res = min(u, v);
		printf("%d\n", res);
	}
    return 0;
}