#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long

using namespace std;
const int N = 1e5 + 10;
int T;
int d[N], sum[N];
int main()
{
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		rep0(i, n) scanf("%d", &d[i]);
		sort(d, d + n);
		ll ans = d[n - 1];
		rep0(i, n) ans -= (ll)(2 * i - n + 1) * d[i];
		printf("%lld\n", ans);
	}
	return 0;
}