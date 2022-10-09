/*






























*/

#include <bits/stdc++.h>

using namespace std;

//#define MULTITEST

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 30 * 1000 + 13;
const int M = 2 * N;

int n, m;
vector<pt> g[N];
bool used[N];
int tin[N], fup[N];
int T;
vector<int> st;
vector<vector<int>> comps;

void add_comp(int t) {
	comps.pb(vector<int>());
	while (sz(st) != t) {
		comps.back().pb(st.back());
		st.pop_back();
	}
}

void dfs1(int v, int p) {
	used[v] = true;
	tin[v] = fup[v] = T++;
	for (auto it : g[v]) {
		int u = it.x, i = it.y;
		if (u == p) continue;
		if (!used[u]) {
			int t = sz(st);
			st.pb(i);
			
			dfs1(u, v);
			fup[v] = min(fup[v], fup[u]);
			
			if (fup[u] >= tin[v])
				add_comp(t);
		} else {
			if (tin[u] < tin[v])	
				st.pb(i);
			fup[v] = min(fup[v], tin[u]);
		}
	}
	
	if (p == -1 && sz(st) > 0)
		add_comp(0);
}

void biconnected_v_comps() {
	comps.clear();
	memset(used, 0, sizeof(bool) * n);
	T = 0;
	forn(i, n) if (!used[i]) 
		dfs1(i, -1);
}

int es[M];

bool read(){
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v, --u, --w;
		es[i] = w;
		g[v].pb(mp(u, i));
		g[u].pb(mp(v, i));
	}
	return true;
}

struct edge{
	int v, to, cap, flow, next;
};

int cnt;

int head[N];
int s, t;

vector<edge> e;

void add_edge(int v, int to, int cap){
	e.pb({v, to, cap, 0, head[v]});
	head[v] = sz(e) - 1;
	e.pb({to, v, 0, 0, head[to]});
	head[to] = sz(e) - 1;
}

void build(){
	e.clear();
	memset(head, -1, sizeof(head));
	
	s = n + m;
	t = s + 1;
	cnt = t + 1;
	forn(i, sz(comps)) for (int &j : comps[i])
		j = es[j];
	forn(i, sz(comps))
		add_edge(s, i, sz(comps[i]) - (sz(comps[i]) > 1));
	forn(i, m)
		add_edge(n + i, t, 1);
	forn(i, sz(comps)) for (int j : comps[i])
		add_edge(i, n + j, 1);
}

inline int rem(int i){
	return e[i].cap - e[i].flow;
}

int d[N];
int lst[N];

int bfs(){
	forn(i, cnt) d[i] = INF;
	d[s] = 0;
	
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int j = head[v]; j != -1; j = e[j].next){
			if (rem(j) && d[e[j].to] == INF){
				d[e[j].to] = d[v] + 1;
				if (e[j].to == t)
					return true;
				q.push(e[j].to);
			}
		}
	}
	
	return d[t] < INF;
}

int dfs(int v, int flow){
	if (v == t)
		return flow;
	if (flow == 0)
		return 0;
	int result = 0;
	for (; lst[v] != -1; lst[v] = e[lst[v]].next){
		int i = lst[v];
		if (d[e[i].to] != d[v] + 1)
			continue;
		int add = dfs(e[i].to, min(flow, rem(i)));
		result += add;
		flow -= add;
		e[i].flow += add;
		e[i ^ 1].flow -= add;
		if (flow == 0)
			break;
	}
	return result;
}

int dinic(){
	int flow = 0;
	while (true){
		if (!bfs())
			break;
		forn(v, cnt)
			lst[v] = head[v];
		int add;
		while ((add = dfs(s, INF)) > 0)
			flow += add;
	}
	return flow;
}

int mincut(){
	build();
	int flow = 0;
	while (true){
		int add = dinic();
		if (add == 0)
			break;
		flow += add;
	}
	return flow;
}

void solve() {
	biconnected_v_comps();
	printf("%d\n", mincut());
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}