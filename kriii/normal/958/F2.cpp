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

int U[211111], L[211111];
void proc()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) scanf("%d", &U[i]);
	for (int i = 1; i <= M; i++) scanf("%d", &L[i]);

	int ans = 0x7fffffff, c = 0, v = 0;
	for (int i = 1; i <= M; i++) if (L[i] == 0) c++;
	for (int i = 0, j = 0; i < N; i++) {
		while (j < N && c < M) {
			if (L[U[j]] <= 0) {
				c--;
				v += L[U[j]];
			}
			L[U[j]]--;
			if (L[U[j]] <= 0) {
				c++;
				v -= L[U[j]];
			}
			j++;
		}

		if (c == M) {
			if (ans > v)
				ans = v;
		}
		if (L[U[i]] <= 0) {
			c--;
			v += L[U[i]];
		}
		L[U[i]]++;
		if (L[U[i]] <= 0) {
			c++;
			v -= L[U[i]];
		}
	}

	if (ans == 0x7fffffff) ans = -1;
	printf("%d\n", ans);
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