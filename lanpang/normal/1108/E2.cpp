#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , m , len , tp , h , ans , pi , ma;
int a[maxn] , p[maxn] , b[610] , c[610] , bf[610] , ff[310];
map<int,int> mp;
struct mmp{
	int l , r;
}f[310];

void ins(int x , int y)
{
	c[++tp] = 1000000;
	for (int i = x ; i <= y ; i++)
	{
		c[tp] = min(c[tp],a[i]);
		p[i] = tp;
	}
}

int main()
{
	int i , j , t;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (i = 1 ; i <= m ; i++)
	{
		cin >> f[i].l >> f[i].r;
		mp[f[i].l] = 1;
		mp[f[i].r+1] = 1;
	}
	for (auto i: mp)
	{ 
		mp[i.first] = ++len;
		b[len] = i.first;
	} 
	if (b[1] > 1) 
	{
		ins(1,b[1]-1);
		t = 1;
	}
	else t = 0;
	for (i = 1 ; i < len ; i++)
		ins(b[i],b[i+1]-1);
	b[0] = 1;
	if (b[len] <= n) ins(b[len],n);
	for (i = 1 ; i <= m ; i++)
	{
		f[i].l = mp[f[i].l]+t;
		f[i].r = mp[f[i].r+1]-1+t;
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= tp ; j++)
			bf[j] = 0;
		for (j = 1 ; j <= m ; j++)
		{
			if (f[j].l > p[i] || p[i] > f[j].r)
			{
				bf[f[j].l]--;
				bf[f[j].r+1]++;
			}
		}	
		ma = a[i]-c[p[i]];	
		for (j = 1 ; j <= tp ; j++)
		{
			bf[j] += bf[j-1];
			if (j != p[i]) ma = max(ma,a[i]-c[j]-bf[j]);
		}
		if (ans < ma)
		{
			ans = ma;
			pi = p[i];
		}
	}
	cout << ans << "\n";
	for (i = 1 ; i <= m ; i++)
		if (f[i].l > pi || pi > f[i].r) ff[++h] = i;
	cout << h << "\n";
	for (i = 1 ; i <= h ; i++)
		cout << ff[i] << " ";
	cout << "\n";
	return 0;
}