#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 2005;

int n, k;
char s[Maxn];
int dp1[Maxn][Maxn], dp2[Maxn][Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	reverse(s + 1, s + n + 1);
	dp2[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) {
			dp2[i][j] = (ll(s[i] - 'a') * ll(dp2[i - 1][j]) + ll(dp2[i - 1][j] - dp1[i - 1][j] + mod)) % ll(mod);
			for (int l = 1; l <= i + 1 - l && l * (i + 1 - l) <= j; l++) {
				int z = i + 1 - l;
				if (l <= i) dp1[i][j] = (dp1[i][j] + ll('z' - s[l]) * ll(dp2[l - 1][j - l * z]) % ll(mod)) % mod;
				if (z != l && z <= i) dp1[i][j] = (dp1[i][j] + ll('z' - s[z]) * ll(dp2[z - 1][j - l * z]) % ll(mod)) % mod;
			}
			dp2[i][j] = (dp2[i][j] + dp1[i][j]) % mod;
		}
	printf("%d\n", dp2[n][k]);
	return 0;
}