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

const int non = 500000000;
int N, K, P, A[500020], D[500020][105], BIT[101];

void in(int x, int p)
{
	x++;
	while (x <= P) {
		if (BIT[x] > p)
			BIT[x] = p;
		x += x & (-x);
	}
}

int out(int x)
{
	x++;
	int r = non;
	while (x) {
		if (r > BIT[x])
			r = BIT[x];
		x -= x & (-x);
	}
	return r;
}

void proc()
{
	scanf("%d %d %d", &N, &K, &P);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]), D[i][0] = non, A[i] = (A[i] + A[i-1]) % P;
	D[0][0] = 0;

	for (int k = 1; k <= K; k++) {
		for (int i = 0; i <= N; i++) D[i][k] = non;
		for (int j = 1; j <= P; j++) BIT[j] = non;
		
		int last = non;
		for (int i = 1; i <= N; i++) {
			in(A[i - 1], D[i - 1][k - 1] - A[i - 1]);
			if (last > D[i - 1][k - 1] - A[i - 1])
				last = D[i - 1][k - 1] - A[i - 1];

			int u = min(A[i] + out(A[i]), last + P+A[i]);
			if (D[i][k] > u)
				D[i][k] = u;
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