#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000000;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a[0] = a[n + 1] = 0;
		ll res = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n + 1; i++)
			res += abs(a[i] - a[i - 1]);
		for (int i = 1; i <= n; i++)
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				int red = a[i] - max(a[i - 1], a[i + 1]);
				res -= red;
			}
		printf("%I64d\n", res);
	}
    return 0;
}