#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 805, MAXM = 100005, INF = 0x3f3f3f3f;

struct MCMF{
	struct edge{
		int n, p, r;
		double w;
		void var(int _n, int _p, int _r, double _w){
			n = _n, p = _p, r = _r, w = _w;
		}
	}edges[MAXM << 1];
	struct queue{
		int d[MAXN], head, tail;
		void init(){head = tail = 0;}
		void push(int x){d[tail = (tail + 1) % MAXN] = x;}
		void pop(){head = (head + 1) % MAXN;}
		int front(){return d[(head + 1) % MAXN];}
		bool empty(){return head == tail;}
	}q;
	int g[MAXN], edgeSize, cur[MAXN], s, t, pre[MAXN], en[MAXN], flow;
	double dist[MAXN], cost;
	bool inq[MAXN];

	void init(int _s, int _t){
		s = _s, t = _t;
		edgeSize = 1;
	}
	void addEdge(int from, int to, int cap, double _cost){
		edges[++ edgeSize].var(to, g[from], cap, _cost);
		g[from] = edgeSize;
		edges[++ edgeSize].var(from, g[to], 0, - _cost);
		g[to] = edgeSize;
	}
	bool bellmanFord(){
		int now, p;
		for(now = s; now <= t; ++ now)
			dist[now] = 1e10;
		q.init();
		dist[s] = 0;
		q.push(s);
		inq[s] = true;
		while(!q.empty()){
			now = q.front();
			q.pop();
			inq[now] = false;
			for(p = g[now]; p; p = edges[p].p){
				edge& e = edges[p];
				if(e.r && dist[e.n] > dist[now] + e.w){
					dist[e.n] = dist[now] + e.w;
					pre[e.n] = now;
					en[e.n] = p;
					if(!inq[e.n]){
						inq[e.n] = true;
						q.push(e.n);
					}
				}
			}
		}
		return dist[t] < 1e10 - 1e-8;
	}
	void augment(){
		int delta = INF, p;
		for(p = t; p != s; p = pre[p])
			delta = min(delta, edges[en[p]].r);
		flow += delta;
		cost += delta * dist[t];
		for(p = t; p != s; p = pre[p]){
			edges[en[p]].r -= delta;
			edges[en[p] ^ 1].r += delta;
		}
	}
	void solve(){
		cost = flow = 0;
		while(bellmanFord())
			augment();
	}
}maxFlow;
struct point{
	int x, y;
	bool operator < (const point& rhs) const{
		return y < rhs.y;
	}
}p[MAXN];
int n;

inline double dist(int a, int b){
	return sqrt((double)(p[a].x - p[b].x) * (p[a].x - p[b].x) + (double)(p[a].y - p[b].y) * (p[a].y - p[b].y));
}
int main(){
	int i, j;
	scanf("%d", &n);
	maxFlow.init(0, n * 2 + 2);
	for(i = 1; i <= n; ++ i)
		scanf("%d%d", &p[i].x, &p[i].y);
	maxFlow.addEdge(0, n * 2 + 1, 1, 0);
	sort(p + 1, p + 1 + n);
	for(i = 1; i <= n; ++ i){
		maxFlow.addEdge(0, i, 2, 0);
		maxFlow.addEdge(n * 2 + 1, n + i, 1, 0);
		maxFlow.addEdge(n + i, n * 2 + 2, 1, 0);
		for(j = 1; j < i; ++ j)
			if(p[j].y < p[i].y)
				maxFlow.addEdge(i, n + j, 1, dist(i, j));
			else break;
	}
	maxFlow.solve();
	if(maxFlow.flow == n) printf("%.15f\n", maxFlow.cost);
	else printf("-1\n");
	return 0;
}