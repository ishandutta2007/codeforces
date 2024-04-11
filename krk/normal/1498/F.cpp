#include <bits/stdc++.h>
using namespace std;

const int Maxm = 40;
const int Maxn = 100005;

int n, k;
vector <int> neigh[Maxn];
int a[Maxn];
vector <int> dp[Maxn], dpup[Maxn], fromup[Maxn];
int res[Maxn];

vector <int> Rotate(const vector <int> &V)
{
	vector <int> res(V.size());
	for (int i = 0; i < V.size(); i++)
		res[(i + 1) % int(V.size())] = V[i];
	return res;
}

void Merge(vector <int> &A, const vector <int> &B)
{
	for (int i = 0; i < A.size(); i++)
		A[i] ^= B[i];
}

void Traverse(int v, int p)
{
	dp[v].resize(2 * k);
	dp[v][0] = a[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		Traverse(u, v);
		dpup[u] = Rotate(dp[u]);
		Merge(dp[v], dpup[u]);
	}
}

void Solve(int v, int p)
{
	Merge(dp[v], fromup[v]);
	int cur = 0;
	for (int i = k; i < dp[v].size(); i++)
		cur ^= dp[v][i];
	res[v] = cur > 0;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		auto tmp = dp[v];
		Merge(tmp, dpup[u]);
		fromup[u] = Rotate(tmp);
		Solve(u, v);
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Traverse(1, 0);
	fromup[1].resize(2 * k, 0);
	Solve(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}