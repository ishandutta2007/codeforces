#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void proc()
{
	int N;
	scanf("%d", &N);

	char A[11][11], B[11][11];
	for (int i = 0; i < N; i++) scanf("%s", A[i]);
	for (int i = 0; i < N; i++) scanf("%s", B[i]);

	for (int k = 0; k < 2; k++) {
		for (int t = 0; t < 4; t++) {
			char T[11][11];
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) T[j][N - i - 1] = A[i][j];
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) A[i][j] = T[i][j];

			bool g = 1;
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (A[i][j] != B[i][j]) g = 0;
			if (g) {
				puts("Yes");
				return;
			}
		}
		char T[11][11];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) T[i][N - j - 1] = A[i][j];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) A[i][j] = T[i][j];
	}
	puts("No");
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}