#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 305;
const int Maxp = Maxn * Maxn;
const int Inf = 1000000000;

int n, m, p;
vector <ii> V[Maxp];
int B[Maxn][Maxn];
ll res[Maxn][Maxn];
ll dp1[Maxn][Maxn], dp2[Maxn][Maxn], dp3[Maxn][Maxn], dp4[Maxn][Maxn];

int main()
{
	fill((ll*)dp1, (ll*)dp1 + Maxn * Maxn, Inf);
	fill((ll*)dp2, (ll*)dp2 + Maxn * Maxn, Inf);
	fill((ll*)dp3, (ll*)dp3 + Maxn * Maxn, Inf);
	fill((ll*)dp4, (ll*)dp4 + Maxn * Maxn, Inf);
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%d", &B[i][j]);
			V[B[i][j]].push_back(ii(i, j));
		}
	for (int i = 0; i < V[1].size(); i++)
		res[V[1][i].first][V[1][i].second] = abs(1 - V[1][i].first) + abs(1 - V[1][i].second);
	for (int i = 1; i < p; i++) {
		if (V[i].size() >= n) {
			for (int r = 1; r <= n; r++)
				for (int c = 1; c <= m; c++) {
					dp1[r][c] = min(dp1[r - 1][c], dp1[r][c - 1]) + 1;
					if (B[r][c] == i) dp1[r][c] = min(dp1[r][c], res[r][c]);
				}
			for (int r = 1; r <= n; r++)
				for (int c = m; c >= 1; c--) {
					dp2[r][c] = min(dp2[r - 1][c], dp2[r][c + 1]) + 1;
					if (B[r][c] == i) dp2[r][c] = min(dp2[r][c], res[r][c]);
				}
			for (int r = n; r >= 1; r--)
				for (int c = 1; c <= m; c++) {
					dp3[r][c] = min(dp3[r + 1][c], dp3[r][c - 1]) + 1;
					if (B[r][c] == i) dp3[r][c] = min(dp3[r][c], res[r][c]);
				}
			for (int r = n; r >= 1; r--)
				for (int c = m; c >= 1; c--) {
					dp4[r][c] = min(dp4[r + 1][c], dp4[r][c + 1]) + 1;
					if (B[r][c] == i) dp4[r][c] = min(dp4[r][c], res[r][c]);
				}
			for (int j = 0; j < V[i + 1].size(); j++) {
				ii p = V[i + 1][j];
				res[p.first][p.second] = min(min(dp1[p.first][p.second], dp2[p.first][p.second]), 
											 min(dp3[p.first][p.second], dp4[p.first][p.second]));
			}
		} else {
			for (int j = 0; j < V[i + 1].size(); j++) {
				ii p = V[i + 1][j];
				res[p.first][p.second] = Inf;
				for (int l = 0; l < V[i].size(); l++) {
					ii u = V[i][l];
					res[p.first][p.second] = min(res[p.first][p.second], res[u.first][u.second] + 
												 abs(p.first - u.first) + abs(p.second - u.second));
				}
			}
		}
	}
	printf("%I64d\n", res[V[p][0].first][V[p][0].second]);
	return 0;
}