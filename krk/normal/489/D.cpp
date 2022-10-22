#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n, m;
vector <int> to[Maxn], from[Maxn];
int has[Maxn][Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		to[a].push_back(b);
		from[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j];
			for (int k = 0; k < to[i].size(); k++) {
				int u = to[i][k];
				if (v != u) has[v][u]++;
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (i != j)
			res += ll(has[i][j]) * (has[i][j] - 1) / 2;
	printf("%I64d\n", res);
	return 0;
}