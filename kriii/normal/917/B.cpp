#include <stdio.h>

bool chk[30][101][101], win[30][101][101];
int N, M, c[101][101];

bool get(int k, int i, int j)
{
	if (!chk[k][i][j]){
		chk[k][i][j] = 1;
		for (int l=1;l<=N;l++) if (c[i][l] >= k){
			if (!get(c[i][l], j, l)){
				win[k][i][j] = 1;
				break;
			}
		}
	}
	return win[k][i][j];
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i=0;i<M;i++){
		int x, y; char S[10];
		scanf("%d %d %s", &x, &y, S);
		c[x][y] = S[0] - 'a' + 1;
	}

	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			putchar(get(1, i, j)?'A':'B');
		}
		puts("");
	}

	return 0;
}