#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
int n, k, r;
vector<int> g[400005];

int anc[19][400005];
int h[400005];
void dfs(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		anc[0][to] = v;
		for(int k = 1; k < 19; k++)
		{
			anc[k][to] = anc[k - 1][anc[k - 1][to]]; 
		}
		h[to] = h[v] + 1;
		dfs(to, v);
	}
}
int la(int v, int len)
{
	for(int k = 19 - 1; k >= 0; k--)
	{
		if(len & (1 << k))
		{
			v = anc[k][v];
		}
	}
	return v;
}
int lca(int a, int b)
{
	if(h[a] < h[b])
	{
		swap(a, b);
	}
	a = la(a, h[a] - h[b]);
	if(a == b)
	{
		return a;
	}
	for(int k = 19 - 1; k >= 0; k--)
	{
		if(anc[k][a] != anc[k][b])
		{
			a = anc[k][a];
			b = anc[k][b];
		}
	}
	return anc[0][a];
}
int walk(int a, int b, int x)
{
	int c = lca(a, b);
	if(x <= h[a] - h[c])
	{
		return la(a, x);
	}
	int excess = x - (h[a] - h[c]);
	return la(b, h[b] - h[c] - excess);
}
int uf[400005];
int dist[400005];
int find(int a)
{
	while(a != uf[a])
	{
		a = uf[a] = uf[uf[a]]; 
	}
	return a;
}
bool query(int k)
{
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	int c = lca(a, b);
	if(h[a] + h[b] - 2 * h[c] <= 2 * k)
	{
		return true;
	}
	else
	{
		return find(walk(a, b, k)) == find(walk(b, a, k));
	}
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> r;
    int N = n;
    for(int i = 0; i < n - 1; i++)
    {
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	g[x].push_back(N);
    	g[y].push_back(N);
    	g[N].push_back(x);
    	g[N].push_back(y);
    	N++;
	}
	for(int i = 0; i < N; i++)
	{
		uf[i] = i;
	}
	fill(dist, dist + N, inf);
	queue <int> fron;
	for(int i = 0; i < r; i++)
	{
		int x;
		cin >> x;
		x--;
		dist[x] = 0;
		fron.push(x);
	}
	while(!fron.empty())
	{
		int x = fron.front();
		if(dist[x] > k - 1)
		{
			break;
		}
		fron.pop();
		for(int y = 0; y < g[x].size(); y++)
		{
			uf[find(g[x][y])] = find(x);
			if(dist[g[x][y]] == inf)
			{
				dist[g[x][y]] = dist[x] + 1;
				fron.push(g[x][y]);
			}
		}
	}
	dfs(0);
	int V;
	cin >> V;
	while(V--)
	{
		if(query(k))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
    return 0;
}