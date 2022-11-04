#include <bits/stdc++.h>
using namespace std;

#include <cmath>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

const int INF = 1000000000;
const int inf = INF;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

struct node{
	int r,c,t;
	node () {}
	node (int r, int c, int t) : r(r), c(c), t(t) {}
};
vector<node> qm,qf;

node read (){
	int r,c,t; cin >> r >> c >> t;
	r--; c--; 
	return node(r,c,t);
}

const int MAXN = 25;
const int MAXT = 600;

char mat[MAXN][MAXN];
int n,m,male,female;
int id[MAXN][MAXN];
int dis[MAXT][MAXT];

int main(){
	cin >> n >> m >> male >> female;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> mat[i][j];
	if (male < female) 
		qm.push_back(read()); 
	else 
		qf.push_back(read());
	for (int i=0; i<male; i++) qm.push_back(read());
	for (int i=0; i<female; i++) qf.push_back(read());
	if (male < female) male++; else female++;
	if (male != female){
		cout << -1 << endl;
		return 0;
	}
	int tot = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (mat[i][j] == '.')
			id[i][j] = tot++;
	for (int i=0; i<tot; i++)
		for (int j=0; j<tot; j++)
			dis[i][j] = (i==j) ? 0 : inf;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (mat[i][j] == '.')
			for (int ii=0; ii<n; ii++)
				for (int jj=0; jj<m; jj++) if (mat[ii][jj] == '.' && abs(i-ii)+abs(j-jj)==1)
					dis[id[i][j]][id[ii][jj]] = 1; 
	for (int k=0; k<tot; k++)
		for (int i=0; i<tot; i++)
			for (int j=0; j<tot; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	long long lo = 0, hi = 1LL<<60, ans = -1;
	while (lo <= hi){
		long long mid = (lo + hi) / 2;
		Dinic res(male+female+2*tot+2);
		for (int i=0; i<(int)qm.size(); i++){
			int index = id[qm[i].r][qm[i].c];
			for (int j=0; j<tot; j++) if (dis[index][j] != inf && (long long)dis[index][j] * qm[i].t <= mid)
				res.AddEdge(i, male+j, 1);
		}
		for (int j=0; j<tot; j++)
			res.AddEdge(male+j, male+tot+j, 1);
		for (int j=0; j<tot; j++)
			for (int k=0; k<(int)qf.size(); k++){
				int index = id[qf[k].r][qf[k].c];
				if (dis[index][j] != inf && (long long)dis[index][j] * qf[k].t <= mid)
					res.AddEdge(male+tot+j, male+tot+tot+k, 1);
			}
		int source = male+tot+tot+female;
		int sink = source + 1;
		for (int i=0; i<male; i++) res.AddEdge(source, i, 1);
		for (int i=0; i<female; i++) res.AddEdge(male+tot+tot+i, sink, 1);
		if (res.GetMaxFlow(source, sink) == male)
			ans = mid, hi = mid-1;
		else
			lo = mid+1;
	}
	cout << ans << endl;
	return 0;
}