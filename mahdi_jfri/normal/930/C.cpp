#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn] , mx[maxn * 4] , dp[maxn];

void update(int p , int val , int s , int e , int v)
{
	if(e - s < 2)
	{
		mx[v] = val;
		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		update(p , val , s , m , 2 * v);
	else
		update(p , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

int get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return 0;

	int m = (s + e) / 2;

	return max(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;

	cin >> m >> n;

	for(int i = 0; i < m; i++)
	{
		int l , r;
		cin >> l >> r;
		l--;
		a[l]++ , a[r]--;
	}

	m++;

	for(int i = 1; i < n; i++)
		a[i] += a[i - 1];

	for(int i = 0; i < n; i++)
	{
		dp[i] = get(0 , a[i] + 1 , 0 , m , 1) + 1;
		update(a[i] , dp[i] , 0 , m , 1);
	}

	memset(mx , 0 , sizeof mx);

	int res = 0;

	for(int i = n - 1; i >= 0; i--)
	{
		res = max(res , get(0 , a[i] , 0 , m , 1) + dp[i]);

		int k = get(0 , a[i] + 1 , 0 , m , 1) + 1;
		update(a[i] , k , 0 , m , 1);
	}

	cout << res << endl;

}