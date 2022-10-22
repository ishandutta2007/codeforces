#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxk = 5;
const int Maxn = 1005;

int n, k;
int dp[Maxn];
int seq[Maxk][Maxn];
int wh[Maxk][Maxn];
int res;

void readSeq(int r)
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[r][i]);
		wh[r][seq[r][i]] = i;
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		readSeq(i);
	for (int i = 1; i <= n; i++)
		dp[i] = 1;
	for (int i = 0; i < n; i++) {
		int a = seq[0][i];
		res = max(res, dp[a]);
		for (int j = i + 1; j < n; j++) {
			int b = seq[0][j];
			bool ok = true;
			for (int l = 1; l < k && ok; l++)
				ok = wh[l][a] < wh[l][b];
			if (ok) dp[b] = max(dp[b], dp[a] + 1);
		}
	}
	printf("%d\n", res);
	return 0;
}