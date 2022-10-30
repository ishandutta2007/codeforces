#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006
#define pb push_back

int T, N, M;
int X[MAXN], Y[MAXN];
bool vis[MAXN];
vector <int> con[MAXN];

int dfs(int n)
{
	vis[n] = 1;
	int ret = 1;
	for (int t: con[n]) if (!vis[t]) ret += dfs(t);
	return ret;
}

bool proc(bool rev)
{
	for (int i=1;i<=N;i++) con[i].clear(), vis[i] = 0;
	for (int i=1;i<=M;i++){
		if (rev) con[Y[i]].pb(X[i]);
		else con[X[i]].pb(Y[i]);
	}
	int res = dfs(1);
	if (rev) for (int i=1;i<=N;i++) vis[i] ^= 1;
	return res < N;
}

int main()
{
	for (scanf("%d", &T);T--;){
		scanf("%d%d", &N, &M);
		for (int i=1;i<=M;i++) scanf("%d%d", X+i, Y+i);
		if (proc(0) || proc(1)){
			puts("Yes");
			int cnt = 0;
			for (int i=1;i<=N;i++) if (vis[i]) cnt++;
			printf("%d %d\n", cnt, N-cnt);
			for (int i=1;i<=N;i++) if (vis[i]) printf("%d ", i); puts("");
			for (int i=1;i<=N;i++) if (!vis[i]) printf("%d ", i); puts("");
		}else puts("No");
	}
}