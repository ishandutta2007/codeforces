#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int>G[2<<17];
int pr[2<<17];
int dd(int s)
{
	vector<int>d(N,1e9);
	d[s]=0;
	pr[s]=-1;
	queue<int>P;P.push(s);
	int ans=s;
	while(!P.empty())
	{
		int u=P.front();P.pop();
		if(d[ans]<d[u])ans=u;
		for(int v:G[u])if(d[v]>d[u]+1)
		{
			d[v]=d[u]+1;
			pr[v]=u;
			P.push(v);
		}
	}
	return ans;
}
bool vis[2<<17];
vector<pair<int,int> >E;
long long ans;
void dfs(int u,int p,int d,int usd)
{
	for(int v:G[u])if(v!=p)dfs(v,u,d+1,usd);
	ans+=d;
	E.push_back(make_pair(usd,u));
}
main()
{
	cin>>N;
	for(int i=1;i<N;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int U=dd(dd(0));
	vector<int>dir;
	while(U>=0)
	{
		dir.push_back(U);
		vis[U]=true;
		U=pr[U];
	}
	for(int i=0;i<dir.size();i++)
	{
		int dist,usd;
		if(i*2<dir.size())
		{
			dist=dir.size()-i-1;
			usd=dir.back();
		}
		else
		{
			dist=i;
			usd=dir[0];
		}
		for(int u:G[dir[i]])if(!vis[u])
		{
			dfs(u,dir[i],dist+1,usd);
		}
	}
	for(int i=0;i+1<dir.size();i++)
	{
		ans+=dir.size()-i-1;
		E.push_back(make_pair(dir.back(),dir[i]));
	}
	cout<<ans<<endl;
	for(pair<int,int>e:E)cout<<e.first+1<<" "<<e.second+1<<" "<<e.second+1<<"\n";
}