#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

struct Edge
{
	int from, to, cap, flow, index;

	Edge(int from, int to, int cap, int flow, int index) :
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic
{
	int N;
	vector< vector<Edge> > G;
	vector<Edge*> dad;
	vector<int> Q;

	Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

	void AddEdge(int from, int to, int cap)
	{
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if(from == to) G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	long long BlockingFlow(int s, int t)
	{
		fill(dad.begin(),dad.end(),(Edge*) NULL);
		dad[s] = &G[0][0] - 1;

		int head = 0, tail = 0;
		Q[tail++] = s;

		while(head < tail)
		{
			int x = Q[head++];

			for(int i = 0; i < (int) G[x].size(); ++i)
			{
				Edge &e = G[x][i];

				if(!dad[e.to] && e.cap - e.flow > 0)
				{
					dad[e.to] = &G[x][i];
					Q[tail++] = e.to;
				}
			}
		}

		if(!dad[t]) return 0;

		long long totflow = 0;

		for(int i = 0; i < (int) G[t].size(); ++i)
		{
			Edge *start = &G[G[t][i].to][G[t][i].index];
			int amt = oo;

			for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				if(!e) { amt = 0; break; }
				amt = min(amt,e->cap - e->flow);
			}

			if(amt == 0) continue;

			for(Edge *e = start; amt && e != dad[s]; e = dad[e->from])
			{
				e->flow += amt;
				G[e->to][e->index].flow -= amt;
			}

			totflow += amt;
		}

		return totflow;
	}

	long long GetMaxFlow(int s, int t)
	{
		long long totflow = 0;

		while(long long flow = BlockingFlow(s,t))
			totflow += flow;

		return totflow;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	Dinic flow(2 * n + 2);

	for (int i = 0; i < n; ++i)
		flow.AddEdge(i + 2, i + n + 2, oo);

	int a = 0, b = 0;
	for (int i = 0; i < n; ++i){
		int cur; cin >> cur;
		flow.AddEdge(0, i + 2, cur);
		a += cur;
	}

	for (int i = 0; i < n; ++i){
		int cur; cin >> cur;
		flow.AddEdge(i + n + 2, 1, cur);
		b += cur;
	}

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;
		u--; v--;
		flow.AddEdge(u + 2, v + n + 2, oo);
		flow.AddEdge(v + 2, u + n + 2, oo);
	}

	int f = flow.GetMaxFlow(0, 1);

	vector<vector<int>> V(n, vector<int>(n));

	if (b == a && f == b){
		cout << "YES" << endl;
		for (auto node : flow.G){
			for (auto edge : node){
				if (edge.from < 2 || edge.to < 2 || edge.to < edge.from) continue;
				V[ (edge.from - 2) % n][ (edge.to - n - 2) % n ] = edge.flow;
			}
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				cout << V[i][j] << " ";
			cout << endl;
		}
//		exit(0);
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}