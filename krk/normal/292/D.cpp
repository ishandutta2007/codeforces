#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int n, m;
vector <ii> neigh[Maxn];
int k;
int l, r;
bool taken[Maxn];
int res;

void Traverse(int v)
{
	taken[v] = true;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if ((u.second < l || u.second > r) && !taken[u.first])
			Traverse(u.first);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i)); neigh[b].push_back(ii(a, i));
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &l, &r);
		fill(taken + 1, taken + n + 1, false);
		res = 0;
		for (int i = 1; i <= n; i++) if (!taken[i]) {
			res++; Traverse(i);
		}
		printf("%d\n", res);
	}
	return 0;
}