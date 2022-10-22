#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;
typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 205;
const int Maxm = Maxn * Maxn;

int n, m;
int a[Maxm], b[Maxm], c[Maxm];
int dist[Maxn][Maxn];
ii srt[Maxn][Maxn];
vector <ii> V;
ld res = ld(Inf);

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) 
			dist[i][j] = dist[j][i] = (i != j) * Inf;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]); 
		dist[a[i]][b[i]] = dist[b[i]][a[i]] = min(dist[a[i]][b[i]], c[i]);
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			srt[i][j] = ii(dist[i][j], j);
		sort(srt[i] + 1, srt[i] + n + 1);
	}
	for (int i = 0; i < m; i++) {
		V.clear();
		for (int j = 1; j <= n; j++) {
			ii ab = ii(srt[a[i]][j].first, dist[b[i]][srt[a[i]][j].second]);
			//if (!V.empty() && V.back().first == ab.first && V.back().second >= ab.second) continue;
			while (!V.empty() && V.back().second <= ab.second) V.pop_back();
			V.push_back(ab);
		}
		res = min(res, ld(min(V.back().first, V[0].second)));
		for (int j = 0; j + 1 < V.size(); j++)
			res = min(res, ld(V[j].first + V[j + 1].second + c[i]) / 2.0l);
	}
	cout << fixed << setprecision(16) << res << endl;
	return 0;
}