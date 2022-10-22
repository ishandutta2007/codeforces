#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
vector <ii> neigh[Maxn][Maxn];
int in[Maxn][Maxn];
bool tk[Maxn][Maxn];
queue <ii> Q;

void Colour(ii a, ii b)
{
	if (a > b) swap(a, b);
	if (a.first < b.first) { B[a.first][a.second] = '^'; B[b.first][b.second] = 'v'; }
	else { B[a.first][a.second] = '<'; B[b.first][b.second] = '>'; }
}

bool Check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '.') return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i + 1 < n && B[i][j] == '.' && B[i + 1][j] == '.') {
				neigh[i][j].push_back(ii(i + 1, j)); in[i][j]++;
				neigh[i + 1][j].push_back(ii(i, j)); in[i + 1][j]++;
			}
			if (j + 1 < m && B[i][j] == '.' && B[i][j + 1] == '.') {
				neigh[i][j].push_back(ii(i, j + 1)); in[i][j]++;
				neigh[i][j + 1].push_back(ii(i, j)); in[i][j + 1]++;
			}
			if (in[i][j] == 1) { tk[i][j] = true; Q.push(ii(i, j)); }
		}
	while (!Q.empty()) {
		ii v = Q.front(); Q.pop();
		for (int i = 0; i < neigh[v.first][v.second].size(); i++) {
			ii u = neigh[v.first][v.second][i];
			if (B[v.first][v.second] == '.' && B[u.first][u.second] == '.' && (!tk[u.first][u.second] || in[u.first][u.second] == 1)) {
				Colour(v, u); 
				if (!tk[u.first][u.second]) { tk[u.first][u.second] = true; Q.push(u); }
			} else if (--in[u.first][u.second] == 1 && !tk[u.first][u.second]) {
				tk[u.first][u.second] = true; Q.push(u);
			}
		}
	}
	if (Check())
		for (int i = 0; i < n; i++)
			printf("%s\n", B[i]);
	else printf("Not unique\n");
	return 0;
}