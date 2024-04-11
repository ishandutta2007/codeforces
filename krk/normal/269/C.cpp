#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, m;
int a[Maxn], b[Maxn], c[Maxn], res[Maxn];
vector <ii> neigh[Maxn];
int st[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		neigh[a[i]].push_back(ii(b[i], i)); neigh[b[i]].push_back(ii(a[i], i));
		st[a[i]] += c[i]; st[b[i]] += c[i];
	}
	queue <int> Q; Q.push(1);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			ii u = neigh[v][i];
			if (!res[u.second]) {
				res[u.second] = v;
				st[u.first] -= 2 * c[u.second];
				if (st[u.first] == 0 && u.first != n) Q.push(u.first);
			}
		}
	}
	for (int i = 0; i < m; i++)
		printf("%d\n", a[i] != res[i]);
	return 0;
}