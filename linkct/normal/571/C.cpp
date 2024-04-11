#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 200005;
typedef pair <int, int> pii;
#define fi first
#define se second

int f[MAXN], n, m, d[MAXN], value[MAXN];
bool freed[MAXN];
vector <int> clause[MAXN];
vector <pii> pos[MAXN];
queue <int> q;

inline int sgn(int x){return x > 0 ? 1 : (x ? -1 : 0);}
int find(int x){return f[x] > 0 ? f[x] = find(f[x]) : x;}
inline int abs(int x){return x >= 0 ? x : -x;}
void merge(int u, int v){
	if(!f[u]) f[v] = 0;
	f[u] = v;
}
void EliminateKnownClause(){
	int now, i, vid, t;
	while(!q.empty()){
		now = q.front(); q.pop();
		for(i = 0; i < int(clause[now].size()); ++ i){
			vid = abs(clause[now][i]);
			if(value[vid] != -1) continue;
			value[vid] = int(clause[now][i] < 0);
			t = pos[vid][0].fi == now;
			if(!freed[pos[vid][t].fi]){
				freed[pos[vid][t].fi] = true;
				q.push(pos[vid][t].fi);
			}
		}
	}
}
int main(){
	int i, j, sz, t, u, v, cur, vid;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &sz);
		for(j = 1; j <= sz; ++ j){
			scanf("%d", &t);
			clause[i].push_back(t);
			pos[abs(t)].push_back(pii(i, j));
		}
	}
	memset(value, -1, sizeof(value));
	for(i = 1; i <= m; ++ i){
		if(pos[i].size() == 0) value[i] = 1;
		else if(pos[i].size() == 1){
			value[i] = int(clause[pos[i][0].fi][pos[i][0].se - 1] > 0);
			if(!freed[pos[i][0].fi]){
				freed[pos[i][0].fi] = true;
				q.push(pos[i][0].fi);
			}
		}else if(sgn(clause[pos[i][0].fi][pos[i][0].se - 1]) == sgn(clause[pos[i][1].fi][pos[i][1].se - 1])){
			value[i] = int(clause[pos[i][0].fi][pos[i][0].se - 1] > 0);
			if(!freed[pos[i][0].fi]){
				freed[pos[i][0].fi] = true;
				q.push(pos[i][0].fi);
			}
			if(!freed[pos[i][1].fi]){
				freed[pos[i][1].fi] = true;
				q.push(pos[i][1].fi);
			}
		}
	}
	EliminateKnownClause();
	for(i = 1; i <= n; ++ i) f[i] = -1;
	for(i = 1; i <= m; ++ i)
		if(value[i] == -1){
			u = find(pos[i][0].fi), v = find(pos[i][1].fi);
			if(u == v) f[u] = 0;
			else merge(u, v);
			++ d[pos[i][0].fi], ++ d[pos[i][1].fi];
		}
	for(i = 1; i <= n; ++ i)
		if(!freed[i] && f[find(i)]) break;
	if(i != n + 1){
		printf("NO\n");
		return 0;
	}
	for(i = 1; i <= n; ++ i)
		if(d[i] == 1){
			cur = i;
			while(d[cur] == 1){
				d[cur] = 0;
				freed[cur] = true;
				for(j = 0; j < int(clause[cur].size()); ++ j)
					if(value[abs(clause[cur][j])] == -1) break;
				vid = abs(clause[cur][j]);
				value[vid] = int(clause[cur][j] > 0);
				t = pos[vid][0].fi == cur;
				if((-- d[pos[vid][t].fi]) == 1) cur = pos[vid][t].fi;
			}
		}
	for(i = 1; i <= m; ++ i){
		if(value[i] != -1) continue;
		value[i] = 1;
		t = int(clause[pos[i][0].fi][pos[i][0].se - 1] < 0);
		freed[pos[i][t].fi] = true;
		q.push(pos[i][t].fi);
		EliminateKnownClause();
	}
	printf("YES\n");
	for(i = 1; i <= m; ++ i) printf("%d", value[i]);
	printf("\n");
	return 0;
}