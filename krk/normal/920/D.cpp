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

const int Maxn = 5005;
const int Inf = 1000000000;

int n, k, v;
int a[Maxn];
bool dp[Maxn][Maxn];
bool mark[Maxn];

void Pour(int tims, int v, int u)
{
	if (tims == 0) return;
	printf("%d %d %d\n", tims, v + 1, u + 1);
	a[u] += tims * k; a[v] -= tims * k;
}

void PourAll(int v, int u)
{
	int tims = a[v] / k + bool(a[v] % k);
	if (tims == 0) return;
	printf("%d %d %d\n", tims, v + 1, u + 1);
	a[u] += a[v]; a[v] = 0;
}

int main()
{
	scanf("%d %d %d", &n, &k, &v);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int dif = (sum % k - v % k + k) % k;
	sum -= dif;
	if (sum < v) { printf("NO\n"); return 0; }
	dp[0][0] = true;
	for (int i = 0; i < n; i++) {
		int my = a[i] % k;
		for (int j = 0; j < k; j++) if (dp[i][j])
			dp[i + 1][j] = dp[i + 1][(j + my) % k] = true;
	}
	if (!dp[n][v % k]) { printf("NO\n"); return 0; }
	printf("YES\n");
	vector <int> seq;
	int r = n, c = v % k;
	while (r > 0)
		if (dp[r - 1][c]) r--;
		else {
			seq.push_back(r - 1);
			mark[r - 1] = true;
			int my = a[r - 1] % k;
			c = (c - my + k) % k;
			r--;
		}
	if (seq.empty()) {
		for (int i = 1; i < n; i++)
			PourAll(i, 0);
		Pour(v / k, 0, n - 1);
	} else {
		int r = seq[0];
		for (int i = 0; i < n; i++) if (i != r)
			if (mark[i]) PourAll(i, r);
		int oth = r == 0? 1: 0;
		for (int i = 0; i < n; i++) if (i != oth)
			if (!mark[i]) PourAll(i, oth);
		Pour(a[oth] / k, oth, r);
		Pour((a[r] - v) / k, r, oth);
	}
	return 0;
}