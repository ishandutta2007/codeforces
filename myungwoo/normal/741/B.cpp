#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003
#define pb push_back

int N, M, W;
int par[MAXN];
int A[MAXN], B[MAXN];
int P[MAXN], Q[MAXN];
int D[MAXN], E[MAXN];
vector <int> con[MAXN];

int cp(int n){ return par[n] == n ? n : (par[n] = cp(par[n])); }

int main()
{
	scanf("%d%d%d", &N, &M, &W);
	for (int i=1;i<=N;i++)
		scanf("%d", A+i);
	for (int i=1;i<=N;i++)
		scanf("%d", B+i);
	for (int i=1;i<=N;i++){
		P[i] = A[i];
		Q[i] = B[i];
		par[i] = i;
		con[i] = {i};
	}
	for (int i=1;i<=M;i++){
		int a, b; scanf("%d%d", &a, &b);
		a = cp(a), b = cp(b);
		if (a == b) continue;
		par[b] = a; A[a] += A[b]; B[a] += B[b];
		for (int t: con[b])
			con[a].pb(t);
	}
	for (int i=1;i<=N;i++) if (cp(i) == i){
		for (int j=W-A[i];j>=0;j--)
			E[j+A[i]] = max(E[j+A[i]], D[j]+B[i]);
		for (int t: con[i]){
			for (int j=W-P[t];j>=0;j--)
				E[j+P[t]] = max(E[j+P[t]], D[j]+Q[t]);
		}
		for (int j=0;j<=W;j++)
			D[j] = E[j];
	}
	printf("%d\n", D[W]);
}