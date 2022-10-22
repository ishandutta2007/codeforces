#include <cstdio>
using namespace std;

const int Maxn = 105;

int n, m;
bool edge[Maxn][Maxn];
bool ta[Maxn], tb[Maxn];
int res;

void FillB(int j);

void FillA(int i)
{
	if (ta[i]) return;
	ta[i] = true;
	for (int j = 1; j <= m; j++)
		if (edge[i][j]) FillB(j);
}

void FillB(int j)
{
	if (tb[j]) return;
	tb[j] = true;
	for (int i = 1; i <= n; i++)
		if (edge[i][j]) FillA(i);
}

int main()
{
	scanf("%d %d", &n, &m);
	bool allzer = true;
	for (int i = 1; i <= n; i++) {
		int cnt; scanf("%d", &cnt);
		allzer = allzer && cnt == 0;
		while (cnt--) {
			int l; scanf("%d", &l);
			edge[i][l] = true;
		}
	}
	if (allzer) { printf("%d\n", n); return 0; }
	for (int i = 1; i <= n; i++)
		if (!ta[i]) { res++; FillA(i); }
	printf("%d\n", res - 1);
	return 0;
}