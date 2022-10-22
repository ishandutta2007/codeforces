#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int Maxn = 405;
const int Inf = 1000000000;

struct node {
	int a, b, c;
	node(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
};

int n, m;
bool E[Maxn][Maxn];
vector <int> neigh[Maxn];
int dist[Maxn][Maxn][2];

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		E[a][b] = E[b][a] = true;
	}
	fill((int*)dist, (int*)dist + Maxn * Maxn * 2, Inf);
	dist[1][1][0] = 0;
	queue <node> Q; Q.push(node(1, 1, 0));
	while (!Q.empty()) {
		node p = Q.front(); Q.pop();
		int d = dist[p.a][p.b][p.c]; 
		if (p.c == 0) {
			if (d + 1 < dist[p.a][p.b][1]) {
				dist[p.a][p.b][1] = d + 1; Q.push(node(p.a, p.b, 1));
			}
			for (int i = 1; i <= n; i++)
				if (!E[p.a][i] && d + 1 < dist[i][p.b][1]) {
					dist[i][p.b][1] = d + 1; Q.push(node(i, p.b, 1));
				}
		} else {
			if (d + 1 < dist[p.a][p.b][0] && (p.a != p.b || p.b == n)) {
				dist[p.a][p.b][0] = d + 1; Q.push(node(p.a, p.b, 0));
			}
			for (int i = 1; i <= n; i++)
				if (E[p.b][i] && d + 1 < dist[p.a][i][0] && (p.a != i || i == n)) {
					dist[p.a][i][0] = d + 1; Q.push(node(p.a, i, 0));
				}
		}
	}
	if (dist[n][n][0] != Inf) printf("%d\n", dist[n][n][0] / 2);
	else printf("-1\n");
	return 0;
}