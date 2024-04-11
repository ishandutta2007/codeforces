#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int T;
int n, k;
int p[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		ll sum = 0;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			sum += p[i];
		}
		for (int i = n - 1; i > 0; i--) {
			sum -= p[i];
			ll nd = (100ll * p[i] - 1ll) / k + 1ll;
			if (nd > sum) mx = max(mx, nd - sum);
		}
		printf("%I64d\n", mx);
	}
    return 0;
}