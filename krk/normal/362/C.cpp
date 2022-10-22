#include <cstdio>
using namespace std;

const int Maxn = 5005;

int n;
int a[Maxn];
int lcnt[Maxn][Maxn];
int got;
int res = Maxn * Maxn, cnt;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
			lcnt[i][j] = lcnt[i][j - 1] + (a[j] < a[i]);
		for (int j = i - 1; j >= 0; j--)
			lcnt[i][j] = lcnt[i][j + 1] + (a[j] < a[i]);
		got += lcnt[i][n - 1];
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) if (a[i] > a[j]) {
			int cand = got - 2 * (lcnt[i][j - 1] - lcnt[j][i + 1]) - 1;
			if (cand < res) { res = cand; cnt = 0; }
			if (cand == res) cnt++;
		}
	printf("%d %d\n", res, cnt);
	return 0;
}