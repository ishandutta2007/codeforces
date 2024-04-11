#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int mod = 1000000007;

int n;
int V[Maxn];
vector <int> neigh[Maxn];
int cnt[Maxn][2];
int res;

void Traverse(int v, int p, int lvl)
{
	cnt[v][lvl]++;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v, (lvl + 1) % 2);
		cnt[v][0] += cnt[u][0]; cnt[v][1] += cnt[u][1];
	}
}

void Solve(int v, int p, int lvl)
{
	res = (res + ll(n) * V[v]) % mod;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Solve(u, v, (lvl + 1) % 2);
		int my0 = cnt[u][lvl], my1 = cnt[u][1 - lvl];
		int rem = n - (my0 + my1);
		res = (res + ll(rem) * my0 % mod * V[v]) % mod;
		int oth = (mod - V[v]) % mod;
		res = (res + ll(rem) * my1 % mod * oth) % mod;
	}
	int my0 = cnt[1][lvl] - cnt[v][lvl], my1 = cnt[1][1 - lvl] - cnt[v][1 - lvl];
	int rem = n - (my0 + my1);
	res = (res + ll(rem) * my0 % mod * V[v]) % mod;
	int oth = (mod - V[v]) % mod;
	res = (res + ll(rem) * my1 % mod * oth) % mod;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &V[i]);
		V[i] = (V[i] + mod) % mod;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1, 0, 0);
	Solve(1, 0, 0);
	printf("%d\n", res);
	return 0;
}