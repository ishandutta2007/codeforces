#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 20;
const int Maxl = 16;
const string let = "0123456789abcdef";

ll C[N][N];
ll k;
int t;
int ans[N];

ll Solve(int n, const vector <int> &av, bool fl = false)
{
	if (fl && av[0] <= 0) return 0;
	for (int i = 0; i < av.size(); i ++)
		if (av[i] < 0) return 0;
	vector <ll> dp(n + 1, 0); 
	dp[n - fl] = 1;
	for (int i = 0; i < av.size(); i ++)
		for (int j = 0; j <= n; j ++)
			for (int k = 1; k <= j && k <= av[i] - (fl && i == 0); k ++)
				dp[j - k] += dp[j] * C[j][k];
	return dp[0];
}

int main()
{
	for (int i = 0; i < N; i ++) 
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j ++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	cin >> k >> t;
	int len = 1;
	vector <int> cur(Maxl, t);
	ll got;
	while ((got = Solve(len, cur) - Solve(len, cur, true)) < k) { k -= got; len ++; }
	for (int i = 0; i < len; i ++) 
	{
		ans[i] = (i? 0: 1); cur[ans[i]] --;
		while ((got = Solve(len - 1 - i, cur)) < k) 
		{
			k -= got; 
			cur[ans[i]] ++;
			ans[i] ++; cur[ans[i]] --;
		}
		printf("%c", let[ans[i]]);
	}
	printf("\n");
	return 0;
}