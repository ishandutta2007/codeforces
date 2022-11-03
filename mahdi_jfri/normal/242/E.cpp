#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
#define int ll
const int maxn = 1e5 + 20;
const int maxb = 30;


ll t[maxn * 4][maxb] , lazy[maxn * 4] , a[maxn];

void shift(int s , int e , int v)
{
	if(lazy[v] && e - s >= 2)
	{
		int m = (s + e) / 2;
		for(int i = 0; i < maxb; i++)
			if(bit(lazy[v] , i))
			{
				t[2 * v][i] = m - s - t[2 * v][i];
				t[2 * v + 1][i] = e - m - t[2 * v + 1][i];
			}
		lazy[2 * v] ^= lazy[v];
		lazy[2 * v + 1] ^= lazy[v];
		lazy[v] = 0;
	}
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		for(int i = 0; i < maxb; i++)
			t[v][i] = bit(a[s] , i);
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	for(int i = 0; i < maxb; i++)
		t[v][i] = t[2 * v][i] + t[2 * v + 1][i];
}

void update(int l , int r , int val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		for(int i = 0; i < maxb; i++)
			if(bit(val , i))
				t[v][i] = e - s - t[v][i];
		lazy[v] ^= val;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);
	for(int i = 0; i < maxb; i++)
		t[v][i] = t[2 * v][i] + t[2 * v + 1][i];
}

ll get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		ll res = 0;
		for(int i = 0; i < maxb; i++)
			res += t[v][i] * (1LL << i);
		return res;
	}
	if(r <= s || e <= l)
		return 0;
	shift(s , e , v);
	int m = (s + e) / 2;
	return (ll)get(l , r , s , m , 2 * v) + (ll)get(l , r , m , e , 2 * v + 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build(0 , n , 1);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			int l , r;
			cin >> l >> r;
			cout << get(l - 1 , r , 0 , n , 1) << endl;
		}
		else
		{
			int l , r , x;
			cin >> l >> r >> x;
			update(l - 1 , r , x , 0 , n , 1);
		}
	}
}