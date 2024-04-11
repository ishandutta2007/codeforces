#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 255;
const int Inf = 1000000000;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, q, p;
char B[Maxn][Maxn];
int dist[Maxn][Maxn];
ll sum[Maxn][Maxn];
vector <int> V;
ii seq[Maxn * Maxn];
int slen;

void Solve(int r, int c)
{
	dist[r][c] = 0;
	seq[slen++] = ii(r, c);
	for (int i = 0; i < slen; i++) {
		ii v = seq[i];
		int d = dist[v.first][v.second];
		if (d + 1 >= V.size()) break;
		for (int j = 0; j < Maxd; j++) {
			ii u = ii(v.first + dy[j], v.second + dx[j]);
			if (0 <= u.first && u.first < n && 0 <= u.second && u.second < m && 
				B[u.first][u.second] != '*' && d + 1 < dist[u.first][u.second]) {
				dist[u.first][u.second] = d + 1;
				seq[slen++] = u;
			}
		}
	}
	for (int i = 0; i < slen; i++) {
		sum[seq[i].first][seq[i].second] += V[dist[seq[i].first][seq[i].second]];
		dist[seq[i].first][seq[i].second] = Inf;
	}
	slen = 0;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &q, &p);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (isupper(B[i][j])) {
				V.clear(); V.push_back(ll(B[i][j] - 'A' + 1) * q);
				while (V.back() / 2 > 0) V.push_back(V.back() / 2);
				Solve(i, j);
			}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res += sum[i][j] > p;
	printf("%d\n", res);
	return 0;
}