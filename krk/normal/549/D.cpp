#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 105;

int n, m;
char B[Maxn][Maxn];
ll C[Maxn][Maxn];
int res;

void Fill(int r, int c, ll val)
{
	for (int i = r; i >= 0; i--)
		for (int j = c; j >= 0; j--)
			C[i][j] += val;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			if (B[i][j] == 'W' && C[i][j] != 1) { res++; Fill(i, j, 1 - C[i][j]); }
			else if (B[i][j] == 'B' && C[i][j] != -1) { res++; Fill(i, j, -1 - C[i][j]); }
	printf("%d\n", res);
	return 0;
}