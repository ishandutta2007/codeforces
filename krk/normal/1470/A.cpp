#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int T;
int n, m;
int k[Maxn];
int c[Maxn];
ll sum[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d", &k[i]);
		sort(k + 1, k + n + 1);
		for (int i = 1; i <= m; i++) {
			scanf("%d", &c[i]);
			sum[i] = sum[i - 1] + c[i];
		}
		ll res = 1000000000000000000ll;
		ll cur = 0;
		for (int i = 0; i <= n; i++) {
			cur += c[k[i]];
			if (n - i <= m)
				res = min(res, cur + sum[n - i]);
		}
		printf("%I64d\n", res);
	}
    return 0;
}