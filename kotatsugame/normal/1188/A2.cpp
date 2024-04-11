#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<pair<pair<int,int>,int> >E,ans;
vector<int>G[1000];
int dfs(int u,int p,int x)
{
	if(u==x)return -1;
	if(G[u].size()==1)
	{
		return u;
	}
	int ans=N;
	for(int v:G[u])
	{
		if(v!=p)ans=min(ans,dfs(v,u,x));
	}
	return ans;
}
void add(int u,int v,int x)
{
	if(G[u].size()==1&&G[v].size()==1)
	{
		ans.push_back(make_pair(make_pair(u,v),x));
		return;
	}
	int iu1=-1,iu2=-1;
	if(G[v].size()!=1)swap(u,v);
	for(int w:G[u])
	{
		int now=dfs(w,u,v);
		if(now>=0)iu2=iu1,iu1=now;
		if(iu2>=0)break;
	}
	if(G[v].size()==1)
	{
		ans.push_back(make_pair(make_pair(iu1,v),x/2));
		ans.push_back(make_pair(make_pair(iu2,v),x/2));
		ans.push_back(make_pair(make_pair(iu1,iu2),-x/2));
	}
	else
	{
		add(v,iu1,x);
		add(u,iu1,-x);
	}
}
main()
{
	scanf("%d",&N);
	for(int i=1;i<N;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		E.push_back(make_pair(make_pair(a,b),c));
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<N;i++)
	{
		if(G[i].size()==2)
		{
			puts("NO");
			return 0;
		}
	}
	for(pair<pair<int,int>,int>p:E)
	{
		add(p.first.first,p.first.second,p.second);
	}
	puts("YES");
	printf("%d\n",(int)ans.size());
	for(pair<pair<int,int>,int>p:ans)printf("%d %d %d\n",p.first.first+1,p.first.second+1,p.second);
}