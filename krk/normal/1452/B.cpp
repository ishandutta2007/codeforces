#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll nd = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			nd = max(nd, ll(a[i]) * (n - 1));
			sum += a[i];
		}
		nd = max(nd, sum + (n - 1 - sum % (n - 1)) % (n - 1));
		printf("%I64d\n", nd - sum);
	}
    return 0;
}