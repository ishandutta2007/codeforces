#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 3005;

int n, k;
int p[Maxn];
bool alln100[Maxn], onen0[Maxn]; 
int dist[Maxn][Maxn];
vector <ii> Q;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	alln100[n + 1] = true; onen0[n + 1] = false;
	for (int i = n; i >= 1; i--) {
		alln100[i] = p[i] != 100 && alln100[i + 1];
		onen0[i] = p[i] != 0 || onen0[i + 1];
	}
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
	dist[1][2] = 0; Q.push_back(ii(1, 2));
	for (int i = 0; i < Q.size(); i++) {
		ii v = Q[i]; int d = dist[v.first][v.second];
		if (v.second > n || d == k) continue;
		if (alln100[v.second] && p[v.first] != 0 && d + 1 < dist[v.first][v.second + 1]) {
			dist[v.first][v.second + 1] = d + 1; Q.push_back(ii(v.first, v.second + 1));
		}
		if (onen0[v.second] && p[v.first] != 100 && d + 1 < dist[v.second][v.second + 1]) {
			dist[v.second][v.second + 1] = d + 1; Q.push_back(ii(v.second, v.second + 1));
		}
		if (onen0[v.second] && p[v.first] != 0 && d + 1 < dist[v.second + 1][v.second + 2]) {
			dist[v.second + 1][v.second + 2] = d + 1; Q.push_back(ii(v.second + 1, v.second + 2));
		}
	}
	printf("%d\n", Q.size());
	return 0;
}