#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

ll AddLazy[maxn * 8] , mx[maxn * 8];
int a[maxn];

inline void shift(int v)
{
	AddLazy[2 * v] += AddLazy[v];
	AddLazy[2 * v + 1] += AddLazy[v];

	mx[2 * v] += AddLazy[v];
	mx[2 * v + 1] += AddLazy[v];

	AddLazy[v] = 0;
}

inline void add(int l , int r , ll val , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		AddLazy[v] += val;
		mx[v] += val;

		return;
	}

	if(r <= s || e <= l)
		return;

	int m = (s + e) / 2;

	shift(v);

	add(l , r , val , s , m , 2 * v);
	add(l , r , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

inline int dfs(int s , int e , int v)
{
	if(mx[v] < 0)
		return -1;

	if(e - s < 2)
	{
		if(mx[v] == 0)
			return s + 1;
		else
			return -1;
	}

	shift(v);

	int m = (s + e) / 2;
	int res = dfs(s , m , 2 * v);

	if(res == -1)
		return dfs(m , e , 2 * v + 1);
	else
		return res;
}

int main()
{
	int n , q;
	scanf("%d%d", &n,&q);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		add(i , i + 1 , a[i] , 0 , n , 1);
		add(i + 1 , n ,-a[i] , 0 , n , 1);
	}

	while(q--)
	{
		int p , x;
		scanf("%d%d", &p, &x);
		p--;

		add(p , p + 1 , x - a[p] , 0 , n , 1);
		add(p + 1 , n , a[p] - x , 0 , n , 1);
		a[p] = x;

		printf("%d\n" , dfs(0 , n , 1));
	}

}