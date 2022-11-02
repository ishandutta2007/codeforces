#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define pb push_back

int N;
int A[MAXN], B[MAXN], C[MAXN*2];
vector <int> con[MAXN*2];

void dfs(int n, int c)
{
	C[n] = c;
	for (int t: con[n]) if (!C[t]){
		dfs(t, 3-c);
	}
}

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d%d", A+i, B+i);
		con[A[i]].pb(B[i]);
		con[B[i]].pb(A[i]);
	}
	for (int i=1;i<N+N;i+=2){
		con[i].pb(i+1);
		con[i+1].pb(i);
	}
	for (int i=1;i<=N+N;i++) if (!C[i]){
		dfs(i, 1);
	}
	for (int i=1;i<=N;i++)
		printf("%d %d\n", C[A[i]], C[B[i]]);
}