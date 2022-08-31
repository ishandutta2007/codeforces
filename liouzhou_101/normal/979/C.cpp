#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <cstring>
#include <queue>
#include <ctime>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

const int INF = 2*1e9;
const int maxN = 300010;
const int maxM = 200010;
const int maxK = 19;
ll n;
int flwr,bee;
vector<int> mp[maxN];
int deep[maxN];
int kid[maxN];
int pre[maxN][maxK];
void init()
{
	for(int i=1;i<=n;i++)
	{
		kid[i] = 1;
	}
}
void build(int x,int p)
{
	for(int i = 0;i<mp[x].size();i++)
	{
		int y = mp[x][i];
		if(y==p)continue;
		deep[y] = deep[x]+1;
		pre[y][0] = x;
		build(y,x);
		kid[x] += kid[y];
	}
}
int getLCA(int x,int y)        // 
{
	if(deep[x] < deep[y]) swap(x,y);
	for(int i=maxK-1;i>=0;i--)
	{
		if(deep[x] - deep[y] >= 1<<i)
		{
			x = pre[x][i];
		}
	}
	if(x == y)
		return x;
	
	for(int i=maxK-1;i>=0;i--)
	{
		if(pre[x][i] != pre[y][i])
		{
			x = pre[x][i];
			y = pre[y][i];
		}	
	}
	return pre[x][0];	
}
int main()
{
	scanf("%I64d %d %d",&n,&flwr,&bee);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	init(); 
	build(1,0);
	for(int k=1;k<=maxK-1;k++)
	{
		for(int i=1;i<=n;i++)
		{
			pre[i][k] = pre[pre[i][k-1]][k-1];
		}
	} 
	ll ans = 0;
	int fa = getLCA(flwr,bee);
	if(fa != flwr && fa != bee)
	{
		ans = n*(n-1)-((ll)kid[flwr] * (ll)kid[bee]);
	}
	else
	{
		if(deep[flwr] > deep[bee])
			swap(flwr,bee);
		ll bsum = (ll)kid[bee];
		ll fsum = 1;
		for(int i=0;i<mp[flwr].size();i++)
		{
			int y = mp[flwr][i];
			if(y == pre[flwr][0]) continue;
			if(y == getLCA(y,bee)) 
			{
				fsum = n - kid[y];
				break;
			}
			
		}
		ans = n*(n-1) - (fsum*bsum);
	}
	printf("%I64d\n",ans);
	return 0;
}