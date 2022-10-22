#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 5005;
const int Inf = 1000000007;

int n, m, t;
vector <ii> neigh[Maxn];
int dist[Maxn][Maxn];
short par[Maxn][Maxn];
vector <int> res;

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		neigh[a].push_back(ii(b, c));
	}
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf); dist[1][1] = 0;
	priority_queue <iii> Q; Q.push(iii(0, ii(1, 1)));
	while (!Q.empty()) {
		ii v = Q.top().second; int d = -Q.top().first; Q.pop();
		if (dist[v.first][v.second] != d) continue;
		for (int i = 0; i < neigh[v.first].size(); i++) {
			ii u = neigh[v.first][i];
			if (d + u.second < dist[u.first][v.second + 1]) {
				dist[u.first][v.second + 1] = d + u.second;
				par[u.first][v.second + 1] = v.first;
				Q.push(iii(-dist[u.first][v.second + 1], ii(u.first, v.second + 1)));
			}
		}
	}
	int r = n, c = n;
	while (dist[r][c] > t) c--;
	while (c) {
		res.push_back(r);
		r = par[r][c];
		c--;
	}
	printf("%d\n", res.size());
	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
	return 0;
}