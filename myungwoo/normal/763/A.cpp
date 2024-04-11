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

#define MAXN 100005

int N;
int A[MAXN];
int par[MAXN];
int D[MAXN], E[MAXN];
vector <int> con[MAXN];

void dfs(int n)
{
	D[n] = A[n];
	for (int t: con[n]) if (t != par[n]){
		par[t] = n; dfs(t);
		if (D[t] != A[n]) D[n] = 0;
	}
}

int dfs2(int n, int from)
{
	bool sw = 1;
	for (int t: con[n]) if (t != par[n]){
		if (!D[t]) sw = 0;
	}
	if (from && sw) return n;
	int diff_cnt = 0, diff_tar = 0;
	if (from >= 0 && from != A[n]) return 0;
	for (int t: con[n]) if (t != par[n]){
		if (A[n] != D[t]) diff_cnt++, diff_tar = t;
	}
	if (diff_cnt > 1) return 0;

	for (int t: con[n]) if (t != par[n]){
		if (diff_tar && diff_tar != t) continue;
		int k = dfs2(t, A[n]);
		if (k) return k;
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<N;i++){
		int a, b; scanf("%d%d", &a, &b);
		con[a].pb(b); con[b].pb(a);
	}
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	dfs(1);
	int ans = dfs2(1, -1);
	if (!ans) puts("NO");
	else printf("YES\n%d\n", ans);
}