#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld lim = 1e10l;
const int Maxn = 52;
const int Maxm = 5505;

int n, R;
int f[Maxn], s[Maxn], p[Maxn];
ld prob[Maxn];
ld dp[Maxn][Maxm];

ld Solve(ld val)
{
	for (int i = 0; i < Maxm; i++)
		dp[n][i] = i <= R? 0: val;
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j <= R; j++)
			dp[i][j] = min(val, prob[i] * (f[i] + dp[i + 1][j + f[i]]) + (1.0l - prob[i]) * (s[i] + dp[i + 1][j + s[i]]));
		for (int j = R + 1; j < Maxm; j++)
			dp[i][j] = val;
	} 
	return prob[0] * (f[0] + dp[1][f[0]]) + (1.0l - prob[0]) * (s[0] + dp[1][s[0]]);
}

int main()
{
	scanf("%d %d", &n, &R);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &f[i], &s[i], &p[i]);
		prob[i] = ld(p[i]) / 100.0l;
	}
	ld lef = 0, rig = lim;
	for (int i = 0; i < 80; i++) {
		ld mid = (lef + rig) / 2.0l;
		if (Solve(mid) <= mid) rig = mid;
		else lef = mid;
	}
	cout << fixed << setprecision(15) << lef << endl;
	return 0;
}