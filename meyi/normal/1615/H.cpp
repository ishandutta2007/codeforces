#include <cstdio>
#include <queue>
using namespace std;
#define int long long
const int MAXN=1005;
const int INF=1E14;
namespace MF
{
	struct Edge
	{
		int from, to, cap, flow;
		Edge(int u, int v, int c, int f):
			from(u), to(v), cap(c), flow(f) {}
	};
	int n, s, t, flow;
	vector<Edge> edges;
	vector<int> g[MAXN];
	int h[MAXN], cur[MAXN];
	void init(int v, int a, int b)
	{
		n=v, s=a, t=b, flow=0;
		edges.clear();
		for (int i=1; i<=n; i++) g[i].clear();
	}
	void addEdge(int from, int to, int cap)
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		g[from].push_back(edges.size()-2);
		g[to].push_back(edges.size()-1);
	}
	bool bfs()
	{
		queue<int> q;
		for (int i=1; i<=n; i++) cur[i]=h[i]=0;
		h[s]=1, q.push(s);
		while (!q.empty())
		{
			int u=q.front(); q.pop();
			for (int i=0; i<g[u].size(); i++)
			{
				Edge e=edges[g[u][i]];
				if (e.cap>e.flow&&!h[e.to])
					h[e.to]=h[u]+1, q.push(e.to);
			}
		}
		return h[t];
	}
	int dfs(int u, int f)
	{
		if (u==t) return f;
		for (int &i=cur[u]; i<g[u].size(); i++)
		{
			Edge &e=edges[g[u][i]];
			if (e.cap>e.flow&&h[e.to]==h[u]+1)
			{
				int d=dfs(e.to, min(f, e.cap-e.flow));
				if (d>0)
				{
					e.flow+=d;
					edges[g[u][i]^1].flow-=d;
					return d;
				}
			}
		}
		return 0;
	}
	void Dinic()
	{
		while (bfs())
			while (int f=dfs(s, INF)) flow+=f;
	}
}
int c[MAXN];
int w[MAXN], a[66], b[66];
int p[MAXN], q[MAXN], t1[MAXN], t2[MAXN];
int f[MAXN];
vector<int> G[MAXN];
void solve(int l, int r, int L, int R)
{
	if (l>r) return;
	if (R-L==1)
	{
		MF::init(r-l+3, r-l+2, r-l+3);
		for (int i=l; i<=r; i++) q[p[i]]=i-l+1;
		for (int i=l; i<=r; i++)
		{
			int u=p[i], cost=w[u]<L?-1:w[u]==L?0:1;
			if (cost>0) MF::addEdge(MF::s, q[u], cost);
			else MF::addEdge(q[u], MF::t, -cost);
			for (int v: G[u]) if (q[v])
				MF::addEdge(q[u], q[v], INF);
		}
		for (int i=l; i<=r; i++) q[p[i]]=0;
		MF::Dinic();
		for (int i=l; i<=r; i++)
			if (!MF::h[i-l+1]) f[p[i]]=L;
			else f[p[i]]=R;
		return;
	}
	int mid=(L+R)/2;
	MF::init(r-l+3, r-l+2, r-l+3);
	for (int i=l; i<=r; i++) q[p[i]]=i-l+1;
	for (int i=l; i<=r; i++)
	{
		int u=p[i];
		if (mid<w[u]) MF::addEdge(MF::s, q[u], 1);
		else MF::addEdge(q[u], MF::t, 1);
		for (int v: G[u]) if (q[v])
			MF::addEdge(q[u], q[v], INF);
	}
	for (int i=l; i<=r; i++) q[p[i]]=0;
	MF::Dinic();
	int c1=0, c2=0;
	for (int i=l; i<=r; i++)
		if (!MF::h[i-l+1]) t1[++c1]=p[i];
		else t2[++c2]=p[i];
	for (int i=1; i<=c1; i++) p[l+i-1]=t1[i];
	for (int i=1; i<=c2; i++) p[l+c1+i-1]=t2[i];
	solve(l, l+c1-1, L, mid);
	solve(l+c1, r, mid, R);
}
signed main()
{
//	freopen("shop.in", "r", stdin);
//	freopen("shop.out", "w", stdout);
	int n, m;
	scanf("%lld%lld", &n, &m);
	for (int i=1; i<=n; i++) scanf("%lld", &w[i]),p[i]=i;
	while(m--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		G[x].push_back(y);
	}
	solve(1, n, 0, 2e9);
	for (int i=1; i<=n; i++)printf("%lld ",f[i]);
	return 0;
}