#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll ps[maxn] , a[maxn] , n , k , fen[maxn];
pair<ll , ll> p[maxn];

int low(ll x , ll i)
{
	pair<ll , ll> b = {x , i};
	return lower_bound(p , p + n + 1 , b) - p;
}

int upp(ll x)
{
	pair<ll , ll> b = {x , maxn};
	return upper_bound(p , p + n + 1 , b) - p;
}

void update(ll p , ll val)
{
	for(p++; p < maxn; p += p & (-p))
		fen[p] += val;
}

ll get(ll p)
{
	ll res = 0;
	for(p++; p > 0; p -= p & (-p))
		res += fen[p];
	return res;
}

ll check(ll x)
{
	ll res = 0;
	fill(fen , fen + maxn , 0);
	update(low(0 , 0) , 1);
	for(int i = 1; i <= n; i++)
	{
		ll k = ps[i] - x;
		res += get(upp(k) - 1);
		update(low(ps[i] , i) , 1);
	}
	return res;
}

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i] , ps[i] = ps[i - 1] + a[i];
	for(int i = 0; i <= n; i++)
		p[i] = {ps[i] , i};
	sort(p , p + n + 1);
	ll l = -1e16 , r = 1e16;
	while(r - l > 1)
	{
		ll m = (r + l) / 2;
		if(check(m) >= k)
			l = m;
		else
			r = m;
	}
	cout << l << endl;
}