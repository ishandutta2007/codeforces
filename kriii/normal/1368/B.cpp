#include <stdio.h>

const int L = 400;
long long d[11][L+1]; int v[11][L+1];

int main()
{
	d[0][0] = 1;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j <= L; j++) if (d[i][j]){
			for (int k = 1; j + k <= L; k++){
				if (d[i + 1][j + k] < d[i][j] * k){
					d[i + 1][j + k] = d[i][j] * k;
					v[i + 1][j + k] = k;
				}
			}
		}
	}

	long long k; scanf ("%lld", &k);
	for (int l = 1; l <= L; l++) if (d[10][l] >= k){
		char *str = "codeforces";
		int i = 10, j = l;
		while (i){
			int u = v[i][j];
			i--; j -= u;
			while (u--) putchar(str[9 - i]);
		}
		puts("");
		break;
	}
	return 0;
}