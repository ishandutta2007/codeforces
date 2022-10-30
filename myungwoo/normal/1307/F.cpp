#include <bits/stdc++.h>
using namespace std;

#define pb push_back
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

#define MAXN 400005

int N, K, R, Q;
int par[MAXN][19], dep[MAXN], grp[MAXN], dist[MAXN];
vector <int> con[MAXN];
void add_edge(int a, int b){ con[a].pb(b); con[b].pb(a); }

int find(int n){ return grp[n] == n ? n : (grp[n] = find(grp[n])); }

void dfs(int n)
{
	for (int t: con[n]) if (t != par[n][0]){
		par[t][0] = n; dep[t] = dep[n]+1; dfs(t);
	}
}

inline int go_up(int n, int d)
{
	for (int i=19;i--;) if (d & 1<<i) n = par[n][i];
	return n;
}

inline int lca(int a, int b)
{
	if (dep[a] < dep[b]) swap(a, b);
	a = go_up(a, dep[a]-dep[b]);
	if (a == b) return a;
	for (int i=19;i--;) if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
	return par[a][0];
}

inline int go_k_step(int a, int b, int c)
{
	int da = dep[a]-dep[c], db = dep[b]-dep[c];
	if (da < K) return go_up(b, db-(K-da));
	else return go_up(a, K);
}

int main()
{
    read(N, K, R);
	for (int i=1;i<N;i++){
		int a, b, c = N+i; read(a, b);
		add_edge(a, c); add_edge(c, b);
	}
	N += N-1;
	for (int i=1;i<=N;i++) grp[i] = i, dist[i] = 1e9;
	queue <int> que;
	for (int i=1;i<=R;i++){
		int v; read(v);
		dist[v] = 0; que.push(v);
	}
	while (!que.empty()){
		int q = que.front(); que.pop();
		if (dist[q] == K) continue;
		for (int t: con[q]){
			grp[find(t)] = find(q);
			if (dist[t] == 1e9)
				dist[t] = dist[q]+1, que.push(t);
		}
	}
	par[1][0] = 1; dfs(1);
	for (int k=1;k<19;k++) for (int i=1;i<=N;i++) par[i][k] = par[par[i][k-1]][k-1];
	for (read(Q);Q--;){
		int a, b; read(a, b);
		int c = lca(a, b);
		if (dep[a]-dep[c]+dep[b]-dep[c] <= K+K){ puts("YES"); continue; }
		int na = go_k_step(a, b, c);
		int nb = go_k_step(b, a, c);
		if (find(na) == find(nb)) puts("YES");
		else puts("NO");
	}
}