#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;

ll sum[maxn * 4] , mx[maxn * 4] , mn[maxn * 4] , lazy[maxn * 4] , add[maxn * 4];

void build(int s , int e , int v)
{
	lazy[v] = -1;
	if(e - s < 2)
	{
		mx[v] = s + 1;
		mn[v] = s + 1;
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

void shift(int s , int e , int v)
{
	if(e - s >= 2 && lazy[v] != -1)
	{
		int m = (s + e) / 2;
		lazy[2 * v] = lazy[v];
		sum[2 * v] += add[v] * (m - s);
		add[2 * v] += add[v];
		lazy[2 * v + 1] = lazy[v];
		sum[2 * v + 1] += add[v] * (e - m);
		add[2 * v + 1] += add[v];
		mx[2 * v] = mn[2 * v] = mx[2 * v + 1] = mn[2 * v + 1] = lazy[v];
	}
	lazy[v] = -1;
	add[v] = 0;
}

void update(int l , int r , int val , int s , int e , int v)
{
	shift(s , e , v);
	if(l <= s && e <= r && mx[v] == mn[v])
	{
		lazy[v] = val;
		sum[v] += (e - s) * abs(val - mx[v]);
		add[v] += abs(val - mx[v]);
		mx[v] = mn[v] = val;
		return;
	}
	if(r <= s || e <= l)
		return;
	int m = (s + e) / 2;
	update(l , r , val , s , m , 2 * v);
	update(l , r , val , m , e , 2 * v + 1);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	mn[v] = min(mn[2 * v] , mn[2 * v + 1]);
}

ll get(int l , int r , int s , int e , int v)
{
	shift(s , e , v);
	if(l <= s && e <= r)
		return sum[v];
	if(r <= s || e <= l)
		return 0;
	int m = (s + e) / 2;
	return get(l , r , s , m , 2 * v) + get(l , r , m , e , 2 * v + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n , q;
	cin >> n >> q;
	build(0 , n , 1);
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int l , r , x;
			cin >> l >> r >> x;
			l--;
			update(l , r , x , 0 , n , 1);
		}
		else
		{
			int l , r;
			cin >> l >> r;
			l--;
			cout << get(l , r , 0 , n , 1) << endl;
		}
	}
}