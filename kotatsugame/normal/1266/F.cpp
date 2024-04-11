#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N;
vector<pair<int,int> >G[5<<17];
pair<int,int>diameter_dfs(int u,int p)
{
	pair<int,int>ans(0,u);
	for(const pair<int,int>&e:G[u])
	{
		if(e.first!=p)
		{
			pair<int,int>q=diameter_dfs(e.first,u);
			q.first++;
			ans=max(ans,q);
		}
	}
	return ans;
}
int diameter()
{
	pair<int,int>p=diameter_dfs(0,-1);
	pair<int,int>q=diameter_dfs(p.second,-1);
	return q.first;
}
int maxv1[5<<17],maxv2[5<<17],max1[5<<17],max2[5<<17];
int dfs(int u,int p)
{
	for(pair<int,int>&v:G[u])
	{
		if(v.first==p)continue;
		int now=1+dfs(v.first,u);
		v.second=now;
		if(max1[u]<now)
		{
			max2[u]=max1[u];
			maxv2[u]=maxv1[u];
			max1[u]=now;
			maxv1[u]=v.first;
		}
		else if(max2[u]<now)
		{
			max2[u]=now;
			maxv2[u]=v.first;
		}
	}
	return max1[u];
}
void dfs2(int u,int p,int pv)
{
	pv++;
	if(max1[u]<pv)
	{
		max2[u]=max1[u];
		maxv2[u]=maxv1[u];
		max1[u]=pv;
		maxv1[u]=p;
	}
	else if(max2[u]<pv)
	{
		max2[u]=pv;
		maxv2[u]=p;
	}
	for(pair<int,int>&v:G[u])
	{
		if(v.first==p)
		{
			v.second=pv;
		}
		else
		{
			if(v.first==maxv1[u])dfs2(v.first,u,max2[u]);
			else dfs2(v.first,u,max1[u]);
		}
	}
}
vector<pair<int,int> >Es;
vector<pair<int,int> >EX[5<<17];
map<pair<int,int>,int>edge;
int ans[5<<17],ans2[5<<17];
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int u,v;scanf("%d%d",&u,&v);u--,v--;
		G[u].push_back(make_pair(v,-1));
		G[v].push_back(make_pair(u,-1));
		Es.push_back(make_pair(u,v));
	}
	dfs(0,-1);
	dfs2(0,-1,-1);
	int D=diameter();
	ans[N-1]=1;
	ans[D-1]=2;
	int ans1=2;
	for(int i=0;i<N;i++)
	{
		int now=G[i].size()+1;
		if(ans1<now)ans1=now;
	}
	ans[0]=ans1;
	for(int i=0;i<N;i++)
	{
		vector<int>es;
		for(pair<int,int>v:G[i])
		{
			es.push_back(v.second);
			edge[make_pair(i,v.first)]=v.second;
		}
		sort(es.begin(),es.end());
		vector<pair<int,int> >ex;
		for(int e:es)
		{
			if(ex.empty()||ex.back().first!=e)
			{
				ex.push_back(make_pair(e,1));
			}
			else ex.back().second++;
		}
		int cumsum=0;
		for(int j=ex.size();j--;)
		{
			int now=ex[j].first;
			int id=now*2;if(id>=N)id=N-1;
			ans[id]=max(ans[id],1+cumsum);
			if(id==now*2)id--;
			ans[id]=max(ans[id],cumsum+=ex[j].second);
		}
		EX[i]=ex;
	}
	for(pair<int,int>p:Es)
	{
		int u=p.first,v=p.second;
		int iu=EX[u].size()-1,iv=EX[v].size()-1;
		int cumsum=0;
		int X=edge[make_pair(u,v)],Y=edge[make_pair(v,u)];
		while(iu>=0||iv>=0)
		{
			int now;
			int U=iu<0?-114514:EX[u][iu].first;
			int V=iv<0?-114514:EX[v][iv].first;
			if(U<V)
			{
				now=V;
				cumsum+=EX[v][iv--].second;
				if(now==Y)cumsum--;
			}
			else if(U>V)
			{
				now=U;
				cumsum+=EX[u][iu--].second;
				if(now==X)cumsum--;
			}
			else
			{
				now=U;
				cumsum+=EX[u][iu--].second+EX[v][iv--].second;
				if(now==X)cumsum--;
				if(now==Y)cumsum--;
			}
			ans2[now-1]=max(ans2[now-1],cumsum);
		}
	}
	for(int i=N;i--;)
	{
		ans[i]=max(ans[i],ans[i+1]);
		ans2[i]=max(ans2[i],ans2[i+1]);
	}
	for(int i=1;i<=N;i++)
	{
		int nowans=ans[i-1];
		if(i%2==0)nowans=max(nowans,ans2[i/2-1]);
		printf("%d%c",nowans,i==N?'\n':' ');
	}
}