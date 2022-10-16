#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 10000001;

struct node{
	node *go[2];
	node *f, *father;
	int e;
};

vector<node*> nodeid;

void push(node *cur, int idx, string &s){
	for (int i = 0; i < (int)s.length(); ++i){
		int v = s[i] - 'a';
		if (!cur->go[v]){
			cur->go[v] = new node();
			cur->go[v]->father = cur;
		}
		cur = cur->go[v];
	}
	cur->e = idx;
	nodeid.push_back(cur);
}

void build(node *root){
	queue<node*> q; 
	for (int i = 0; i < 2; ++i)
		if (root->go[i]){
			q.push(root->go[i]);
			root->go[i]->f = root;
		}
		else
			root->go[i] = root;

	while (!q.empty()){
		auto cur = q.front(); q.pop();
		if (!cur->e) cur->e = cur->f->e;
		for (int i = 0; i < 2; ++i){
			if (cur->go[i])
			{
				cur->go[i]->f = cur->f->go[i];
				q.push(cur->go[i]);
			}
			else
				cur->go[i] = cur->f->go[i];
		}
	}
}

template<typename T>
struct dinic
{
	struct edge
	{
		int src, dst;
		T cap, flow;
		int rev;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n) {}

	void add_edge(int src, int dst, T cap)
	{
		adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size() });
		if (src == dst) adj[src].back().rev++;
		adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1 });
	}

	vector<int> level, iter;

	T augment(int u, int t, T cur)
	{
		if (u == t)
			return cur;
		for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
		{
			edge &e = adj[u][i];
			if (e.cap - e.flow > 0 && level[u] > level[e.dst])
			{
				T f = augment(e.dst, t, min(cur, e.cap - e.flow));
				if (f > 0)
				{
					e.flow += f;
					adj[e.dst][e.rev].flow -= f;
					return f;
				}
			}
		}
		return 0;
	}

	int bfs(int s, int t)
	{
		level.assign(n, n);
		level[t] = 0;
		queue<int> Q;
		for (Q.push(t); !Q.empty(); Q.pop())
		{
			int u = Q.front();
			if (u == s) break;
			for (edge &e : adj[u])
			{
				edge &erev = adj[e.dst][e.rev];
				if (erev.cap - erev.flow > 0 && level[e.dst] > level[u] + 1)
				{
					Q.push(e.dst);
					level[e.dst] = level[u] + 1;
				}
			}
		}
		return level[s];
	}

	T max_flow(int s, int t)
	{
		for (int u = 0; u < n; ++u) // initialize
			for (auto &e : adj[u])
				e.flow = 0;

		T flow = 0;
		while (bfs(s, t) < n)
		{
			iter.assign(n, 0);
			for (T f; (f = augment(s, t, numeric_limits<T>::max())) > 0;)
				flow += f;
		} // level[u] == n ==> s-side
		return flow;
	}
};

const int oo = 0x3f3f3f3f;

const int N = 751;

bool mat[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	node *root = new node();
	for (int i = 1; i <= n; ++i)
	{
		string s; cin >> s;
		push(root, i, s);
	}
	build(root);

	for (int i = 1; i <= n; ++i){
		node *cur = nodeid[i - 1];
		mat[cur->f->e][i] = true;
		while (cur != root){
			mat[cur->e][i] = true;
			cur = cur->father;
		}
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				mat[i][j] |= mat[i][k] & mat[k][j];

	dinic<int> flow(2 * n + 2);

	for (int i = 0; i < n; ++i){
		flow.add_edge(0, i + 2, 1);
		flow.add_edge(i + 2 + n, 1, 1);
		for (int j = 0; j < n; ++j){
			if (i == j) continue;
			if (mat[i + 1][j + 1]){
				flow.add_edge(i + 2, j + n + 2, oo);
				// cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}

	int f = flow.max_flow(0, 1);
	vector<int> ans;
	for (int i = 0; i < n; ++i)
		if (flow.level[i + 2] == flow.n && flow.level[i + 2 + n] != flow.n)
			ans.push_back(i + 1);

	cout << ans.size() << endl;
	for (auto v : ans)
		cout << v << " ";
	cout << endl;


	return 0;
}