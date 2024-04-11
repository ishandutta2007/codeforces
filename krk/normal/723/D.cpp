#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 52;
const int Maxm = Maxn * Maxn;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m, k;
char B[Maxn][Maxn];
int cur, col[Maxn][Maxn];
vector <ii> V;
bool tkdown[Maxm];
int res;

bool Get(int r, int c, int cur, int &siz)
{
	if (r < 0 || r >= n || c < 0 || c >= m) return true;
	if (col[r][c] || B[r][c] == '*') return false;
	col[r][c] = cur; siz++;
	bool res = false;
	for (int i = 0; i < Maxd; i++)
		res |= Get(r + dy[i], c + dx[i], cur, siz);
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (col[i][j] == 0 && B[i][j] == '.') {
			cur++;
			int siz = 0;
			if (!Get(i, j, cur, siz)) V.push_back(ii(siz, cur));
		}
	sort(V.rbegin(), V.rend());
	while (V.size() > k) { tkdown[V.back().second] = true; res += V.back().first; V.pop_back(); }
	printf("%d\n", res);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (tkdown[col[i][j]]) B[i][j] = '*';
		printf("%s\n", B[i]);
	}
	return 0;
}