#include<bits/stdc++.h>
 
using namespace std;
 

int x;
string t;
vector <vector <bool> > g;
struct node{
	int parentchar;
	node* parent;
	int index;
	vector <int> terminal;
	node* go[2];
	node* suf;
	node* supersuf;
	node()
	{
		index = 0;
		suf = NULL;
		supersuf = NULL;
		for(int i = 0; i < 2; i++)
		{
			go[i] = NULL;
		}
		parent = NULL;
	}
};
node* global_root;
node* root;
vector <node*> nodes;
void go_to(node* &v, int i, int ind){
	if(!v)
	{
		v = new node();
		if(i != 0)
		{
			v -> parentchar = t[i - 1] - 'a';
		}
		v -> parent = root;
		v -> suf = global_root;
		v -> supersuf = global_root;
	}
	if(i == t.size())
	{
		v -> index = ind;
		nodes.push_back(v);
		return;
	}
	root = v;
	go_to(v -> go[t[i] - 'a'], i + 1, ind);
}
struct edge{
	int a, b, cap, flow;
	edge(int a, int b, int cap):
		a(a),
		b(b),
		cap(cap),
		flow(0){};
	int other(int v)
	{
		return (v == a) ? b : a;
	}
	int capTo(int v)
	{
		return (v == b) ? (cap - flow) : flow;
	}
	int addFlow(int v, int fl)
	{
		if(v == b)
		{
			flow += fl;
		}
		else
		{
			flow -= fl;
		}
	}
};
vector <vector <int> > g1;
vector <edge> edges;
vector <bool> used;
vector <int> k, h, p;
void add_edge(int a, int b, int cap)
{
	if(a == b)
	{
		return;
	}
	edges.push_back(edge(a, b, cap));
	g1[a].push_back(edges.size() - 1);
	g1[b].push_back(edges.size() - 1);
}
int N;
bool bfs(int st, int end)
{
	vector <bool> used(N);
	queue <int> Q;
	for(int i = 0; i < N; i++)
	{
		h[i] = N;
		k[i] = 0;
		p[i] = 0;
	}
	Q.push(st);
	h[st] = 0;
	used[st] = true;
	while(Q.size() != 0)
	{
		int v = Q.front();
		Q.pop();
		if(v == end)
		{
			return 1;
		}
		for(int i = 0; i < g1[v].size(); i++)
		{
			int e = g1[v][i];
			int to = edges[e].other(v);
			if(!used[to] && edges[e].capTo(to))
			{
				used[to] = true;
				h[to] = h[v] + 1;
				p[to] = e;
				Q.push(to);
			}
		}
	}
	return 0;
}
bool bfs1(int st, int end)
{
	vector <bool> used(N);
	queue <int> Q;
	for(int i = 0; i < N; i++)
	{
		h[i] = N;
		k[i] = 0;
		p[i] = 0;
	}
	Q.push(st);
	h[st] = 0;
	used[st] = true;
	while(Q.size() != 0)
	{
		int v = Q.front();
		Q.pop();
		if(v == end)
		{
			return 1;
		}
		for(int i = 0; i < g1[v].size(); i++)
		{
			int e = g1[v][i];
			int to = edges[e].other(v);
			if(!used[to] && edges[e].capTo(v))
			{
				used[to] = true;
				h[to] = h[v] + 1;
				p[to] = e;
				Q.push(to);
			}
		}
	}
	return 0;
}
bool dfs(int v, int end)
{
	if(v == end)
	{
		return 1;
	}
	for(;k[v] < g1[v].size(); k[v]++)
	{
		int e = g1[v][k[v]];
		int to = edges[e].other(v);
		int w = edges[e].capTo(to);
		if(h[to] == h[v] + 1 && w && dfs(to, end))
		{
			p[to] = e;
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	global_root = new node();
	global_root -> parent = global_root;
	queue <node*> q;
	global_root -> suf = global_root;
	global_root -> supersuf = global_root;
	int n;
	cin >> n;
	N = 2 * n + 2;
	h.resize(N);
	k.resize(N);
	p.resize(N);
	g1.resize(N);
	g.resize(n + 1, vector <bool> (n + 1));
	vector <string> str(n);
	vector <pair <int, int> > mass1;
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
		t = str[i];
		go_to(global_root, 0, i + 1);
		mass1.push_back({str[i].size(), i});
	}
	sort(mass1.begin(), mass1.end());
	for(int i = 0; i < 2; i++)
	{
		if(!global_root -> go[i])
		{
			global_root -> go[i] = global_root;
			continue;
		}
		q.push(global_root -> go[i]);
	}
	node* v;
  	while(q.size() != 0)
  	{
  		v = q.front();
  		q.pop();
  		if(!v -> index)
  		{
  			v ->index = v -> supersuf -> index;
		}
  		v -> suf = v -> parent -> suf -> go[v -> parentchar];
  		if(!v -> suf || v -> suf == v)
  		{
  			v -> suf = global_root;
  		}
  		if(v -> suf -> index == 0)
  		{
			v -> supersuf = v -> suf -> supersuf;
		}
		else
		{
			v -> supersuf = v -> suf;
		}
		for(int i = 0; i < 2; i++)
		{
			if(!v -> go[i]){
				if(!v -> suf -> go[i])
				{
					v -> go[i] = global_root;
					continue;
				}
				v -> go[i] = v -> suf -> go[i];
				continue;
			}
			q.push(v -> go[i]);
		}
  	}
  	for(int i = 0; i < n; i++)
  	{
  		node* p = global_root;
  		for(int j = 0; j < str[i].size(); j++)
  		{
  			p = p -> go[str[i][j] - 'a'];
		}
		while(p != global_root)
		{
			
		g[p -> supersuf -> index][i + 1] = 1;
			g[p -> index][i + 1] = 1;
			p = p -> parent;
		}
	}
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		add_edge(0, i + 2, 1);
		add_edge(i + n + 2, 1, 1);
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				continue;
			}
			if(g[i + 1][j + 1])
			{
		//		cout << i + 1 << " "<< j + 1 << "\n";
				add_edge(i + 2, j + 2 + n, 1e9);
			}
		}
	}
	while(bfs(0, 1))
	{
	//	cout << "A\n";
		while(dfs(0, 1))
		{
			int flow = 1e9;
			for(int v = 1; v != 0; v = edges[p[v]].other(v))
			{
				flow = min(flow, edges[p[v]].capTo(v));
			}
			for(int v = 1; v != 0; v = edges[p[v]].other(v))
			{
				edges[p[v]].addFlow(v, flow);
			}
		}
	}
	vector <int> ans;
	bfs1(1, 0);
	for(int i = 0; i < n; i++)
	{
		if(h[i + 2] == N && h[i + 2 + n] != N)
		{
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}