#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int non = -50000000;
int N, K, P, A[20020], D[20020][55], R[100];

void proc()
{
	scanf("%d %d %d", &N, &K, &P);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]), D[i][0] = non, A[i] = (A[i] + A[i-1]) % P;
	D[0][0] = 0;

	for (int k = 1; k <= K; k++) {
		for (int i = 0; i <= N; i++) D[i][k] = non;
		for (int j = 0; j < P; j++) R[j] = non;
		
		for (int i = 1; i <= N; i++) {
			if (R[A[i-1]] < D[i-1][k-1])
				R[A[i-1]] = D[i-1][k-1];
			for (int j = 0; j < P; j++) if (R[j] != non) {
				int u = R[j] + (A[i] - j + P) % P;
				if (D[i][k] < u)
					D[i][k] = u;
			}
		}
	}

	printf("%d\n", D[N][K]);
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