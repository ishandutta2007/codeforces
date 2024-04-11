#include <cstdio>
using namespace std;

const int Maxn = 1005;
const int mod = 2;

int n;
int B[Maxn][Maxn];
int q;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &B[i][j]);
	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			res = (res + B[i][k] * B[k][i]) % mod;
	scanf("%d", &q);
	while (q--) {
		int a, b; scanf("%d", &a);
		if (a == 3) printf("%d", res);
		else { scanf("%d", &b); res = (res + 1) % mod; }
	}
	printf("\n");
	return 0;
}