#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
ll res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		ll ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			res[i] = a[i];
			if (i + a[i] < n) res[i] += res[i + a[i]];
			ans = max(ans, res[i]);
		}
		printf("%I64d\n", ans);
	}
    return 0;
}