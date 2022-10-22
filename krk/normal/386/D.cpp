#include <cstdio>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 72;
const int Maxs = 3;
const int a[Maxs] = {1, 0, 0};
const int b[Maxs] = {2, 2, 1};

struct vert {
	int x[Maxs];
};

int n;
char B[Maxn][Maxn];
int dist[Maxn][Maxn][Maxn];
ii par[Maxn][Maxn][Maxn];
queue <vert> Q;

bool End(vert v)
{
	sort(v.x, v.x + Maxs);
	return v.x[0] == 1 && v.x[1] == 2 && v.x[2] == 3;
}

void Print(const vert &v)
{
	if (dist[v.x[0]][v.x[1]][v.x[2]] == 0) return;
	ii p = par[v.x[0]][v.x[1]][v.x[2]];
	vert u = v; u.x[p.first] = p.second;
	Print(u);
	printf("%d %d\n", u.x[p.first], v.x[p.first]);
}

int main()
{
	fill((int*)dist, (int*)dist + Maxn * Maxn * Maxn, Inf);
	scanf("%d", &n);
	vert v;
	for (int i = 0; i < Maxs; i++)
		scanf("%d", &v.x[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf(" %c", &B[i][j]);
	dist[v.x[0]][v.x[1]][v.x[2]] = 0; Q.push(v);
	while (!Q.empty()) {
		v = Q.front(); int d = dist[v.x[0]][v.x[1]][v.x[2]]; Q.pop();
		if (End(v)) { printf("%d\n", d); Print(v); return 0; }
		vert u;
		for (int i = 0; i < 3; i++) {
			u = v;
			for (u.x[i] = 1; u.x[i] <= n; u.x[i]++) 
				if (u.x[i] != u.x[a[i]] && u.x[i] != u.x[b[i]] && B[v.x[i]][u.x[i]] == B[u.x[a[i]]][u.x[b[i]]] &&
					d + 1 < dist[u.x[0]][u.x[1]][u.x[2]]) {
					dist[u.x[0]][u.x[1]][u.x[2]] = d + 1; 
					par[u.x[0]][u.x[1]][u.x[2]] = ii(i, v.x[i]);
					Q.push(u);
				}
		}
	}
	printf("-1\n");
	return 0;
}