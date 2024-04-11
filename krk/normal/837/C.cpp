#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, a, b;
int X[Maxn], Y[Maxn];
int res;

bool Solve(int X1, int Y1, int X2, int Y2)
{
	return max(X1, X2) <= a && Y1 + Y2 <= b ||
			X1 + X2 <= a && max(Y1, Y2) <= b;
}

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (Solve(X[i], Y[i], X[j], Y[j]) || Solve(X[i], Y[i], Y[j], X[j]) ||
				Solve(Y[i], X[i], X[j], Y[j]) || Solve(Y[i], X[i], Y[j], X[j]))
				res = max(res, X[i] * Y[i] + X[j] * Y[j]);
	printf("%d\n", res);
	return 0;
}