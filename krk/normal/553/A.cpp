#include <cstdio>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxk = 1005;

int C[Maxk][Maxk];
int k;
int c[Maxk];
int tot;
int res = 1;

int main()
{
	for (int i = 0; i < Maxk; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);	
		tot += c[i];
	}
	for (int i = k - 1; i >= 0; i--) {
		res = ll(res) * C[tot - 1][c[i] - 1] % mod;
		tot -= c[i];
	}
	printf("%d\n", res);
	return 0;
}