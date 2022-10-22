#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 0, 1};
const int dx[Maxd] = {0, -1, 1, 0};

int n, m;
char B[Maxn][Maxn];
int cur, col[Maxn][Maxn];
int siz[Maxn * Maxn];
char R[Maxn][Maxn];

int getSiz(int r, int c, int mycol)
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '*' || col[r][c] > 0) return 0;
	col[r][c] = mycol; int res = 1;
	for (int i = 0; i < Maxd; i++)
		res += getSiz(r + dy[i], c + dx[i], mycol);
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == '.' && col[i][j] <= 0) {
				cur++;
				siz[cur] = getSiz(i, j, cur);
			}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (B[i][j] == '.') R[i][j] = '.';
			else {
				vector <int> seq;
				for (int d = 0; d < Maxd; d++) {
					int r = i + dy[d], c = j + dx[d];
					if (0 <= r && r < n && 0 <= c && c < m)
						seq.push_back(col[r][c]);
				}
				sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
				int res = 1;
				for (int d = 0; d < seq.size(); d++)
					res = (res + siz[seq[d]]) % 10;
				R[i][j] = '0' + res;
			}
		R[i][m] = '\0';
		printf("%s\n", R[i]);
	}
	return 0;
}