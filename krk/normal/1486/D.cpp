#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
int a[Maxn];
int mn[Maxn];

bool Check(int val)
{
	mn[0] = 0;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= val) cur++;
		else cur--;
		if (i >= k && cur - mn[i - k] > 0) return true;
		mn[i] = min(cur, mn[i - 1]);
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = 1, r = n;
	while (l <= r) {
		int m = l + r >> 1;
		if (Check(m)) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r);
    return 0;
}