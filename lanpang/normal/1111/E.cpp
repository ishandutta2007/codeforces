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

int n , q , dp[maxn][310] , ans;
int fa[maxn] , d[maxn] , mi[maxn] , ma[maxn];
int p2[20] , f2[maxn*4] , rmq[maxn*4][20];
int tr[maxn*16] , tp;
vector<int> v[maxn];
struct mmp{
	int x , y;
	bool operator < (const mmp &op) const{
		return y < op.y;
	}
}a[maxn];

void dfs(int x , int y)
{
	fa[x] = y;
	d[x] = d[y]+1;
	rmq[++tp][0] = x;
	mi[x] = ma[x] = tp;
	for (auto i: v[x])
	{
		if (i != y) 
		{
			dfs(i,x);
			rmq[++tp][0] = x;
			ma[x] = tp;
		}
	}
}

void rmq_build()
{
	for (int i = 2 ; i <= tp ; i++)
		f2[i] = f2[i/2]+1;
	p2[0] = 1;
	for (int i = 1 ; i <= f2[tp] ; i++)
		p2[i] = p2[i-1]*2;
	for (int i = 1 ; i <= f2[tp] ; i++)
	{
		for (int j = 1 ; j+p2[i]-1 <= tp ; j++)
		{
			if (d[rmq[j][i-1]] < d[rmq[j+p2[i-1]][i-1]]) rmq[j][i] = rmq[j][i-1];
			else rmq[j][i] = rmq[j+p2[i-1]][i-1];
		}
	}
}

int rmq_query(int l , int r)
{
	if (l > r) swap(l,r);
	int x = rmq[l][f2[r-l+1]] , y = rmq[r-p2[f2[r-l+1]]+1][f2[r-l+1]];
	if (d[x] < d[y]) return x;
	else return y;
}

void putin(int num , int l , int r , int x , int y)
{
	if (x > r || x < l) return;
	if (l == r)
	{
		tr[num] += y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = tr[num*2]+tr[num*2+1];
}

int getout(int num , int l , int r , int x)
{
	if (x < l) return 0; 
	if (x >= r) return tr[num];
	return getout(num*2,l,(l+r)/2,x)+getout(num*2+1,(l+r)/2+1,r,x);
}

int main()
{
	int i , j , k , x , y , z , lca;
	cin >> n >> q;
	for (i = 1 ; i < n ; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	rmq_build();
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		for (j = 1 ; j <= x ; j++)
		{
			scanf("%d",&a[j].x);
			putin(1,1,tp,mi[a[j].x],1);
			putin(1,1,tp,ma[a[j].x]+1,-1);
		}
		for (j = 1 ; j <= x ; j++)
		{
			lca = rmq_query(mi[a[j].x],mi[z]);
			a[j].y = getout(1,1,tp,mi[a[j].x])+getout(1,1,tp,mi[z])-getout(1,1,tp,mi[lca])-getout(1,1,tp,mi[fa[lca]]);
		}
		sort(a+1,a+x+1);
		dp[0][0] = 1;
		for (j = 0 ; j < x ; j++)
		{
			for (k = 0 ; k < y ; k++) 
				dp[j+1][k+1] = dp[j][k];
			for (k = a[j+1].y ; k <= y ; k++)
				dp[j+1][k] = ((LL)dp[j+1][k]+(LL)dp[j][k]*(LL)(k-a[j+1].y+1))%mod;
		}
		ans = 0;
		for (k = 0 ; k <= y ; k++)
			ans = (ans+dp[x][k])%mod;
		printf("%d\n",ans);
		for (j = 1 ; j <= x ; j++)
		{
			putin(1,1,tp,mi[a[j].x],-1);
			putin(1,1,tp,ma[a[j].x]+1,1);
		}
	}
	return 0;
}