#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back
#define sz(v) ((int)(v).size())

int N;
int cnt[MAXN];
bool V[MAXN];
vector <int> con[MAXN];

void dfs(int n)
{
	V[n] = 1;
	for (int t: con[n]) if (!V[t] && sz(con[t]) < 3)
		dfs(t);
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<N;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		con[a].pb(b); con[b].pb(a);
	}
	for (int i=1;i<=N;i++) if (sz(con[i]) == 1 && !V[i]) dfs(i);
	for (int i=1;i<=N;i++) if (!V[i])
		for (int t: con[i]) if (V[t])
			cnt[i] = min(cnt[i]+1, 2);
	for (int i=1;i<=N;i++) if (!V[i]){
		int deg = 0;
		for (int t: con[i]) if (!V[t] && sz(con[t]) - cnt[t] > 1)
			deg++;
		if (deg > 2){ puts("No"); return 0; }
	}
	puts("Yes");
}