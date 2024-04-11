#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<29;
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

bool isPrime(int v){
	for (int i = 2; i * i <= v; ++i)
		if (v % i == 0) return false;
	return true;
}

bool mk[210];
bool odd[210];

void dfs(int v, vi &cur, Dinic &flow)
{
	mk[v] = true;
	cur.push_back(v);
	for (int i = 0; i < SZ(flow.G[v]); ++i){
		Edge &nx = flow.G[v][i];
		if (odd[v]){
			if (nx.to > 1 && !mk[nx.to] && nx.flow == nx.cap)
				dfs(nx.to, cur, flow);
		}
		else{
			if (nx.to > 1 && !mk[nx.to] && flow.G[ nx.to ][ nx.index ].flow == flow.G[nx.to][nx.index].cap)
				dfs(nx.to, cur, flow);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Dinic flow(n + 2);

	vector<int> V(n);

	for (int i = 0; i < n; ++i){
		cin >> V[i];
		odd[i + 2] = V[i] % 2 == 1;
		if (V[i] & 1) flow.AddEdge(0, i + 2, 2);
		else flow.AddEdge(i + 2, 1, 2);

		for (int j = 0; j < i; ++j)
			if (isPrime(V[i] + V[j])){
				if (V[i] & 1) flow.AddEdge(i + 2, j + 2, 1);
				else flow.AddEdge(j + 2, i + 2, 1);
			}
	}

	if (flow.GetMaxFlow(0, 1) != n){
		cout << "Impossible" << endl;
	}
	else{
		vector<vi> ans;
		for (int i = 2; i < n + 2; ++i){
			if (mk[i]) continue;
			vi cur;
			dfs(i, cur, flow);
			ans.push_back(cur);
		}
		cout << SZ(ans) << endl;
		for (int i = 0; i < SZ(ans); ++i){
			vi &cur = ans[i];
			cout << SZ(cur);
			for (int j = 0; j < SZ(cur); ++j)
				cout << " " << cur[j] - 1;
			cout << endl;
		}
	}

	return 0;
}