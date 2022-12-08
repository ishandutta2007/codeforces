#include <stdio.h>

int N,M,C[1001001],P[10][10];

int main()
{
	int ans = 0;

	scanf ("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		int x; scanf ("%d",&x);
		C[x]++;
		if (C[x] >= 9){
			ans++;
			C[x] -= 3;
		}
	}

	for (int i=0;i<9;i++) for (int j=0;j<9;j++) P[i][j] = -10000000;
	P[0][0] = ans;
	for (int t=1;t<=M;t++){
		int V[10][10];
		for (int i=0;i<9;i++) for (int j=0;j<9;j++) V[i][j] = -10000000;
		for (int i=0;i<9;i++) for (int j=0;j<9;j++){
			for (int k=0;k<=C[t];k++) if (i >= k && j >= k){
				int u = P[i][j] + k + (i - k) / 3;
				if (V[j-k][C[t]-k] < u)
					V[j-k][C[t]-k] = u;
			}
		}
		for (int i=0;i<9;i++) for (int j=0;j<9;j++) P[i][j] = V[i][j];
	}
	for (int i=0;i<9;i++) for (int j=0;j<9;j++){
		int u = P[i][j] + i / 3 + j / 3;
		if (ans < u)
			ans = u;
	}
	printf ("%d\n",ans);

	return 0;
}