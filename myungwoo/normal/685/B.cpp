#include <bits/stdc++.h>
using namespace std;

#define MAXN 300005
#define pb push_back
#define sz(v) ((int)(v).size())

int N, Q;
int P[MAXN], S[MAXN], T[MAXN][19];
vector <int> con[MAXN];

void dfs(int n)
{
	S[n] = 1;
	int mx = 0, mxt = 0;
	for (int t: con[n]){
		dfs(t);
		S[n] += S[t];
		if (mx < S[t]) mx = S[t], mxt = t;
	}
	T[n][0] = mxt;
	for (int i=1;i<19;i++) T[n][i] = T[T[n][i-1]][i-1];
}

int main()
{
	scanf("%d%d", &N, &Q);
	for (int i=2;i<=N;i++) scanf("%d", P+i), con[P[i]].pb(i);
	dfs(1);
	while (Q--){
		int n; scanf("%d", &n);
		int m = S[n], t = n, b = m>>1;
		if (S[t] <= b){ printf("%d\n", t); continue; } 
		for (int i=19;i--;){
			if (S[T[t][i]] > b) t = T[t][i];
		}
		int v = max(S[T[t][0]], m - S[t]);
		if (v > b) for (;;);
		printf("%d\n", t);
	}
}