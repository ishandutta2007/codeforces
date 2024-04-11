#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxd = 4;

int n;
char s[Maxn], t[Maxn];
ll dp[Maxn][Maxd];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxd; j++) {
			int ai = i + bool(j & 1);
			int bi = i + bool(j & 2);
			if (ai < n && bi < n && s[ai] == t[bi]) dp[i + 1][j] += dp[i][j];
			else {
				if (ai < n && !(j & 1)) dp[i][j | 1] += dp[i][j];
				if (bi < n && !(j & 2)) dp[i][j | 2] += dp[i][j];
			}
		}
	printf("%I64d\n", dp[n - 1][3]);
	return 0;
}