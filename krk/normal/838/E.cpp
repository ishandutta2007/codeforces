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

typedef long double ld;

const int Maxn = 2505;

ld dp[Maxn][Maxn][2];
int n;
int X[Maxn], Y[Maxn];
ld res;

ld getDist(int a, int b) { return sqrt(ld(X[a] - X[b]) * (X[a] - X[b]) + ld(Y[a] - Y[b]) * (Y[a] - Y[b])); }

ld Solve(int a, int b, int flag)
{
	if (a == b) return 0;
	if (dp[a][b][flag] < 0) {
		int na = (a + 1) % n, pb = (b - 1 + n) % n;
		ld res;
		if (flag == 0) res = max(getDist(a, na) + Solve(na, b, 0), getDist(a, b) + Solve(na, b, 1));
		else res = max(getDist(a, b) + Solve(a, pb, 0), getDist(pb, b) + Solve(a, pb, 1));
		dp[a][b][flag] = res;
	}
	return dp[a][b][flag];
}

int main()
{
	fill((ld*)dp, (ld*)dp + Maxn * Maxn * 2, -1.0l);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	for (int i = 0; i < n; i++) {
		int pi = (i - 1 + n) % n;
		res = max(res, Solve(i, pi, 0));
	}
	cout << fixed << setprecision(15) << res << endl;
	return 0;
}