#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,k,x,y,in[111111],pa[111111][18],dep[111111],num,r,cur,p,ans;
vector<int> g[111111];
set<pair<int,int> > s;
void dfs(int i,int fa,int d)
{
	dep[i]=d;
	pa[i][0]=fa;
	for (int j=1;j<=17;j++)
	{
		pa[i][j]=pa[pa[i][j-1]][j-1];
	}
	in[i]=++num;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,d+1);
	}
}
int lca(int x,int y)
{
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
	{
		if (dep[y]-pow(2,i)>=dep[x]) y=pa[y][i];
	}
	for (int i=17;i>=0;i--)
	{
		if (pa[x][i]!=pa[y][i])
		{
			x=pa[x][i];
			y=pa[y][i];
		}
	}
	if (x!=y) x=pa[x][0];
	return x;
}
int count(int i)
{
	int res=1e9;
	if (s.empty()) return 1;
	int root=lca(s.begin()->second,s.rbegin()->second);
	if (lca(i,root)==i) return dep[root]-dep[i];
	if (lca(i,root)!=root) return dep[i]+dep[root]-dep[lca(i,root)]*2;
	set<pair<int,int> >::iterator it=s.lower_bound(make_pair(in[i],i));
	if (it!=s.end())
	{
		if (lca(it->second,i)==i) return 0;
		res=dep[i]-dep[lca(i,it->second)];
	}
	if (it!=s.begin())
	{
		it--;
		res=min(res,dep[i]-dep[lca(i,it->second)]);
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0,0);
	r=1;
	for (int i=1;i<=n;i++)
	{
		while(1)
		{
			if (r>n) break;
			p=count(r);
			if (cur+p<=k)
			{
				cur+=p;
				s.insert(make_pair(in[r],r));
				r++;
			}
			else break;
		}
		ans=max(ans,r-i);
		s.erase(s.find(make_pair(in[i],i)));
		p=count(i);
		cur-=p;
	}
	printf("%d\n",ans);
	return 0;
}