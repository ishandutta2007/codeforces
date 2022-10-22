#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int res[Maxn];

void Solve(int l, int r, int val)
{
	int mx = l;
	for (int i = l; i <= r; i++)
		if (a[i] > a[mx]) mx = i;
	res[mx] = val;
	if (l < mx) Solve(l, mx - 1, val + 1);
	if (mx < r) Solve(mx + 1, r, val + 1);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		Solve(0, n - 1, 0);
		for (int i = 0; i < n; i++)
			printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}