#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 4000000000000000000ll;

int T;
int n;
int c[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &c[i]);
		ll res = Inf;
		ll sum = c[0];
		ll mn[2] = {c[0], c[1]};
		for (int i = 1; i < n; i++) {
			sum += c[i];
			mn[i % 2] = min(mn[i % 2], ll(c[i]));
			res = min(res, sum + ll(n - (i + 2) / 2) * mn[0] + ll(n - (i + 1) / 2) * mn[1]);
		}
		printf("%I64d\n", res);
	}
    return 0;
}