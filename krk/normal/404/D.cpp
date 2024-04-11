#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1000005;

char s[Maxn];
int slen;
int dp[Maxn][3];

int main()
{
	scanf("%s", s); slen = strlen(s);
	dp[0][0] = dp[0][1] = 1;
	for (int i = 0; i < slen; i++) {
		// from 0
		if (s[i] == '0' || s[i] == '?') dp[i + 1][0] = (dp[i + 1][0] + dp[i][0]) % mod;
		if (s[i] == '1' || s[i] == '?') dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % mod;
		// from 1
		if (s[i] == '*' || s[i] == '?') dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % mod;
		// from *
		if (s[i] == '*' || s[i] == '?') dp[i + 1][2] = (dp[i + 1][2] + dp[i][2]) % mod;
		if (s[i] == '1' || s[i] == '?') dp[i + 1][0] = (dp[i + 1][0] + dp[i][2]) % mod;
		if (s[i] == '2' || s[i] == '?') dp[i + 1][1] = (dp[i + 1][1] + dp[i][2]) % mod;
	}
	printf("%d\n", (dp[slen][0] + dp[slen][2]) % mod);
	return 0;
}