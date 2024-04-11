#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
vector <ii> neigh[Maxn];
int dp[Maxn][2];
int nd[Maxn];
vector <int> res;

void Traverse(int v, int p)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		Traverse(u.first, v);
		dp[v][0] += dp[u.first][0]; dp[v][1] += dp[u.first][1];
		dp[v][u.second]++;
	}
}

void Calc(int v, int p, int tome)
{
	nd[v] = dp[v][1] + tome;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p) continue;
		if (u.second == 0) Calc(u.first, v, tome + dp[v][1] - dp[u.first][1] + 1);
		else Calc(u.first, v, tome + dp[v][1] - dp[u.first][1] - 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, 0)); neigh[b].push_back(ii(a, 1));
	}
	Traverse(1, 0);
	Calc(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		if (!res.empty() && nd[i] < nd[res.back()]) res.clear();
		if (res.empty() || nd[i] == nd[res.back()]) res.push_back(i);
	}
	printf("%d\n", nd[res.back()]);
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}