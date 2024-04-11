/*
	Author:	MarX
	School:	UH
 */

#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e2 + 10;
const int64 MOD = 1e9 + 7;

int N, K, D;
int64 dp[MAXN][MAXN];

int64 solve(int n, int c)
{
	if (n < c)
		return 0;

	if (n == 0 && c == 0)
		return 1LL;

	if (dp[n][c] > 0)
		return dp[n][c];

	int64 ans = 0;
	int t = min(K,n);
	for (int i = 1; i <= t; ++i)
	{
		if (i < c)
			ans += solve(n - i,c);
		else
			ans += solve(n - i,0);
		ans %= MOD;
	}

	return dp[n][c] = ans % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> D;

	cout << solve(N, D) << endl;

	return 0;
}