#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, c;
int a[Maxn];
int b[Maxn];

ll Need(int x, int perday)
{
	return x <= 0? 0: (x - 1) / perday + 1;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &c);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n - 1; i++)
			scanf("%d", &b[i]);
		ll res = Need(c, a[0]);
		ll has = 0, tim = 0;
		for (int i = 0; i < n - 1; i++) {
			ll work = Need(b[i] - has, a[i]);
			tim += work; has += work * a[i];
			tim++; has -= b[i];
			res = min(res, tim + Need(c - has, a[i + 1]));
		}
		printf("%I64d\n", res);
	}
    return 0;
}