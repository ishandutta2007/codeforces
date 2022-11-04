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
const int maxn = 5e5+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , q , mi[maxn] , ma[maxn] , tp , leaf[maxn];
LL dis[maxn] , ans[maxn] , tr[maxn*4] , bf[maxn*4];
vector<int> v[maxn] , w[maxn];
struct mmp{
	int l , r , id;
}p;
vector<mmp> h[maxn];

void putin(int num , int l , int r , int x , int y , LL z)
{
	if (l > y || x > r) return;
	if (x <= l && r <= y)
	{
		bf[num] += z;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y,z);
	putin(num*2+1,(l+r)/2+1,r,x,y,z);
	tr[num] = min(tr[num*2]+bf[num*2],tr[num*2+1]+bf[num*2+1]);
}

LL getout(int num , int l , int r , int x , int y)
{
	if (l > y || x > r) return mod*mod;
	if (x <= l && r <= y) return tr[num]+bf[num];
	return bf[num]+min(getout(num*2,l,(l+r)/2,x,y),getout(num*2+1,(l+r)/2+1,r,x,y));
}

void dfs(int x)
{
	if (v[x].size() == 0)
	{
		leaf[++tp] = x; 
		mi[x] = tp;
		ma[x] = tp;
		return;
	}
	int sz = tp;
	for (int i = 0 ; i < v[x].size() ; i++)
	{
		int t = v[x][i];
		dis[t] = dis[x]+w[x][i];
		dfs(t);
	}
	mi[x] = sz+1;
	ma[x] = tp;
}

void dfs1(int x)
{
	for (auto i: h[x])
	{
		int l = lower_bound(leaf+1,leaf+tp+1,i.l)-leaf;
		int r = upper_bound(leaf+1,leaf+tp+1,i.r)-leaf-1;
		ans[i.id] = getout(1,1,tp,l,r);
	}
	for (int i = 0 ; i < v[x].size() ; i++)
	{
		int t = v[x][i];
		putin(1,1,tp,1,mi[t]-1,w[x][i]);
		putin(1,1,tp,mi[t],ma[t],-w[x][i]);
		putin(1,1,tp,ma[t]+1,tp,w[x][i]);
		dfs1(v[x][i]);
		putin(1,1,tp,1,mi[t]-1,-w[x][i]);
		putin(1,1,tp,mi[t],ma[t],w[x][i]);
		putin(1,1,tp,ma[t]+1,tp,-w[x][i]);
	}
}

int main()
{
	int i , j , x , y;
	cin >> n >> q;
	for (i = 2 ; i <= n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(i);
		w[x].push_back(y);
	}
	dfs(1);
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d",&x,&p.l,&p.r);
		p.id = i;
		h[x].push_back(p);
	}
	for (i = 1 ; i <= tp ; i++)
		putin(1,1,tp,i,i,dis[leaf[i]]);
	dfs1(1);
	for (i = 1 ; i <= q ; i++)
		printf("%I64d\n",ans[i]);
	return 0;
}