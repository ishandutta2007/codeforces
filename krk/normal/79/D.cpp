#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 10005;
const int Maxk = 12;
const int Maxl = 105;
const int MaxN = 1 << 20;

int n, k, l;
int x[Maxn];
int a[Maxl];
vector <int> V;
int dist[2 * Maxk][Maxn];
int dp[MaxN];

void BFS(int ind, int st)
{
	fill(dist[ind], dist[ind] + Maxn, Inf); dist[ind][st] = 0;
	queue <int> Q; Q.push(st);
	while (!Q.empty()) {
		int v = Q.front(), d = dist[ind][v]; Q.pop();
		for (int i = 0; i < l; i++) {
			int u = v + a[i];
			if (u <= n && d + 1 < dist[ind][u]) { dist[ind][u] = d + 1; Q.push(u); }
			u = v - a[i];
			if (u >= 0 && d + 1 < dist[ind][u]) { dist[ind][u] = d + 1; Q.push(u); }
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &k, &l);
	while (k--) {
		int onx; scanf("%d", &onx);
		x[onx] = 1;
	}
	for (int i = 0; i < l; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		if (x[i] != x[i + 1]) {
			V.push_back(i); 
			BFS(V.size() - 1, i);
		}
	int N = V.size();
	fill(dp, dp + (1 << N), Inf); dp[0] = 0;
	for (int i = 0; i < (1 << N) - 1; i++) {
		int j = N - 1;
		while (i & 1 << j) j--;
		for (int k = j - 1; k >= 0; k--)
			dp[i ^ 1 << k ^ 1 << j] = min(dp[i ^ 1 << k ^ 1 << j], dp[i] + dist[k][V[j]]);
	}
	int resin = (1 << N) - 1;
	printf("%d\n", dp[resin] == Inf? -1: dp[resin]);
	return 0;
}