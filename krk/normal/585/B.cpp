#include <cstdio>
using namespace std;

const int Maxn = 105;
const int Maxd = 3;

int t;
int n, k;
char B[Maxd][Maxn];
bool vis[Maxd][Maxn];

bool Check(int r, int c)
{
	if (r < 0 || r >= Maxd || c < 0 || c >= n) return false;
	return B[r][c] == '.';
}

void Traverse(int r, int c)
{
	if (!Check(r, c) || vis[r][c]) return;
	vis[r][c] = true;
	if (Check(r, c + 1)) {
		if (Check(r - 1, c + 1) && Check(r - 1, c + 2) && Check(r - 1, c + 3)) Traverse(r - 1, c + 3);
		if (Check(r, c + 2) && Check(r, c + 3)) Traverse(r, c + 3);
		if (Check(r + 1, c + 1) && Check(r + 1, c + 2) && Check(r + 1, c + 3)) Traverse(r + 1, c + 3);
	}
}

bool Ok(int r, int c)
{
	for (int j = c; j < n; j++)
		if (!Check(r, j)) return false;
	return true;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k); n += 3;
		for (int i = 0; i < Maxd; i++) {
			scanf("%s", B[i]); B[i][n - 3] = '.'; B[i][n - 2] = '.'; B[i][n - 1] = '.';
			for (int j = 0; j < n; j++)
				vis[i][j] = false;
		}
		int ni = 0, nj = 0;
		while (B[ni][nj] != 's') ni++;
		B[ni][nj] = '.';
		Traverse(ni, nj);

		bool ok = false;
		for (int i = 0; i < Maxd && !ok; i++)
			for (int j = 0; j < n && !ok; j++)
				if (vis[i][j]) ok = Ok(i, j);
		printf("%s\n", ok? "YES": "NO");
	}
	return 0;
}