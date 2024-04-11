#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LIM 1000005
#define ll long long
#define pb push_back
#define po pop_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char *P1,*P2,buf[LIM];
int n,m,c,w[N];ll dst[N],dst1[N];bool vs[N];vector<int> vc[N];
struct Edge {int v,id;};vector<Edge> e[N];
struct Node {int u;ll w;bool operator < (Node t) const {return w>t.w;}};
priority_queue<Node> q;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void Dijkstra(int S)
{
	for(int i=1;i<=n;++i) vs[i]=0,dst[i]=INF;q.push((Node) {S,dst[S]=0});
	while(!q.empty())
	{
		Node t=q.top();q.pop();int u=t.u;if(vs[u]) continue;vs[u]=1;
		for(auto i:e[u]) if(dst[u]+w[i.id]<dst[i.v])
			q.push((Node) {i.v,dst[i.v]=dst[u]+w[i.id]});
	}
}
void slv(int S,int up)
{
	for(int i=1;i<=n;++i) vs[i]=0,dst1[i]=dst[i],dst[i]=INF;
	vc[dst[S]=0].pb(S);int t=0,u;
	while(t<=up)
	{
		while(!vc[t].empty())
		{
			u=*--vc[t].end();vc[t].po();if(vs[u]) continue;vs[u]=1;
			for(auto i:e[u]) if(dst[u]+w[i.id]<dst[i.v])
			{
				dst[i.v]=dst[u]+w[i.id];
				if(dst[i.v]-dst1[i.v]<=up) vc[dst[i.v]-dst1[i.v]].pb(i.v);
			}
		}++t;
	}
}
int main()
{
	n=rd();m=rd();c=rd();
	for(int i=1,u,v;i<=m;++i)
		u=rd(),v=rd(),w[i]=rd(),e[u].pb((Edge) {v,i});Dijkstra(1);
	for(int i=1,x,F[2];i<=c;++i)
	{
		F[0]=rd();F[1]=rd();
		if(F[0]==1) printf("%lld\n",(dst[F[1]]<INF?dst[F[1]]:-1));
		else {for(int j=1;j<=F[1];++j) x=rd(),++w[x];slv(1,F[1]);}
	}return 0;
}