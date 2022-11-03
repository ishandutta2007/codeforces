#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz second.second
#define odd first.first
#define even first.second
#define ssum second.first
typedef pair<pair<ll , ll> , pair<ll , ll> > shit;
const int maxn = 2e5 + 20;
const ll inf = 1e17;

ll a[maxn] , sum[maxn * 4] , mn_odd[maxn * 4] , mn_even[maxn * 4] , lazy[maxn * 4];

shit merge(shit a , shit b)
{
	shit c;
	if(!a.sz)
		return b;
	if(!b.sz)
		return a;
	if(a.sz % 2)
		c.ssum = a.ssum - b.ssum;
	else
		c.ssum = a.ssum + b.ssum;
	if(b.sz % 2)
	{
		c.odd = min(b.odd , a.even - b.ssum);
		c.even = min(b.even , a.odd + b.ssum);
	}
	else
	{
		c.even = min(a.even - b.ssum , b.even);
		c.odd = min(a.odd + b.ssum , b.odd);
	}
	c.sz = a.sz + b.sz;
	return c;
}

shit f(int s , int e , int v)
{
	return {{mn_odd[v] , mn_even[v]} , {sum[v] , e - s}};
}

void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		sum[v] = a[s];
		mn_even[v] = a[s];
		mn_odd[v] = inf;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	shit x = merge(f(s , m , 2 * v) , f(m , e , 2 * v + 1));
	mn_odd[v] = x.odd;
	mn_even[v] = x.even;
	sum[v] = x.ssum;
}

void shift(int s , int e , int v)
{
	if(e - s > 1 && lazy[v])
	{
		int m = (s + e) / 2;
		lazy[2 * v] += lazy[v];
		sum[2 * v] += lazy[v] * ((m - s) % 2);
		mn_even[2 * v] += lazy[v];
		lazy[2 * v + 1] += lazy[v];
		sum[2 * v + 1] += lazy[v] * ((e - m) % 2);
		mn_even[2 * v + 1] += lazy[v];
	}
	lazy[v] = 0;
}

void update(int l , int r , ll val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		lazy[v] += val;
		sum[v] += val * ((e - s) % 2);
		mn_even[v] += val;
		return;
	}
	if(r <= s || e <= l)
		return;
	shift(s , e , v);
	int m = (s + e) / 2;
	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);
	shit x = merge(f(s , m , 2 * v) , f(m , e , 2 * v + 1));
	mn_odd[v] = x.odd;
	mn_even[v] = x.even;
	sum[v] = x.ssum;
}

shit get(int l , int r , int s , int e , int v) // {{mn_odd , mn_even} , {sum , sz}};
{
	if(l <= s && e <= r)
		return {{mn_odd[v] , mn_even[v]} , {sum[v] , e - s}};
	if(r <= s || e <= l)
		return {{inf , inf} , {0 , 0}};
	shift(s , e , v);
	int m = (s + e) / 2;
	shit a = get(l , r , s , m , 2 * v);
	shit b = get(l , r , m , e , 2 * v + 1);
	return merge(a , b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , a[i]--;
	build(0 , n , 1);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			int l , r , k;
			cin >> l >> r >> k;
			r++;
			update(l , r , k , 0 , n , 1);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			r++;
			shit ans = get(l , r , 0 , n , 1);
	//		cout << ans.odd << " " << ans.even << " " << ans.ssum << " " << ans.sz << endl;
			if(min(ans.odd , ans.even) >= 0 && ans.ssum + 1 == 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
}