#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f; 
 
int vn, en;
pair<int, LL> E[1000005];
vector<int> G[40005];
int dis[40005];
void adde(int u, int v, LL w)
{
	if(w == 0) return;
	E[en] = MP(v, w);
	G[u].push_back(en ++);
	E[en] = MP(u, 0);
	G[v].push_back(en ++);
}
 
int pos[40005], que[40005], fr, rr;
bool bfs(int v, int t)
{
	rep(i, vn) {
		pos[i] = 0; dis[i] = -1;
	}
	fr = rr = 0;
	dis[v] = 0;
	que[rr ++] = v;
	while(fr < rr) {
		v = que[fr ++];
		rep(i, G[v].size()) {
			int ce = G[v][i];
			if(E[ce].second == 0) continue;
			if(dis[E[ce].first] == -1) {
				dis[E[ce].first] = dis[v] + 1;
				que[rr ++] = E[ce].first;
			}
		}
	}
	return dis[t] != -1;
}
LL dfs(int s, int t, LL tot = INF)
{
	if(s == t) return tot;
	LL ret = 0;
	for(; pos[s] < (int)G[s].size(); pos[s] ++) {
		int ce = G[s][pos[s]];
		if(E[ce].second > 0 && dis[E[ce].first] == dis[s] + 1) {
			LL cf = min(E[ce].second, tot);
			cf = dfs(E[ce].first, t, cf);
			tot -= cf; ret += cf;
			E[ce].second -= cf; E[ce ^ 1].second += cf;
		}
		if(tot == 0) break;
	}
	return ret;
}
LL calc(int s, int t)
{
	LL ret = 0;
	while(bfs(s, t)) ret += dfs(s, t);
	return ret;
}
 
int n, mat[505][505], c[505][505], id[505][505][2], perm[505];
void addadj(int f[], int t[])
{
	adde(f[0], t[0], INF);
	adde(f[1], t[1], INF);
	adde(t[1], f[0], INF);
}
 
int main()
{
	scanf("%d", &n);
	rep1(i, n) rep1(j, n) scanf("%d", &mat[i][j]);
	rep1(i, n) rep1(j, n) scanf("%d", &c[i][j]);
	vn = 2;
#define INF 0
	rep1(i, n) rep1(j, n) {
		rep(k, 2) id[i][j][k] = vn ++;
		adde(0, id[i][j][0], INF);
		adde(id[i][j][0], id[i][j][1], INF + n - c[i][j]);
		adde(id[i][j][1], 1, INF);
	}
#undef INF
	
	rep1(i, n) {
		rep1(j, n) perm[mat[i][j]] = j;
		adde(id[i][perm[1]][1], 1, INF);
		rep1(j, n - 1) addadj(id[i][perm[j]], id[i][perm[j + 1]]);
		adde(0, id[i][perm[n]][0], INF);
	}
	rep1(i, n) {
		rep1(j, n) perm[mat[j][i]] = j;
		adde(id[perm[1]][i][1], 1, INF);
		rep1(j, n - 1) addadj(id[perm[j]][i], id[perm[j + 1]][i]);
		adde(0, id[perm[n]][i][0], INF);
	}

#define INF 0
	printf("%lld\n", (1LL + INF) * n * n - calc(0, 1));
	return 0;
}