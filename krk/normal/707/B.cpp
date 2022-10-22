#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 100005;
const int Inf = 1000000005;

int n, m, k;
int A[Maxn], B[Maxn], C[Maxn];
bool spec[Maxm];
int res = Inf;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &A[i], &B[i], &C[i]);
	for (int i = 0; i < k; i++) {
		int v; scanf("%d", &v);
		spec[v] = true;
	}
	for (int i = 0; i < m; i++)
		if (spec[A[i]] + spec[B[i]] == 1) res = min(res, C[i]);
	printf("%d\n", res == Inf? -1: res);
	return 0;
}