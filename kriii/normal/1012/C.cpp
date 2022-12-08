#include <stdio.h>
#include <algorithm>
using namespace std;

int N, H[5050], A[5555][2550],B[2550];

int cost(int h1, int h2)
{
	if (h2 >= h1) return h2 - h1 + 1;
	return 0;
}

int main()
{
	scanf("%d", &N);
	int K = (N + 1) / 2;

	const int non = 0x1fffffff;
	for (int k = 1; k <= K; k++) A[0][k] = B[k] = non;

	for (int i = 1; i <= N; i++) scanf("%d", &H[i]);

	int p = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i >= 2) {
			for (int j = 0; j <= K; j++) if (B[j] > A[i - 2][j]) B[j] = A[i - 2][j];
		}
		for (int k = 1; k <= K; k++) A[i][k] = non;
		for (int k = 1; k <= K; k++){
			if (B[k - 1] != non) {
				A[i][k] = B[k - 1] + cost(H[i], H[i - 1]) + cost(H[i], H[i + 1]);
			}

			if (k >= 2 && i >= 3 && A[i - 2][k - 1] != non) {
				int nc = - cost(H[i - 2], H[i - 1]) + cost(min(H[i-2],H[i]),H[i-1]) + cost(H[i], H[i + 1]);
				if (A[i][k] > A[i - 2][k - 1] + nc)
					A[i][k] = A[i - 2][k - 1] + nc;
			}
		}
		p = !p;
	}
	for (int i = N - 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) if (B[j] > A[i][j]) B[j] = A[i][j];
	}

	for (int i = 1; i <= K; i++) printf("%d ", B[i]);
	return 0;
}