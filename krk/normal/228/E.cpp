#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, m;
vector <ii> neigh[Maxn];
int col[Maxn];
bool ok = true;
vector <int> res;

bool isOk(int v, int c)
{
	if (col[v] == c) return true;
	if (col[v] == -c) return false;
	col[v] = c; if (c > 0) res.push_back(v);
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.second == 0 && !isOk(u.first, -c) || u.second == 1 && !isOk(u.first, c))
			return false;
	} 
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c)); neigh[b].push_back(ii(a, c));
	}
	for (int i = 1; i <= n && ok; i++) if (!col[i])
		ok = isOk(i, 1);
	if (ok) {
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); i++)
			printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	} else printf("Impossible\n");
	return 0;
}