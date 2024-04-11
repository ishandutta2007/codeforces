#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 20;

int n, m, d;
int has[Maxn][Maxm];
bool was[1 << Maxm];
int res = Maxm;

int main()
{
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		int s; scanf("%d", &s);
		while (s--) {
			int a; scanf("%d", &a);
			has[a][i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			has[i][j] += has[i - 1][j];
	for (int i = d; i <= n; i++) {
		int mask = 0;
		for (int j = 0; j < m; j++)
			if (has[i][j] - has[i - d][j] == 0) mask |= 1 << j;
		was[mask] = true;
	}
	for (int i = (1 << m) - 1; i >= 0; i--) if (was[i])
		for (int j = 0; j < m; j++) if (i & 1 << j)
			was[i ^ 1 << j] = true;
	for (int i = 0; i < 1 << m; i++) if (!was[i]) {
		int bits = 0;
		for (int j = 0; j < m; j++)
			if (i & 1 << j) bits++;
		res = min(res, bits);
	}
	printf("%d\n", res);
	return 0;
}