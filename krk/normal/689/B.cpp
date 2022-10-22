#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int Maxn = 200005;
const int Inf = 1000000000;

int n;
int a[Maxn];
int dist[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	fill(dist, dist + n + 1, Inf); dist[1] = 0;
	queue <int> Q; Q.push(1);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		for (int i = -1; i <= 1; i += 2) {
			int u = v + i;
			if (1 <= u && u <= n && dist[v] + 1 < dist[u]) {
				dist[u] = dist[v] + 1; Q.push(u);
			}
		}
		int u = a[v];
		if (dist[v] + 1 < dist[u]) {
			dist[u] = dist[v] + 1; Q.push(u);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", dist[i], i + 1 <= n? ' ': '\n');
	return 0;
}