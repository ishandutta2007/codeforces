#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans = -1;
ll n, sum, x;
void calc(ll y)
{
	if(sum / y >= x) ans = max(ans,y);
}

int main()
{
	cin >> sum;
	cin >> n;
	x = 0;
	for(ll i = 1; i <= n; i ++) 
	{
		x += i;
		if(x > sum) 
		{
			cout << -1 << endl; 
			return 0;
		}
	}
	for(ll i = 1; i * i <= sum; i ++) 
		if(sum % i == 0) 
		{
			calc(i); 
			calc(sum / i);
		}
	if(ans == -1) cout << ans << endl;
	else 
	{
		ll s = 0;
		for(ll i = 1; i < n; i ++) printf("%I64d ",ans * i), s += ans * i;
		cout << sum - s << endl;
	}
	return 0;
}