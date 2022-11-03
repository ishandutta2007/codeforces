#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll mx[maxn * 4] , sum[maxn * 4] , node[maxn * 4] , a[maxn];
void build(int s , int e , int v)
{
	if(e - s < 2)
	{
		node[v] = s;
		mx[v] = a[s];
		sum[v] = a[s];
		return;
	}
	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	if(mx[v] == mx[2 * v])
		node[v] = node[2 * v];
	else
		node[v] = node[2 * v + 1];
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}
void update(int p , int value , int s , int e , int v)
{
	if(e - s < 2)
	{
		node[v] = s;
		mx[v] = value;
		sum[v] = value;
		return;
	}
	int m = (s + e) / 2;
	if(p < m)
		update(p , value , s , m , 2 * v);
	else
		update(p , value , m , e , 2 * v + 1);
	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
	if(mx[v] == mx[2 * v])
		node[v] = node[2 * v];
	else
		node[v] = node[2 * v + 1];
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}
int get_max(int l , int r , int s , int e , int v)
{
	if(s >= l && e <= r)
		return node[v];
	if(e <= l || r <= s)
		return maxn - 1;
	int m = (s + e) / 2;
	int x = get_max(l , r , s , m , 2 * v) , y = get_max(l , r , m , e , 2 * v + 1);
	return (a[x] > a[y]? x : y);
}
ll get_sum(int l , int r , int s , int e , int v)
{
	if(s >= l && e <= r)
		return sum[v];
	if(e <= l || r <= s)
		return 0;
	int m = (s + e) / 2;
	return get_sum(l , r , s , m , 2 * v) + get_sum(l , r , m , e , 2 * v + 1);
}
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	build(0 , n , 1);
	while(m--)
	{
		int a1;
		cin >> a1;
		if(a1 == 1)
		{
			int l , r;
			cin >> l >> r;
			l--;
			cout << get_sum(l , r , 0 , n , 1) << endl;
		}
		else if(a1 == 2)
		{
			int l , r , x;
			cin >> l >> r >> x;
			l--;
			while(a[get_max(l , r , 0 , n , 1)] >= x)
			{
				int ind = get_max(l , r , 0 , n , 1);
				a[ind] %= x;
				update(ind , a[ind] , 0 , n , 1);
			}
		}
		else if(a1 == 3)
		{
			int k , x;
			cin >> k >> x;
			k--;
			a[k] = x;
			update(k , x , 0 , n , 1);
		}
	}
}