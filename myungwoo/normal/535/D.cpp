#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006
typedef long long lld;

const int MOD = 1e9+7;
int N, M, K;
char P[MAXN];
int A[MAXN], ff[MAXN][20];

void get_ff()
{
	for (int i=2,k=0;i<=M;i++){
		while (k && P[k+1] != P[i]) k = ff[k][0];
		if (P[k+1] == P[i]) k++;
		ff[i][0] = k;
	}
	for (int i=1;i<20;i++) for (int j=1;j<=M;j++){
		ff[j][i] = ff[ff[j][i-1]][i-1];
	}
}

int main()
{
	scanf("%d%d%s", &N, &K, P+1), M = strlen(P+1);
	for (int i=1;i<=K;i++) scanf("%d", A+i);
	bool invalid = 0;
	get_ff();
	for (int i=1;i<K;i++) if (A[i] > A[i+1]-M){
		int pre_len = A[i+1]-A[i];
		int mid_len = M-pre_len, p = M;
		for (int j=20;j--;){
			if (ff[p][j] > mid_len) p = ff[p][j];
		}
		if (ff[p][0] != mid_len){
			invalid = 1; break;
		}
	}
	if (invalid){ puts("0"); return 0; }

	A[++K] = N+1;
	int free_cnt = A[1]-1;
	for (int i=1;i<K;i++){
		if (A[i+1]-A[i] > M) free_cnt += A[i+1]-A[i]-M;
	}
	int ans = 1;
	for (int i=0;i<free_cnt;i++) ans = (lld)ans * 26 % MOD;
	printf("%d\n", ans);
}