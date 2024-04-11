#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL INF = 0x3f3f3f3f3f3f3f3f;
int vn, en;
pair<int, LL> E[100005];
vector<int> G[2005];
int dis[2005];
void adde(int u, int v, LL w)
{
	E[en] = MP(v, w);
	G[u].push_back(en ++);
	E[en] = MP(u, 0);
	G[v].push_back(en ++);
}

int pos[2005], que[2005], fr, rr;
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

int n, m, a, b;
char ret[1005];

int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	a --; b --;
	vn = 2 * n + 2;
	rep(i, n) {
		if(i == b) adde(0, i * 2 + 2, INF);
		if(i == a) adde(i * 2 + 2, 1, INF);
		if(i == a) adde(0, i * 2 + 3, INF);
		if(i == b) adde(i * 2 + 3, 1, INF);
	}
	rep(i, m) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		u --; v --;
		adde(u * 2 + 2, v * 2 + 3, l);
		adde(v * 2 + 3, u * 2 + 2, l);
		adde(v * 2 + 2, u * 2 + 3, l);
		adde(u * 2 + 3, v * 2 + 2, l);
	}
	LL ans = calc(0, 1);
	rep(i, n) ret[i] = 'A';
	for(int i = 2; i < n * 2 + 2; i ++) ret[(i - 2) / 2] += (i % 2) ^ (dis[i] != -1);
	rep(i, n) if(ret[i] != 'A') ret[i] ^= 1;
	printf("%lld\n%s\n", ans, ret);
	return 0;
}