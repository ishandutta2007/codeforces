#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 300005;
const int Inf = 2000000007;

int n, k;
int A[Maxn];
map <int, int> dp[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	sort(A, A + n);
	A[n] = A[n - 1];

	res = A[n - 1] - A[0];
	int small = (n - k) / k + 1, big = (n - 1) / k + 1;
	int bnums = n % k == 0? k: n % k;
	int snums = k - bnums;

	dp[0][0] = 0;
	for (int i = 0; i < n; i++) if (!dp[i].empty())
		for (map <int, int>::iterator it = dp[i].begin(); it != dp[i].end(); it++) {
			int stk = it->first;
			int btk = (i - stk * small) / big;
			if (stk < snums) dp[i + small][stk + 1] = max(dp[i + small][stk + 1], it->second + A[i + small] - A[i + small - 1]);
			if (btk < bnums) dp[i + big][stk] = max(dp[i + big][stk], it->second + A[i + big] - A[i + big - 1]);
		}
	printf("%d\n", res - dp[n][snums]);
	return 0;
}