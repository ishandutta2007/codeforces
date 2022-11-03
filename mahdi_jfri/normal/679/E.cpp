#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const int shit = 42;

struct node
{
	ll mx , mn , lazy , ladd , mn_diff;
	node()
	{
		mx = 0;
		mn = 1e16;
		lazy = -1;
		ladd = 0;
		mn_diff = 1e16;
	}
};

ll a[maxn] , tmpval , tmpnex , tmpaddval;

node seg[maxn * 4] , void_node;

vector<ll> bads;

inline node merge(node a , node b)
{
	node c;
	c.mx = max(a.mx , b.mx);
	c.mn = min(a.mn , b.mn);
	c.mn_diff = min(a.mn_diff , b.mn_diff);
	return c;
}

inline ll get_next(ll x)
{
	return *lower_bound(bads.begin() , bads.end() , x);
}

inline void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		seg[v].mx = seg[v].mn = a[s];
		seg[v].mn_diff = get_next(a[s]) - a[s];
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

inline void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		if(seg[v].lazy != -1)
		{
			seg[2 * v].ladd = seg[2 * v + 1].ladd = seg[v].ladd;

			seg[2 * v].lazy = seg[2 * v + 1].lazy = seg[v].lazy;

			seg[2 * v].mn = seg[2 * v].mx = seg[2 * v + 1].mx = seg[2 * v + 1].mn = seg[v].ladd + seg[v].lazy;

			seg[2 * v].mn_diff = seg[2 * v + 1].mn_diff = seg[v].mn_diff;
		}
		else if(seg[v].ladd)
		{
			seg[2 * v].ladd += seg[v].ladd;
			seg[2 * v + 1].ladd += seg[v].ladd;

			seg[2 * v].mn += seg[v].ladd;
			seg[2 * v + 1].mn += seg[v].ladd;

			seg[2 * v].mx += seg[v].ladd;
			seg[2 * v + 1].mx += seg[v].ladd;
			if(seg[v].mx == seg[v].mn)
				seg[2 * v].mn_diff = seg[2 * v + 1].mn_diff = seg[v].mn_diff;
			else
			{
				seg[2 * v].mn_diff -= seg[v].ladd;
				seg[2 * v + 1].mn_diff -= seg[v].ladd;

			}
		}
	}
	seg[v].ladd = 0;
	seg[v].lazy = -1;
}

inline node get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return seg[v];
	if(r <= s || e <= l)
		return void_node;
	shift(s , e , v);
	int m = (s + e) / 2;
	return merge(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

inline void add(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		if(seg[v].mn_diff >= tmpaddval)
		{
			seg[v].ladd += tmpaddval;
			seg[v].mn += tmpaddval;
			seg[v].mx += tmpaddval;
			seg[v].mn_diff -= tmpaddval;
			return;
		}
		else if(seg[v].mx == seg[v].mn)
		{
			seg[v].ladd += tmpaddval;
			seg[v].mn += tmpaddval;
			seg[v].mx += tmpaddval;
			ll nex = get_next(seg[v].mx);
			seg[v].mn_diff = nex - seg[v].mx;
			return;
		}
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	add(l , r , s , m , 2 * v);
	add(l , r , m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

inline void st(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		seg[v].lazy = tmpval;
		seg[v].ladd = 0;
		seg[v].mx = seg[v].mn = tmpval;
		seg[v].mn_diff = tmpnex - tmpval;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	st(l , r , s , m , 2 * v);
	st(l , r , m , e , 2 * v + 1);
	seg[v] = merge(seg[2 * v] , seg[2 * v + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll p = 1;
	while(p < 1e17)
		bads.pb(p) , p *= shit;
	int n , q;
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build(0 , n , 1);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int pos;
			cin >> pos;
			pos--;
			node x = get(pos , pos + 1 , 0 , n , 1);
			cout << x.mx << endl;
		}
		else if(type == 2)
		{
			ll l , r , x;
			cin >> l >> r >> x;
			l--;
			tmpnex = get_next(x);
			tmpval = x;
			st(l , r , 0 , n , 1);
		}
		else
		{
			ll l , r , x;
			cin >> l >> r >> x;
			l--;
			tmpaddval = x;
			add(l , r , 0 , n , 1);
			while(get(l , r , 0 , n , 1).mn_diff == 0)
				add(l , r , 0 , n , 1);
		}
	}
}