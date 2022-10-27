#include<bits/stdc++.h>
 
using namespace std;

vector <vector <int> > g;
vector <vector <int> > parent;
vector <vector <int> > id;
int s, t, n, m;
map <pair <int, int>, int> mp;
vector <int> dep;
int edge_id[30000];
int num;
const int N = 3e4;
struct Graph{
	int to, nxt, flow;
}G[N * 100];
int head[N * 20];
int etot  = 1;
void addedge(int x, int y, int f)
{
	G[++etot] = {y, head[x], f};
	head[x] = etot;
	G[++etot] = {x, head[y], 0};
	head[y] = etot;
}
void dfs(int v, int p)
{
	parent[v][0] = p;
	dep[v] = dep[p] + 1;
	if(v != 1)
	{
		id[v][0] = ++num;
		edge_id[mp[{min(v, p), max(v, p)}]] = num;
		addedge(id[v][0], t, 1);
		for(int i = 1; i <= 15; i++)
		{
			parent[v][i] = parent[parent[v][i - 1]][i - 1];
			if(!parent[v][i])
			{
				break;
			}
			id[v][i] = ++num;
			addedge(id[v][i], id[v][i - 1], 1e9);
			if(parent[v][i - 1] && parent[v][i - 1] != 1)
			{
				addedge(id[v][i], id[parent[v][i - 1]][i - 1], 1e9);
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			dfs(g[v][i], v);
		}
	}
}
int get_lca(int x, int y)
{
	if(dep[x] < dep[y])
	{
		swap(x, y);
	}
	for(int i = 15; i >= 0; i--)
	{
		if(dep[parent[x][i]] >= dep[y])
		{
			x = parent[x][i];
		}
	}
	if(x == y)
	{
		return x;
	}
	for(int i = 15; i >= 0; i--)
	{
		if(parent[x][i] != parent[y][i])
		{
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	return parent[x][0];
}
void work(int x, int y, int st)
{
	for(int i = 15; i >= 0; i--)
	{
		if(dep[parent[x][i]] >= dep[y])
		{
			addedge(st, id[x][i], 1e9);
			x = parent[x][i];
		}
	}
}
int dist[N * 20], cur[N * 20];
bool bfs()
{
	for(int i = 1; i <= num; i++)
	{
		dist[i] = 0;
		cur[i] = head[i];
	}
	dist[s] = 1;
	queue <int> q;
	q.push(s);
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		for(int i = head[v]; i; i = G[i].nxt)
		{
			int y = G[i].to;
			if(G[i].flow && !dist[y])
			{
				dist[y] = dist[v] + 1;
				q.push(y);
			}
		}
	}
	return dist[t];
}
int Dfs(int v, int  fl)
{
	if(v == t)
	{
		return fl;
	}
	int used = 0;
	for(int &i = cur[v]; i; i = G[i].nxt)
	{
		int y = G[i].to;
		if(G[i].flow && dist[y] == dist[v] + 1)
		{
			int to = Dfs(y, min(G[i].flow, fl - used));
			if(!to)
			{
				dist[y] = -1;
			}
			else
			{
				G[i].flow -= to;
				G[i ^ 1].flow += to;
				if((used += to) == fl)
				{
					break;
				}
			}
		}
	}
	return used;
}
void dinic(){
	int flow = 0;
	while(bfs())
	{
		flow += Dfs(s, 1e9);
	}
	cout << flow << "\n";
	vector <int> ans;
	for(int i = 1; i <= m; i++)
	{
		if(!dist[i])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << " ";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	ans.clear();
	for(int i = 1; i < n; i++)
	{
		if(dist[edge_id[i]])
		{
			ans.push_back(i);
		}
	}
	cout << ans.size() << " ";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	g.resize(n + 1);
	dep.resize(n + 1);
	parent.resize(n + 1, vector <int> (16));
	id.resize(n + 1, vector <int> (16));
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		mp[{min(u, v), max(u, v)}] = i;
	}
	num = m;
	s = ++num;
	t = ++num;
	dfs(1, 0);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int lca = get_lca(x, y);
		work(x, lca, i);
		work(y, lca, i);
	}
	for(int i = 1; i <= m; i++)
	{
		addedge(s, i, 1);
	}
	dinic();
	return 0;
}