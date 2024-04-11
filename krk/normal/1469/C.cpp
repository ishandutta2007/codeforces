#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
int a[Maxn];

bool Solve()
{
	int l = a[0] - (k - 1), r = a[0] + k - 1;
	for (int i = 1; i < n - 1; i++) {
		l = max(l, a[i]);
		r = min(r, a[i] + k - 1);
		if (l > r) return false;
		r += k - 1;
		l -= (k - 1);
	}
	return l <= a[n - 1] && a[n - 1] <= r;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}