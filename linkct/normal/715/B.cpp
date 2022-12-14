#include <cstdio>
#include <queue>
#include <cstring>
#define fi first
#define se second
const int MAXN = 1005, MAXM = 10005;
using namespace std;
typedef long long int LL;
typedef pair <LL, int> pii;

priority_queue <pii, vector <pii>, greater <pii> > q;
int n, m, L, t, s, u[MAXM], v[MAXM], w[MAXM], edgeSize, g[MAXN];
int to[MAXM << 1], nxt[MAXM << 1], prev[MAXN * MAXN], pren[MAXN * MAXN];
LL dist[MAXN * MAXN];

inline bool relax(LL &a, LL b){if(a > b) return a = b, true; return false;}
void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
int main(){
	int i, p, x, y, T; edgeSize = 1; pii now;
	scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
	++ s, ++ t;
	for(i = 1; i <= m; ++ i){
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		addEdge(u[i] + 1, v[i] + 1);
		addEdge(v[i] + 1, u[i] + 1);
	}
	memset(dist, 0x3f, sizeof(dist));
	q.push(pii(dist[s] = 0LL, s));
	while(!q.empty()){
		now = q.top(); q.pop();
		if(now.fi != dist[now.se]) continue;
		x = ((now.se - 1) % n) + 1, y = (now.se - 1) / n;
		for(p = g[x]; p; p = nxt[p]){
			T = (y + (w[p >> 1] ? 0 : 1)) * n + to[p];
			if(T <= n * n && relax(dist[T], now.fi + (w[p >> 1] ? w[p >> 1] : 1))){
				q.push(pii(dist[T], T));
				prev[T] = p >> 1, pren[T] = now.se;
			}
		}
	}
	if(dist[t] < L){
		printf("NO\n");
		return 0;
	}
	if(dist[t] == L){
		printf("YES\n");
		for(i = 1; i <= m; ++ i)
			if(w[i]) printf("%d %d %d\n", u[i], v[i], w[i]);
			else printf("%d %d 1000000000000000000\n", u[i], v[i]);
		return 0;
	}
	for(i = 1; i < n; ++ i)
		if(dist[i * n + t] <= L){
			printf("YES\n"); x = i * n + t;
			for(p = x; p != s; p = pren[p]){
				if(w[prev[p]]) continue;
				if(i == 1){
					w[prev[p]] = L - dist[x] + 1;
					break;
				} -- i, ++ w[prev[p]];
			}
			for(i = 1; i <= m; ++ i)
				if(w[i]) printf("%d %d %d\n", u[i], v[i], w[i]);
				else printf("%d %d 1000000000000000000\n", u[i], v[i]);
			return 0;
		}
	printf("NO\n");
	return 0;
}