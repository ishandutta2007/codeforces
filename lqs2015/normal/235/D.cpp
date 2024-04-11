#include<bits/stdc++.h>
using namespace std;
int n,x,y,pa[3333],rt[3333],dep[3333],dist[3333],len,pos[3333];
vector<int> g[3333],cycle;
bool used[3333],f,in_cycle[3333];
double ans,a,b,c,d;
void dfs(int i,int fa)
{
	used[i]=1;pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		if (used[to])
		{	
			if (f) continue;
			f=1;
			int cur=i;
			while(cur!=to)
			{
				cycle.push_back(cur);
				cur=pa[cur];
			}
			cycle.push_back(cur);
			continue;
		}
		dfs(to,i);
	}
}
void precalc(int i,int fa,int root,int depth)
{
	rt[i]=root;dep[i]=depth;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa || in_cycle[to]) continue;
		precalc(to,i,root,depth+1);
	}
}
void proc(int i,int fa,int depth,int pt)
{
	dist[i]=depth;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa || (in_cycle[to] && to!=pt)) continue;
		proc(to,i,depth+1,pt);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		x++;y++;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=0;i<cycle.size();i++) in_cycle[cycle[i]]=1;
	for (int i=0;i<cycle.size();i++)
	{
		pos[cycle[i]]=i;
	}
	for (int i=0;i<cycle.size();i++) 
	{
		precalc(cycle[i],0,cycle[i],0);
	}
	len=cycle.size();
	/*for (int i=0;i<cycle.size();i++) cout<<cycle[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++) cout<<pos[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++) cout<<rt[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++) cout<<dep[i]<<" ";
	cout<<endl;*/
	for (int i=1;i<=n;i++)
	{
		memset(dist,0,sizeof(dist));
		proc(i,0,0,rt[i]);
		for (int j=1;j<=n;j++)
		{
			if (rt[i]==rt[j]) 
			{
				ans+=1.00/(double)(dist[j]+1);
			}
			else
			{
				c=(double)dep[i];d=(double)dep[j];a=(double)abs(pos[rt[i]]-pos[rt[j]]);b=(double)(len-(int)a);
				ans+=(1.00/(a+c+d+1.00)+1.00/(b+c+d+1.00)-1.00/(a+b+c+d));
			}
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}