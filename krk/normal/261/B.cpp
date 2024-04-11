#include <cstdio>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Maxn = 52;

int n;
int a[Maxn];
int p;
ll ways[Maxn][Maxn][Maxn];
ld res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &p);
	ways[0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= p; k++) {
				ways[i + 1][j][k] += ways[i][j][k];
				if (k + a[i] <= p) ways[i + 1][j + 1][k + a[i]] += ways[i][j][k];
			}
	for (int i = 1; i <= n; i++) {
		ll sum = 0;
		for (int j = 0; j <= p; j++)
			sum += ways[n][i][j];
		ld add = sum;
		for (int j = i + 1; j <= n; j++)
			add /= ld(j);
		for (int j = 1; j <= n - i; j++)
			add *= ld(j);
		res += add;
	}
	printf("%.10lf\n", (double)res);
	return 0;
}