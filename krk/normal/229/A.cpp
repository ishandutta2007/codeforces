#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxm = 10005;
const int Inf = 1000000000;

int n, m;
char B[Maxn][Maxm];
int need[Maxm];

int Dist(int a, int b)
{
	if (a <= b) return b - a;
	return b + m - a;
}

int Next(int i, int j)
{
	while (B[i][j] == '0') j = (j + 1) % m;
	return j;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &B[i][j]);
	int i;
	for (i = 0; i < n; i++) {
		int lst = -1;
		for (int j = 0; j < m; j++)
			if (B[i][j] == '1') lst = j;
		if (lst == -1) break;
		int nxt = Next(i, 0);
		for (int j = 0; j < m; j++) {
			if (j && B[i][j - 1] == '1') { lst = nxt; nxt = Next(i, j); }
			need[j] += min(Dist(lst, j), Dist(j, nxt));
		}
	}
	if (i < n) printf("-1\n");
	else {
		int best = Inf;
		for (int i = 0; i < m; i++) best = min(best, need[i]);
		printf("%d\n", best);
	}
	return 0;
}