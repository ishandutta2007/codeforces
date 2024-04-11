#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

/* Fast Integer IO */
template<typename T> inline T read(T &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<typename T, typename... Args> inline void read(T &x, Args& ...args){
	read(x); read(args...);
}
template<typename T> inline void write(T x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define MAXE 4903
typedef pair<lld, int> pli;

int N, M, E, Q;
int from[MAXE], cap[MAXE], cost[MAXE];
int dist[51], frome[51];
vector <int> cone[51];

void add_edge(int a, int c, int s)
{
	cone[a].pb(E);
	from[E] = a, cap[E] = c, cost[E++] = s;
}

bool spfa()
{
	queue <int> que;
	for (int i=1;i<=N;i++) dist[i] = 1e9;
	vector <bool> inque(N+1, 0);
	dist[1] = 0; que.push(1);
	while (!que.empty()){
		int q = que.front(); que.pop();
		inque[q] = 0;
		for (int e: cone[q]) if (cap[e]){
			int t = from[e^1];
			if (dist[t] > dist[q]+cost[e]){
				dist[t] = dist[q]+cost[e]; frome[t] = e;
				if (!inque[t]) inque[t] = 1, que.push(t);
			}
		}
	}
	return dist[N] < 1e9;
}

int main()
{
	read(N, M);
	for (int i=1;i<=M;i++){
		int a, b, c; read(a, b, c);
		add_edge(a, 1, c);
		add_edge(b, 0, -c);
	}
	lld total_cost = 0; int total_flow = 0;
	vector <pli> arr = {{0, 0}};
	while (spfa()){
		int flow = 1e9, cur = dist[N];
		for (int i=N;i>1;i=from[frome[i]]) flow = min(flow, cap[frome[i]]);
		total_flow += flow;
		total_cost += flow*cur;
		// debug("%d: %d %d\n", total_flow, dist[N], total_flow*dist[N]-total_cost);
		arr.pb({(lld)total_flow*dist[N]-total_cost, dist[N]});
		for (int i=N;i>1;i=from[frome[i]]) cap[frome[i]] -= flow, cap[frome[i]^1] += flow;
	}
	for (read(Q);Q--;){
		int c; read(c);
		auto it = lower_bound(all(arr), mp(c+1LL, 0))-1;
		int f = it-arr.begin();
		printf("%.9f\n", it->second + (double)(c-it->first)/f);
	}
}