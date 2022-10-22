#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll sum = 0, mx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i > 0) sum += abs(a[i - 1] - a[i]);
		}
		for (int i = 0; i < n; i++)
			if (i == 0) mx = max(mx, ll(abs(a[0] - a[1])));
			else if (i == n - 1) mx = max(mx, ll(abs(a[n - 2] - a[n - 1])));
			else if (a[i] > a[i - 1] && a[i] > a[i + 1])
					mx = max(mx, 2ll * ll(min(a[i] - a[i - 1], a[i] - a[i + 1])));
			else if (a[i] < a[i - 1] && a[i] < a[i + 1])
					mx = max(mx, 2ll * ll(min(a[i - 1] - a[i], a[i + 1] - a[i])));
		printf("%I64d\n", sum - mx);
	}
    return 0;
}