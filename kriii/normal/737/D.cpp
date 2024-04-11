#include <stdio.h>
#include <algorithm>
using namespace std;

int N, S[4040];
int prv[2][2040][91], nxt[2][2040][91];

int main()
{
	scanf("%d", &N);
	for (int i=1;i<=N;i++){
		scanf("%d", &S[i]);
		S[i] += S[i-1];
	}

	for (int i=0;i<=N/2;i++){
		for (int j=0;j<=90;j++){
			prv[0][i][j] = 0x80000000;
			prv[1][i][j] = 0x7fffffff;
		}
	}

	for (int k=90;k>=1;k--){
		for (int i=0;i<=N/2;i++){
			for (int j=0;j<=90;j++){
				nxt[0][i][j] = 0x80000000;
				nxt[1][i][j] = 0x7fffffff;
			}
		}

		if (k == 2){
			int c =0;
			c++;
		}
		for (int i=N/2;i>=0;i--){
			for (int j=N+1-i, v=0;i<j&&v<90;j--, v++){
				int &q = nxt[1][i][v];
				int l = j - (i + k);
				if (l >= 1){
					if (l <= k){
						q = S[i+k] - (S[N] - S[j-1]);
					}
					else{
						if (k + 1 < l && k < 90) q = min(q, prv[0][i+k][v+1]);
						q = min(q, nxt[0][i+k][v]);
					}
				}

				int &p = nxt[0][i][v];
				l = j - i;
				if (l <= k){
					p = S[i] - (S[N] - S[j-1]);
				}
				else{
					if (k + 1 < l && k < 90) p = max(p, prv[1][i][v]);
					p = max(p, nxt[1][i][v]);
				}

			}
		}

		for (int i=0;i<=N/2;i++){
			for (int j=0;j<=90;j++){
				prv[0][i][j] = nxt[0][i][j];
				prv[1][i][j] = nxt[1][i][j];
			}
		}
	}

	printf("%d\n", prv[0][0][0]);

	return 0;
}