#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q;
int a[Maxn];
int ones;

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) ones++;
	}
	for (int i = 1; i <= q; i++) {
		int t, x; scanf("%d %d", &t, &x);
		if (t == 1) {
			ones -= a[x] == 1;
			a[x] = 1 - a[x];
			ones += a[x] == 1;
		} else printf("%d\n", x <= ones? 1: 0);
	}
    return 0;
}