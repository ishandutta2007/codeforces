#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 200005

int N, M, Q, K, T;
int H[MAXN], up[MAXN];
int TN[MAXN], G[MAXN];
bool is_bridge[MAXN], is_down[MAXN];
int par[MAXN][18], HBCC[MAXN];
int goup[MAXN], godown[MAXN];

vector <int> con[MAXN], cone[MAXN], conb[MAXN];

void dfs(int n, int fr, int fre, int group_num)
{
	TN[n] = group_num;
	up[n] = H[n];
	for (int i=sz(con[n]);i--;){
		int e = cone[n][i], t = con[n][i];
		if (fre == e) continue;
		if (!H[t]){
			H[t] = H[n]+1; dfs(t, n, e, group_num);
			is_down[e] = 1;
		}else{
			up[n] = min(up[n], H[t]);
		}
	}
	if (up[n] == H[n] && H[n] > 1) is_bridge[fre] = 1;
}

void color(int n, int c)
{
	G[n] = c;
	for (int i=sz(con[n]);i--;){
		int e = cone[n][i], t = con[n][i];
		if (G[t] || is_bridge[e]) continue;
		color(t, c);
	}
}

void make_tree(int n)
{
	for (int i=sz(con[n]);i--;){
		int e = cone[n][i], t = con[n][i];
		if (!is_down[e] || H[t] < H[n]) continue;
		if (G[t] != G[n]){
			par[G[t]][0] = G[n];
			HBCC[G[t]] = HBCC[G[n]] + 1;
		}
		make_tree(t);
	}
}

void bcc()
{
	for (int i=1;i<=N;i++) if (!H[i]){
		H[i] = 1; dfs(i, 0, 0, ++T);
	}
	for (int i=1;i<=N;i++) if (!G[i]){
		color(i, ++K);
	}
	for (int i=1;i<=N;i++) if (H[i] == 1){
		par[G[i]][0] = G[i];
		HBCC[G[i]] = 1;
		make_tree(i);
	}
	for (int j=1;j<18;j++) for (int i=1;i<=K;i++) par[i][j] = par[par[i][j-1]][j-1];
}

int LCA(int a, int b)
{
	if (HBCC[a] < HBCC[b]) swap(a, b);
	for (int i=18;i--;) if ((HBCC[a]-HBCC[b]) & (1 << i)) a = par[a][i];
	if (a == b) return a;
	for (int i=18;i--;) if (par[a][i] != par[b][i])
		a = par[a][i], b = par[b][i];
	return par[a][0];
}

bool check_error(int n, int &gup, int &gdown)
{
	gup = goup[n], gdown = godown[n];
	for (int t: conb[n]){
		int u, d;
		if (!check_error(t, u, d)) return 0;
		put_max(gup, max(0, u-1));
		put_max(gdown, max(0, d-1));
	}
	if (gup && gdown) return 0;
	return 1;
}

int main()
{
	scanf("%d%d%d", &N, &M, &Q);
	for (int i=1;i<=M;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		con[a].pb(b); cone[a].pb(i);
		con[b].pb(a); cone[b].pb(i);
	}
	bcc();
	/*
	for (int i=1;i<=N;i++) printf("%d: bcc %d, forest %d\n", i, G[i], TN[i]);
	for (int i=1;i<=K;i++) printf("Parent's of bcc %d is bcc %d\n", i, par[i][0]);
	*/
	bool ans = 1;
	while (Q--){
		int a, b;
		scanf("%d%d", &a, &b);
		if (TN[a] != TN[b]){ puts("No"); return 0; }
		a = G[a], b = G[b];
		if (a == b) continue;
		int c = LCA(a, b);
		put_max(goup[a], HBCC[a]-HBCC[c]);
		put_max(godown[b], HBCC[b]-HBCC[c]);
	}
	for (int i=1;i<=K;i++) if (par[i][0] != i){
		conb[par[i][0]].pb(i);
	}
	for (int i=1;i<=K;i++) if (par[i][0] == i){
		int a, b;
		ans &= check_error(i, a, b);
	}
	puts(ans ? "Yes" : "No");
}