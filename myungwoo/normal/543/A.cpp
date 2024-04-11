#include <bits/stdc++.h>
using namespace std;

int N, M, B, MOD;
int A[501], D[501][501];

int main()
{
	cin >> N >> M >> B >> MOD;
	for (int i=1;i<=N;i++) scanf("%d", A+i);
	D[0][0] = 1;
	for (int i=1;i<=N;i++){
		for (int j=0;j<M;j++){
			for (int k=0;k<=B-A[i];k++) if (D[j][k]){
				D[j+1][k+A[i]] = (D[j+1][k+A[i]] + D[j][k])%MOD;
			}
		}
	}
	int ans = 0;
	for (int i=0;i<=B;i++) ans = (ans + D[M][i]) % MOD;
	printf("%d\n", ans);
}