#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define div Wtfc
const int maxn = 1e6 + 20;
const int maxd = 1e4 + 20;

ll a[maxn] , div[maxn] , sz;

int t[maxd] , tmp[maxd] , n;

ll solve(ll k)
{
	sz = 0;
	for(ll i = 1; i * i <= k; i++)
		if(k % i == 0)
		{
			div[sz] = i;
			sz++;
			if(k / i != i)
			{
				div[sz] = k / i;
				sz++;
			}
		}
	sort(div , div + sz);
	memset(t , 0 , sizeof t);
	memset(tmp , 0 , sizeof tmp);
	for(int i = 0; i < n; i++)
	{
		int x = lower_bound(div , div + sz , __gcd(a[i] , k)) - div;
		t[x]++;
	}
	for(int i = sz - 1; i >= 0; i--)
	{
		if(t[i] + tmp[i] >= (n + 1) / 2)
			return div[i];
		if(t[i])
			for(int j = 0; j < i; j++)
				if(div[i] % div[j] == 0)
					tmp[j] += t[i];
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	srand(time(NULL));
	ll ans = 1;
	for(int i = 0; i < 11; i++)
	{
		int k = ((ll)rand() * rand() + rand()) % n;
		ans = max(ans , solve(a[k]));
	}
	cout << ans << endl;
}