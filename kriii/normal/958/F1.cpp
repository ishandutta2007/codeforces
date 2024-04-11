#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

void proc()
{
	int N, M;
	scanf("%d %d", &N, &M);

	int U[111], L[111], C = 0;
	for (int i = 0; i < N; i++) scanf("%d", &U[i]);
	for (int i = 1; i <= M; i++) scanf("%d", &L[i]), C += L[i];

	for (int i = 0; i <= N - C; i++) {
		int R[111];
		for (int i = 1; i <= M; i++) R[i] = L[i];
		for (int j = 0; j < C; j++) R[U[i + j]]--;
		int g = 1;
		for (int i = 1; i <= M; i++) if (R[i] != 0) g = 0;
		if (g) {
			puts("YES");
			return;
		}
	}
	puts("NO");
	return;
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