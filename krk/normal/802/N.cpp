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

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 2250;
const ll Inf = 1000000000000000000ll;

int n, k;
int N;
int R[Maxn][Maxn], C[Maxn][Maxn];
vector <int> neigh[Maxn];
ll dist[Maxn];
int par[Maxn];
ll res;

void addEdge(int a, int b, int cap, int cost)
{
	neigh[a].push_back(b); neigh[b].push_back(a);
	R[a][b] = cap; C[a][b] = cost; C[b][a] = -cost;
}

ll getFlow()
{
	fill(dist, dist + N, Inf); dist[0] = 0;
	priority_queue <lli> Q; Q.push(lli(-dist[0], 0));
	while (!Q.empty()) {
		int v = Q.top().second;
		ll d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (R[v][u] > 0 && d + C[v][u] < dist[u]) {
				dist[u] = d + C[v][u]; par[u] = v;
				Q.push(lli(-dist[u], u));
			}
		}
	}
	ll res = dist[N - 1];
	int v = N - 1;
	while (v) {
		int u = par[v];
		R[u][v]--; R[v][u]++;
		v = u;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	N = n + 2;
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		addEdge(0, i, 1, a);
	}
	for (int i = 1; i <= n; i++) {
		int b; scanf("%d", &b);
		addEdge(i, N - 1, 1, b);
	}
	for (int i = 1; i + 1 <= n; i++)
		addEdge(i, i + 1, n - i, 0);
	while (k--) {
		ll cost = getFlow();
		res += cost;
	}
	printf("%I64d\n", res);
	return 0;
}