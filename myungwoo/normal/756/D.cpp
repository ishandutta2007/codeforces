#include <bits/stdc++.h>
using namespace std;

#define MAXN 5004

const int MOD = (int)1e9 + 7;

int N;
int D[MAXN][MAXN], E[MAXN][MAXN];
int prv[MAXN], rec[26];
char S[MAXN];

int main()
{
	scanf("%d%s", &N, S+1);
	for (int i=1;i<=N;i++){
		prv[i] = rec[S[i]-'a'];
		rec[S[i]-'a'] = i;
	}
	for (int i=1;i<=N;i++){
		if (!prv[i]) D[1][i] = 1;
		E[1][i] = (E[1][i-1] + D[1][i]) % MOD;
	}
	for (int i=2;i<=N;i++){
		for (int j=1;j<=N;j++){
			// for (int k=prv[j]+1;k<=j;k++) D[i][j] = (D[i][j] + D[i-1][k]) % MOD;
			D[i][j] = (E[i-1][j] - E[i-1][prv[j]] + MOD) % MOD;
		}
		for (int j=1;j<=N;j++) E[i][j] = (E[i][j-1] + D[i][j]) % MOD;
	}
	int ans = 0;
	for (int i=1;i<=N;i++) ans = (ans + D[N][i]) % MOD;
	printf("%d\n", ans);
}