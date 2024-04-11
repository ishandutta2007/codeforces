#include <cstdio>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1005;

int n;
int p[Maxn];
int tonxt[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		tonxt[i] = 2;
		for (int j = p[i]; j < i; j++)
			tonxt[i] = (tonxt[i] + tonxt[j]) % mod;
		res = (res + tonxt[i]) % mod;
	}
	printf("%d\n", res);
	return 0;
}