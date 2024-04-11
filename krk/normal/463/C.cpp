#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxm = 2005;
const int Maxn = 4015;

int n;
int a[Maxm][Maxm];
ll diag1[Maxn], diag2[Maxn];
ll res1;
int X1, Y1;
ll res2;
int X2, Y2;

void getRes(int md, ll &res, int &X, int &Y)
{
	res = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if ((i + j) % 2 == md) {
				ll cand = diag1[i + j] + diag2[i - j + Maxm] - a[i][j];
				if (cand > res) { res = cand; X = i; Y = j; }
			}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			diag1[i + j] += a[i][j];
			diag2[i - j + Maxm] += a[i][j];
		}
	getRes(0, res1, X1, Y1);
	getRes(1, res2, X2, Y2);
	printf("%I64d\n", res1 + res2);
	printf("%d %d %d %d\n", X1, Y1, X2, Y2);
	return 0;
}