#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, K, P[400400], S[400400];

int find(int x)
{
	if (P[x] != x) P[x] = find(P[x]);
	return P[x];
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N + M; i++) {
		P[i] = i; S[i] = 1;
	}
	for (int i = 0; i < K; i++) {
		int x, y; scanf("%d %d", &x, &y);
		x--; y--; y += N;
		x = find(x); y = find(y);
		if (x != y) {
			P[x] = y;
			S[y] += S[x];
		}
	}

	int ans = -1;
	for (int i = 0; i < N + M; i++) {
		if (find(i) == i) ans++;
	}

	printf("%d\n", ans);
	return 0;
}