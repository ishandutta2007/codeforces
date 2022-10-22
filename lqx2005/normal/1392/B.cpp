#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
const ll inf = 4e9;
ll t;
ll n;
ll k;
ll a[N];
int main()
{
	scanf("%lld", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		scanf("%lld%lld", &n, &k);
		ll mx = -inf;
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), mx = max(mx, a[i]); 
		for(int i = 1; i <= n; i++) a[i] = mx - a[i];
		k--;
		if(k % 2 == 1)
		{
			mx = -inf;
			for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
			for(int i = 1; i <= n; i++) a[i] = mx - a[i];
		}
		for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
		printf("\n");
	}
	return 0;
}