#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int lim = 200;

int n, m, h, t;
vector <int> neigh[Maxn];
int ares[lim], bres[lim];

bool Test(int v, int u)
{
	int cl = neigh[v].size() - 1 - h;
	int l = 0, r = 0;
	int hasl = 0, hasr = 0;
	while (l < neigh[v].size() && hasl < h && r < neigh[u].size() && hasr < t)
		if (neigh[v][l] == u) l++;
		else if (neigh[u][r] == v) r++;
		else if (neigh[v][l] < neigh[u][r]) { ares[hasl++] = neigh[v][l]; l++; }
		else if (neigh[v][l] == neigh[u][r]) {
				if (cl) { bres[hasr++] = neigh[u][r]; cl--; }
				else ares[hasl++] = neigh[v][l];
				l++; r++;
			} else { bres[hasr++] = neigh[u][r]; r++; }
	while (l < neigh[v].size() && hasl < h)
		if (neigh[v][l] == u) l++;
		else { ares[hasl++] = neigh[v][l]; l++; }
	while (r < neigh[u].size() && hasr < t)
		if (neigh[u][r] == v) r++;
		else { bres[hasr++] = neigh[u][r]; r++; }
	return hasl == h && hasr == t;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &h, &t);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(neigh[i].begin(), neigh[i].end());
	int i, j;
	for (i = 1; i <= n; i++) if (neigh[i].size() >= h + 1) {
		for (j = 0; j < neigh[i].size(); j++) {
			int u = neigh[i][j];
			if (neigh[u].size() < t + 1) continue;
			if (Test(i, u)) break;
		}
		if (j < neigh[i].size()) break;
	}
	if (i > n) printf("NO\n");
	else {
		printf("YES\n");
		printf("%d %d\n", i, neigh[i][j]);
		for (int i = 0; i < h; i++)
			printf("%d%c", ares[i], i + 1 < h? ' ': '\n');
		for (int i = 0; i < t; i++)
			printf("%d%c", bres[i], i + 1 < t? ' ': '\n');
	}
	return 0;
}