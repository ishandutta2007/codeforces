#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, A[510];

ll get(int x)
{
	for(int i = 1; i <= n; i ++)
		if(A[i] < x)
			return 1e18;
	ll res = 0;
	for(int i = 1; i <= n; i ++)
	{
		ll l = (A[i] + x) / (x + 1);
		ll r = A[i] / x;
		if(l > r) return 1e18;
		res += l;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &A[i]);
	sort(A + 1, A + 1 + n);
	ll ans = 1e18;
	for(int i = 1; i <= A[1] && i <= 31500; i ++)
	{
		int l = (A[1] - 1) / i;
		int r = (A[1]) / i;
		for(int j = max(1, l); j <= r; j ++) ans = min(ans, get(j));
	}
	for(int i = 1; i <= 31500; i ++) ans = min(ans, get(i));
	printf("%lld\n", ans);
	return 0;
}