#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
ll t;
ll n;
ll a[N];
int main()
{
	scanf("%lld", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		scanf("%lld", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		ll ans = 0;
		for(int i = 2; i <= n; i++) ans += max(1ll * 0, a[i - 1] - a[i]);
		printf("%lld\n", ans);		
	}
	return 0;
}