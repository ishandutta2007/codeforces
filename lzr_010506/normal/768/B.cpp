#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll B[110], a[110], A[110];
ll x, l, r;
int	main()
{
	cin >> x;
	if(x == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ll n = 0;
	while((1ll << (n + 1)) <= x) n ++;
	n ++;
	ll now = (1ll << n) - 1, y = x;
	for(int	i = 1; i <= n; i ++, y >>= 1)
		a[i] = B[i] = (y & 1ll), A[i] = (1ll << (n - i + 1)) - 1;
	for(int	i = n - 1; i >= 1; i --)
		B[i] += 2ll * B[i + 1];
	cin >> l >> r;
	x = l;
	int	i = 1;
	ll ans = B[1];
	while(x)
	{
		if(x == A[i + 1] + 1)
		{
			ans -= B[i + 1];
			break;
		}
		else if(x <= A[i + 1]) i ++;
		else ans -= B[i + 1] + a[i], x -= A[i + 1] + 1, i ++;
	}

	x = r;
	i = 1;
	while(x)
	{
		if(x == A[i + 1] + 1)
		{
			ans -= B[i + 1];
			break;
		}
		else if(x <= A[i + 1]) ans -= B[i + 1] + a[i], i ++;
		else x -= A[i + 1] + 1, i ++;
	}
	cout << ans;
	return	0;
}