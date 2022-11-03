#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b)) & 1)
const int maxn = 1e5 + 20;
map<ll , ll> dp;
ll c(ll a)
{
	ll res = 0;
	for(ll i = 0; i < 64; i++)
		res += bit(a , i);
	return res;
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		ll l , r;
		cin >> l >> r;
		if(l == r && l == 0)
		{
			cout << 0 << endl;
			continue;
		}
		ll _min = 8e18 , f = 0;
		for(ll i = 63; i >= 0; i--)
		{
			if((1LL << (i)) - 1 > r)
				continue;
			ll k = i;
			ll x = 0;
			for(ll j = 63; j >= 0; j--)
			{
				if(bit(l , j))
				{
					x ^= (1LL << j);
					k--;
					if(!k && x >= l && x <= r)
					{
						i = -1;
						f = 0;
						cout << x << endl;
						break;
					}
				}
				else
				{
					ll nx = x;
					x ^= (1LL << j);
					for(ll z = 0; z < k - 1; z++)
						x ^= (1LL << z);
					if(x <= r && x >= l && k - 2 < j)
					{
					//	i = -1;
						if(f)
						{
							_min = min(_min , x);
							x = nx;
							continue;
						}
						f = 1;
						_min = x;
					}
					x = nx;
				}
			}
			if(f)
				cout << _min << endl , i = -1;
		}
	}
}