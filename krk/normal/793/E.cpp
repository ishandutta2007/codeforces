#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxd = 4;
const int Maxm = 10015;
const int nil = Maxn;

int n;
int my[Maxd];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn], flag[Maxn], cnt[Maxn];
bool dp[2][Maxm], tmp[Maxm];

void Add(bool dp[], int val)
{
	for (int i = 0; i < Maxm; i++)
		tmp[i] = i >= val && dp[i - val] || i + val < Maxm && dp[i + val];
	for (int i = 0; i < Maxm; i++) {
		dp[i] = tmp[i]; tmp[i] = false;
	}
}

void Traverse(int v)
{
	lef[v] = ++cur;
	cnt[v] = neigh[v].size() == 0? 1: 0;
	for (int i = 0; i < Maxd; i++)
		if (v == my[i]) flag[v] |= 1 << i;
	for (int i = 0; i < neigh[v].size(); i++) {
		Traverse(neigh[v][i]); flag[v] |= flag[neigh[v][i]];
		cnt[v] += cnt[neigh[v][i]];
	}
	rig[v] = cur;
}

void Solve(int v, bool dp[])
{
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (flag[u] == 0) Add(dp, cnt[u]);
		else Solve(u, dp);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < Maxd; i++)
		scanf("%d", &my[i]);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
	}
	Traverse(1);
	int mya = nil, myb = nil;
	for (int i = 0; i < neigh[1].size(); i++) {
		int v = neigh[1][i];
		if (flag[v] == 1 << 0) myb -= cnt[v];
		else if (flag[v] == 1 << 1) myb += cnt[v];
		else if (flag[v] == 1 << 2) mya += cnt[v];
		else if (flag[v] == 1 << 3) mya -= cnt[v];
	}
	dp[0][mya] = true; dp[1][myb] = true;
	for (int i = 0; i < neigh[1].size(); i++) {
		int v = neigh[1][i];
		if (flag[v] == (1 << 0) || flag[v] == (1 << 1)) Solve(v, dp[0]);
		else if (flag[v] == (1 << 2) || flag[v] == (1 << 3)) Solve(v, dp[1]);
		else {
			Add(dp[0], cnt[v]);
			Add(dp[1], cnt[v]);
		}
	}
	printf("%s\n", (dp[0][nil] && dp[1][nil])? "YES": "NO");
	return 0;
}