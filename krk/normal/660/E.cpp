#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1000005;

int n, m;
int pw[Maxn];
int dp[Maxn];
int res;

int main() 
{
	scanf("%d %d", &n, &m);
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = ll(m) * pw[i - 1] % mod;
	dp[0] = 1; res = pw[n];
	for (int i = 0; i < n; i++) {
		res = (res + ll(dp[i]) * m % mod * pw[n - 1 - i]) % mod;
		dp[i + 1] = (dp[i + 1] + ll(dp[i]) * (2 * m - 1)) % mod;
	}
	printf("%d\n", res);
    return 0;
}