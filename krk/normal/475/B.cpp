#include <cstdio>
using namespace std;

const int Maxn = 25;

int n, m;
char h[Maxn], v[Maxn];
bool taken[Maxn][Maxn];

void Traverse(int r, int c)
{
	if (r < 0 || r >= n || c < 0 || c >= m || taken[r][c]) return;
	taken[r][c] = true;
	if (h[r] == '<') Traverse(r, c - 1);
	else Traverse(r, c + 1);
	if (v[c] == '^') Traverse(r - 1, c);
	else Traverse(r + 1, c);
}

bool Check(int r, int c)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			taken[i][j] = false;
	Traverse(r, c);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!taken[i][j]) return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s", h); scanf("%s", v);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!Check(i, j)) { printf("NO\n"); return 0; }
	printf("YES\n");
	return 0;
}