#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
map<int,int> mp;
vector<pair<int,int> > g[555555];
int n,an[555555][22],sum[555555][22],tp,lans,l,r,x,pa[555555],sz[555555],cnt,dep[555555];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;
	sz[ry]+=sz[rx];
}
void dfs(int i,int fa,int vl)
{
	an[i][0]=fa;sum[i][0]=vl;dep[i]=dep[fa]+1;
	for (int j=1;j<=19;j++)
	{
		an[i][j]=an[an[i][j-1]][j-1];
		sum[i][j]=sum[i][j-1]^sum[an[i][j-1]][j-1];
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i,val);
	}
}
int lca(int a,int b)
{
	if (dep[a]<dep[b]) swap(a,b);
	int res=0;
	for (int i=19;i>=0;i--)
	{
		if (dep[an[a][i]]<=dep[b]) 
		{
			res^=sum[a][i];
			a=an[a][i];
		}
	}
	for (int i=19;i>=0;i--)
	{
		if (an[a][i]!=an[b][i])
		{
			res^=sum[a][i];res^=sum[b][i];
			a=an[a][i];b=an[b][i];
		}
	}
	if (a==b) return res;
	res^=sum[a][0];res^=sum[b][0];
	return res;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&tp);
		if (tp==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			l^=lans;r^=lans;x^=lans;
			if (l>r) swap(l,r);
			l--;
			if (mp.find(l)==mp.end()) 
			{
				mp[l]=++cnt;
				pa[cnt]=cnt;
				sz[cnt]=1;dep[cnt]=1;
			}
			if (mp.find(r)==mp.end()) 
			{
				mp[r]=++cnt;
				pa[cnt]=cnt;
				sz[cnt]=1;dep[cnt]=1;
			}
			l=mp[l];r=mp[r];
			int ra=root(l),rb=root(r);
			if (ra==rb) continue;
			g[l].push_back(make_pair(r,x));
			g[r].push_back(make_pair(l,x));  
			if (sz[ra]<sz[rb]) dfs(l,r,x);
			else dfs(r,l,x);
			Union(l,r);
		}
		else
		{
			scanf("%d%d",&l,&r);
			l^=lans;r^=lans;
			if (l>r) swap(l,r);
			l--;
			if (mp.find(l)==mp.end() || mp.find(r)==mp.end())
			{
				printf("-1\n");
				lans=1;
				continue;
			}
			l=mp[l];r=mp[r];
			int ra=root(l),rb=root(r);
			if (ra!=rb) 
			{
				printf("-1\n");
				lans=1;
				continue;
			}
			lans=lca(l,r);
			printf("%d\n",lans);
		}
	}
	return 0;
}