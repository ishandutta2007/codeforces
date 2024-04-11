#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int tims[Maxn];
bool was[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(tims, tims + n + 1, 0);
		fill(was, was + n + 1, false);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			was[a[i]] = true;
			if (i > 0 && a[i - 1] != a[i])
				tims[a[i]]++;
		}
		int res = Maxn;
		for (int i = 0; i <= n; i++) if (was[i])
			res = min(res, tims[i] + (a[n - 1] != i));
		printf("%d\n", res);
	}
    return 0;
}