#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxb = 20;

int bits[1 << Maxb];
int n, m;
vector <int> neigh[Maxn];
int in[Maxn];
int b;
int dp[Maxn];
vector <int> mask;
bool found;

void Solve(int v)
{
	if (dp[v]) return;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Solve(u);
		dp[v] |= dp[u];
	}
}

void Gen(int lvl, int cnt, int global)
{
	if (lvl >= mask.size()) {
		if (cnt > 0 && cnt < mask.size() && bits[global] == cnt)
			found = true;
	} else {
		Gen(lvl + 1, cnt, global);
		Gen(lvl + 1, cnt + 1, global | mask[lvl]);
	}
}

int main()
{
	for (int i = 0; i < 1 << Maxb; i++)
		bits[i] = __builtin_popcount(i);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		in[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (neigh[i].empty()) {
			dp[i] = 1 << b;
			b++;
		}
	for (int i = 1; i <= n; i++) {
		Solve(i);
		if (in[i] == 0) mask.push_back(dp[i]);
	}
	Gen(0, 0, 0);
	printf("%s\n", found? "NO": "YES");
    return 0;
}