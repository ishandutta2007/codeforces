#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxb = 36;
const int Maxn = 100005;
const ll Inf = 9000000000000000000ll;

int n;
ll k;
int f[Maxn][Maxb];
ll sum[Maxn][Maxb], mn[Maxn][Maxb];

void Print(int v, ll k)
{
	ll tsum = 0, tmn = Inf;
	for (int i = Maxb - 1; i >= 0; i--) if ((1ll << ll(i)) <= k) {
		tsum += sum[v][i]; tmn = min(tmn, mn[v][i]);
		v = f[v][i];
		k -= 1ll << ll(i);
	}
	printf("%I64d %I64d\n", tsum, tmn);
}

int main()
{
	scanf("%d %I64d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &f[i][0]);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &sum[i][0]); mn[i][0] = sum[i][0];
	}
	for (int j = 1; j < Maxb; j++)
		for (int i = 0; i < n; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
			sum[i][j] = sum[i][j - 1] + sum[f[i][j - 1]][j - 1];
			mn[i][j] = min(mn[i][j - 1], mn[f[i][j - 1]][j - 1]);
		}
	for (int i = 0; i < n; i++)
		Print(i, k);
	return 0;
}