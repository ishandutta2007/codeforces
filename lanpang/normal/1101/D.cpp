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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , a[maxn] , f[maxn] , dis , poi , ans;
vector<int> v[maxn] , p[maxn] , q;

void dfs(int x , int d)
{
	f[x] = 1;
	q.push_back(x);
	if (d > dis)
	{
		dis = d;
		poi = x;
	}
	for (auto i: v[x])
	{
		if (f[i] == 1) continue;
		dfs(i,d+1);
	}
}

int main()
{
	int i , j , k , x , y;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		f[i] = 1;
		scanf("%d",&a[i]);
		x = sqrt(a[i]);
		for (j = 2 ; j <= x ; j++)
		{
			if ((a[i]%j) != 0) continue;
			p[j].push_back(i);
			while (a[i]%j == 0) a[i] /= j;
		}
		if (a[i] > 1) p[a[i]].push_back(i);
	}
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i = 2 ; i <= 200000 ; i++)
	{
 		if ((int)p[i].size() > ans)
		{
			for (auto j: p[i]) f[j] = 0;
			for (auto j: p[i])
			{
				if (f[j] == 1) continue;
				q.clear();
				dis = 0;
				dfs(j,1);
				for (auto k: q) f[k] = 0;
				dis = 0;
				dfs(poi,1);
				ans = max(ans,dis);
			}
		} 
	}
	cout << ans << "\n";
	return 0;
}