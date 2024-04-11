#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100000;

int n;
int deg[Maxn], xr[Maxn];
queue <int> Q;
vector <ii> res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &deg[i], &xr[i]);
		if (deg[i] == 1) Q.push(i);
	}
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		if (deg[v] < 1) continue;
		int u = xr[v]; deg[v]--; xr[v] = 0;
		res.push_back(ii(v, u));
		xr[u] ^= v;
		if (--deg[u] == 1) Q.push(u);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
	return 0;
}