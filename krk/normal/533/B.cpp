#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n;
vector <int> neigh[Maxn];
int val[Maxn];
ll my[Maxn][2], tot[Maxn];

void Traverse(int v)
{
	ll cur[2];
	my[v][0] = 0; my[v][1] = -Inf;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		Traverse(u);
		cur[0] = max(my[v][0] + my[u][0], my[v][1] + my[u][1]);
		cur[1] = max(my[v][0] + my[u][1], my[v][1] + my[u][0]);
		my[v][0] = cur[0]; my[v][1] = cur[1];
	}
	my[v][1] = max(my[v][1], my[v][0] + val[v]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p; scanf("%d %d", &p, &val[i]);
		if (p != -1) neigh[p].push_back(i);
	}
	Traverse(1);
	printf("%I64d\n", max(my[1][0], my[1][1]));
	return 0;
}