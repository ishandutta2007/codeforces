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
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		ll res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i++)
			if (i % 2 != 0) res1 += a[n - i] % 2 == 0? a[n - i]: 0;
			else res2 += a[n - i] % 2 != 0? a[n - i]: 0;
		if (res1 > res2) printf("Alice\n");
		else if (res1 == res2) printf("Tie\n");
		else printf("Bob\n");
	}
    return 0;
}