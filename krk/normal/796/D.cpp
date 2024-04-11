#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 300005;

int n, k, d;
bool spec[Maxn];
int a[Maxn], b[Maxn];
int dist[Maxn], col[Maxn];
vector <int> neigh[Maxn];
vector <int> res;

int main()
{
	scanf("%d %d %d", &n, &k, &d);
	while (k--) {
		int a; scanf("%d", &a);
		spec[a] = true;
	}
	for (int i = 1; i <= n - 1; i++) {
		scanf("%d %d", &a[i], &b[i]);
		neigh[a[i]].push_back(b[i]);
		neigh[b[i]].push_back(a[i]);
	}
	fill(dist, dist + Maxn, Maxn);
	queue <int> Q;
	for (int i = 1; i <= n; i++) if (spec[i]) {
		dist[i] = 0; col[i] = i;
		Q.push(i);
	}
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1; col[u] = col[v];
				Q.push(u);
			}
		}
	}
	for (int i = 1; i <= n - 1; i++)
		if (col[a[i]] != col[b[i]]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}