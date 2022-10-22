#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, p, k;
char str[Maxn];
int x, y;
ll cost[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &p, &k);
		fill(cost, cost + k, 0);
		scanf("%s", str);
		scanf("%d %d", &x, &y);
		for (int i = p - 1; i < n; i++)
			if (str[i] == '0') cost[(i - (p - 1)) % k] += x;
		ll res = cost[0];
		for (int i = 0; n - i >= p; i++) {
			res = min(res, ll(y) * i + cost[i % k]);
			if (str[i + (p - 1)] == '0') cost[i % k] -= x;
		}
		printf("%I64d\n", res);
	}
    return 0;
}