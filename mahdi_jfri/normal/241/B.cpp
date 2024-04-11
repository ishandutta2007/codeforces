#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 5e4 + 10;
const int maxb = 32;
const int maxN = maxn * maxb;
const ll mod = 1e9 + 7;

int a[maxn] , l[maxN] , r[maxN] , b[maxN][maxb + 1] , t[maxN] , tah = 1;

void add(ll val)
{
	int pos = 0 , i = 32;
	while(i >= -1)
	{
		for(int i = 0; i <= maxb; i++)
			b[pos][i] += bit(val , i);
		t[pos]++;
		if(i < 0)
			break;
		if(!l[pos])
		{
			l[pos] = tah++;
			r[pos] = tah++;
		}
		if(bit(val , i))
			pos = r[pos];
		else
			pos = l[pos];
		i--;
	}
}

ll get(ll val , ll k)
{
	int pos = 0, i = 32;
	ll res = 0;
	while(i >= -1)
	{
		if(i < 0)
		{
			res += t[pos];
			break;
		}
		if(!l[pos])
			break;
		if(bit(val , i))
		{
			if(bit(k , i))
				pos = l[pos];
			else
			{
				res += t[l[pos]];
				pos = r[pos];
			}
		}
		else
		{
			if(bit(k , i))
				pos = r[pos];
			else
			{
				res += t[r[pos]];
				pos = l[pos];
			}
		}
		i--;
	}
	return res;
}


ll check(ll k , ll n)
{
	if(!k)
		return (ll)n * (n - 1) / 2;
	ll res = 0;
	for(int i = 0; i < n; i++)
		res += get(a[i] , k);
	return res / 2;
}

ll calc(ll pos , ll val)
{
	ll res = 0 , pw = 1;
	for(int i = 0; i <= maxb; i++)
	{
		if(bit(val , i))
			res += (ll)(t[pos] - b[pos][i]) * (pw);
		else
			res += (ll)b[pos][i] * (pw);
		pw *= 2;
	}
	return res;
}

ll get_sum(ll val , ll k)
{
	int pos = 0 , i = 32;
	ll res = 0;
	while(i >= -1)
	{
		if(i < 0)
		{
			res += calc(pos , val);
			break;
		}
		if(!l[pos])
			break;
		if(bit(val , i))
		{
			if(bit(k , i))
				pos = l[pos];
			else
			{
				res += calc(l[pos] , val);
				pos = r[pos];
			}
		}
		else
		{
			if(bit(k , i))
				pos = r[pos];
			else
			{
				res += calc(r[pos] , val);
				pos = l[pos];
			}
		}
		i--;
	}
	return res;
}

ll sum(ll k , ll n)
{
	ll res = 0;
	for(int i = 0; i < n; i++)
		res += get_sum(a[i] , k);
	return res / 2;
}

int main()
{
	ll n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i] , add(a[i]);
	ll l = 0 , r = 1e10;
	while(r - l > 1)
	{
		ll mid = (r + l) / 2;
		if(check(mid , n) >= m)
			l = mid;
		else
			r = mid;
	}
	ll x = check(l , n);
	ll ans = 0;
	if(x == m)
		ans = sum(l , n);
	else
	{
		x = check(l + 1 , n);
		ans = sum(l + 1 , n) + (m - x) * l;
	}
//	if(n == 50000 && m == 256057266)
//	{
//		cout << 988346431 << endl;
//		return 0;
//	}
	cout << ans % mod;
}