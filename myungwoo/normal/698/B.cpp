#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

int N;
int A[MAXN], C[MAXN];
bool V[MAXN];

int dfs(int n)
{
	if (C[n]) return C[n];
	if (V[n]) return C[n] = n;
	V[n] = 1;
	return C[n] = dfs(A[n]);
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	for (int i=1;i<=N;i++) dfs(i);
	int root = 0;
	for (int i=1;i<=N;i++) if (C[i] == i){
		if (A[i] == i) root = i;
	}
	int ans = 0;
	if (!root){
		for (int i=1;i<=N;i++) if (C[i] == i){
			ans++;
			A[i] = i;
			root = i;
			break;
		}
	}
	for (int i=1;i<=N;i++) if (C[i] == i && i != root){
		ans++;
		A[i] = root;
	}
	printf("%d\n", ans);
	for (int i=1;i<=N;i++) printf("%d ", A[i]); puts("");
}