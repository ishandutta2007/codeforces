#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

int n, m, s, t;
bool con[Maxn][Maxn];
int distA[Maxn], distB[Maxn];

void Calc(int v, int dist[])
{
	fill(dist, dist + Maxn, Inf); dist[v] = 0;
	vector <int> Q; Q.push_back(v);
	for (int i = 0; i < Q.size(); i++) {
		v = Q[i];
		for (int j = 1; j <= n; j++) if (con[v][j])
			if (dist[v] + 1 < dist[j]) {
				dist[j] = dist[v] + 1;
				Q.push_back(j);
			}
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		con[a][b] = con[b][a] = true;
	}
	Calc(s, distA); Calc(t, distB);
	int D = distA[t];
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if (!con[i][j])
			if (distA[i] + 1 + distB[j] >= D && distA[j] + 1 + distB[i] >= D)
				res++;
	printf("%d\n", res);
	return 0;
}