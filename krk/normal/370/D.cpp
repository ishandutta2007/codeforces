#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int r1 = Maxn, r2, c1 = Maxn, c2;
int cnt;

bool Check(int r1, int c1, int a)
{
	if (r1 < 0 || r1 + a - 1 >= n || c1 < 0 || c1 + a - 1 >= m) return false;
	int got = 0;
	for (int i = r1; i < r1 + a; i++)
		got += (B[i][c1] == 'w') + (B[i][c1 + a - 1] == 'w');
	for (int j = c1 + 1; j < c1 + a - 1; j++)
		got += (B[r1][j] == 'w') + (B[r1 + a - 1][j] == 'w');
	return got == cnt;
}

void Fill(int r1, int c1, int a)
{
	for (int i = r1; i < r1 + a; i++) {
		if (B[i][c1] != 'w') B[i][c1] = '+';
		if (B[i][c1 + a - 1] != 'w') B[i][c1 + a - 1] = '+';
	}
	for (int j = c1 + 1; j < c1 + a - 1; j++) {
		if (B[r1][j] != 'w') B[r1][j] = '+';
		if (B[r1 + a - 1][j] != 'w') B[r1 + a - 1][j] = '+';
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf(" %c", &B[i][j]);
			if (B[i][j] == 'w') {
				r1 = min(r1, i); r2 = max(r2, i);
				c1 = min(c1, j); c2 = max(c2, j);
				cnt++;
			}
		}
	if (cnt > 1) {
		int a = max(r2 - r1 + 1, c2 - c1 + 1);
		bool found = false;
		if (r2 - r1 + 1 == a)
			for (int j = 0; j < m && !found; j++) {
				found = Check(r1, j, a);
				if (found) Fill(r1, j, a);
			}
		if (c2 - c1 + 1 == a)
			for (int i = 0; i < n && !found; i++) {
				found = Check(i, c1, a);
				if (found) Fill(i, c1, a);
			}
		if (!found) { printf("-1\n"); return 0; }
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
	return 0;
}