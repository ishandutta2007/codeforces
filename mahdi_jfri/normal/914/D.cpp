#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 5e5 + 20;

int a[maxn] , gcd[maxn * 4];

int fn(int l , int r , int x , int s , int e , int v)
{
	if(l <= s && e <= r && gcd[v] % x == 0)
		return -1;
	if(r <= s || e <= l)
		return -1;
	if(e - s < 2 && l <= s && e <= r)
		return s;
	int m = (s + e) / 2;
	int ans = fn(l , r , x , m , e , 2 * v + 1);
	if(ans == -1)
		ans = fn(l , r , x , s , m , 2 * v);
	return ans;
}

int get(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return gcd[v];
	if(r <= s || e <= l)
		return 0;
	int m = (s + e) / 2;
	
	return __gcd(get(l , r , s , m , 2 * v) , get(l , r , m , e , 2 * v + 1));
}

void change(int p , int s , int e , int v)
{
	if(e - s < 2)
	{
		gcd[v] = a[p];
		return;
	}
	int m = (s + e) / 2;
	if(p < m)
		change(p , s , m , 2 * v);
	else
		change(p , m , e , 2 * v + 1);

	gcd[v] = __gcd(gcd[2 * v] , gcd[2 * v + 1]);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]) , change(i , 0 , n , 1);
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int type;
		scanf("%d", &type);
		if(type == 1)
		{
			int l , r , x;
			scanf("%d%d%d", &l, &r, &x);
			l--;
			int k = fn(l , r , x , 0 , n , 1);
			if(k == -1 || k == l || get(l , k , 0 , n , 1) % x == 0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			int p , x;
			scanf("%d%d", &p, &x);
			p--;
			a[p] = x;
			change(p , 0 , n , 1);
		}
	}
}