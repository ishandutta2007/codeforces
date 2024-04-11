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

typedef long long ll;

const int Maxn = 505;
const int mod = 1000000007;

int n;
int A[Maxn][Maxn];
int dp1[Maxn][Maxn], dp2[Maxn][Maxn];
int res;

int getDP2(int lef, int rig);

int getDP1(int lef, int rig)
{
	if (lef == rig) return 1;
	if (dp1[lef][rig] < 0) {
		int res = 0;
		for (int i = lef + 1; i <= rig; i++) if (A[lef][i])
			res = (res + ll(getDP2(lef, i)) * getDP1(i, rig)) % mod;
		return dp1[lef][rig] = res;
	}
	return dp1[lef][rig];
}

int getDP2(int lef, int rig)
{
	if (lef + 1 == rig) return 1;
	if (dp2[lef][rig] < 0) {
		int res = getDP1(lef, rig - 1);
		for (int i = lef + 1; i < rig; i++) if (A[rig][i])
			res = (res + ll(getDP2(lef, i)) * getDP2(i, rig)) % mod;
		return dp2[lef][rig] = res;
	}
	return dp2[lef][rig];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	fill((int*)dp1, (int*)dp1 + Maxn * Maxn, -1);
	fill((int*)dp2, (int*)dp2 + Maxn * Maxn, -1);
	for (int i = 1; i < n; i++) if (A[0][i])
		res = (res + ll(getDP1(i, n - 1)) * getDP2(0, i)) % mod;
	printf("%d\n", res);
	return 0;
}