#include <bits/stdc++.h>
#define ll long long 
#define pii pair<int,int>
#define mp make_pair
#define mt make_tuple
const int mod=201314;
const int inf=1039714778;
using namespace std;
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31) & mod;}

struct Edge
{
	int to;
	int rev;
	int flow;
	int cost;
};
vector<Edge> edges[2005];
int cur[2005],vis[2005];
int dist[2005];
int n,a,b;
int src,dst;

priority_queue<pii,vector<pii>,greater<pii> > que;
int dijkstra()
{
	memset(dist,0x3f,sizeof(dist));
	que.push(mp(0,src));dist[src]=0;
	while(que.size())
	{
		int d=que.top().first;
		int x=que.top().second;
		que.pop();
		if(dist[x]!=d) continue;
		for(auto &e:edges[x])
		{
			int u=e.to,w=e.cost;
			if(e.flow && dist[u]>dist[x]+w)
			{
				dist[u]=dist[x]+w;
				que.push(mp(dist[u],u));
			}
		}
	}
	return (dist[dst]<inf);
}

void operator += (pii &a,const pii &b)
{
	a.first+=b.first;
	a.second+=b.second;
}

void addEdges(int x,int y,int flow,int cost)
{
	Edge e;e.to=y;e.rev=edges[y].size();e.flow=flow;e.cost=cost;
	edges[x].emplace_back(e);
	e.to=x;e.rev=edges[x].size()-1;e.flow=0;e.cost=-cost;
	edges[y].emplace_back(e);
}

pii dfs(int x,int flow)
{
	if(x==dst) return mp(flow,0);
	vis[x]=1;
	pii res=mp(0,0);
	for(int &i=cur[x];i<(int)edges[x].size();i++)
	{
		auto &e=edges[x][i];
		int u=e.to;
		if(dist[u]!=dist[x]+e.cost || vis[u] || e.flow==0) continue;
		pii f=dfs(u,min(flow,e.flow));
		res+=f;res.second+=f.first*e.cost;flow-=f.first;
		e.flow-=f.first;edges[u][e.rev].flow+=f.first;
		if(!flow) break;
	}
	vis[x]=0;
	return res;
}

int p[2005],q[2005],c[2005];
int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)
	{
		double x;cin>>x;
		p[i]=round(x*1000)*1000;
	}
	for(int i=0;i<n;i++)
	{
		double x;cin>>x;
		q[i]=round(x*1000)*1000;
	}
	for(int i=0;i<n;i++)
	{
		c[i]=(p[i]/1000)*(q[i]/1000);
		// cout<<p[i]<<' '<<q[i]<<' '<<c[i]<<endl;
	}
	int A=n,B=n+1;
	src=n+2,dst=n+3;
	addEdges(src,A,a,0);
	addEdges(src,B,b,0);
	for(int i=0;i<n;i++)
	{
		addEdges(A,i,1,-p[i]);
		addEdges(B,i,1,-q[i]);
		addEdges(i,dst,1,0);
		addEdges(i,dst,1,c[i]);
	}
	int res=0;
	while(dijkstra())
	{
		// for(int i=0;i<n+4;i++)
		// {
		// 	cout<<dist[i]<<' ';
		// }
		// cout<<endl;
		memset(cur,0,sizeof(cur));
		pii w=dfs(src,inf);
		// cout<<w.first<<","<<w.second<<endl;
		if(w.second>=0) break;
		res+=w.second;
	}
	cout<<fixed;cout.precision(10);
	cout<<(double)-res/1e6<<endl;
	return 0;
}