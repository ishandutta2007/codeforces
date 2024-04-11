#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

char let[Maxn];
int cnt[Maxn];
int cur = 0;
ll dp[Maxn][2][2];
ll res[2];

int main()
{
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (cur == 0 || let[cur - 1] != ch) {
			let[cur] = ch; cnt[cur] = 1; cur++;
		} else cnt[cur - 1]++;
	for (int i = 0; i < cur; i++) {
		for (int k = 0; k < 2; k++) {
			res[k] += dp[i][0][k] * (ll(cnt[i]) / 2);
			res[(k + 1) % 2] += dp[i][0][k] * (ll(cnt[i] + 1) / 2);
		}
		for (int j = 1; j <= cnt[i]; j++)
			res[j % 2] += cnt[i] - j + 1;
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i + 1][(j + 1) % 2][(k + cnt[i]) % 2] += dp[i][j][k];
		dp[i + 1][1][0] += ll(cnt[i]) / 2;
		dp[i + 1][1][1] += ll(cnt[i] + 1) / 2;
	}
	for (int i = 0; i < 2; i++)
		printf("%I64d%c", res[i], i + 1 < 2? ' ': '\n');
	return 0;
}