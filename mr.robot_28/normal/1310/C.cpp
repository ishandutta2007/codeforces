#include<bits/stdc++.h>
#define int long long
using namespace std;
#define int long long
const int N = 1110;
const int inf = 1000000007998244353ll;
struct S{
	int l, r;
} a[N * N];
int si[N][N];
int tot;
int n, m, k;
string s;
int lcp[N][N];
int dp[N][N];
int suffix_sum[N];
int ri[N];
inline int add(int a, int b)
{
	return a + b > inf ? inf : a + b;
}
int cnt(int S)
{
	for(int i = 0; i < n; i++)
	{
		ri[i] = i;
		while(ri[i] != n && si[i][ri[i]] <= S)
		{
			ri[i]++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		dp[i][1] = si[i][n - 1] > si[a[S].l][a[S].r] ? 1 : 0;
	}
	for(int j = 2; j <= m; j++)
	{
		suffix_sum[n - 1] = dp[n - 1][j - 1];
		for(int i = n - 2; i >= 0; i--)
		{
			suffix_sum[i] = add(dp[i][j - 1], suffix_sum[i + 1]);
		}
		for(int i = 0; i < n; i++)
		{
			dp[i][j] = ri[i] == n ? 0 : suffix_sum[ri[i] + 1];
		}
	}
	return dp[0][m];
}
bool cmp(S i, S j)
{
	int p = i.l + lcp[i.l][j.l], q = j.l + lcp[i.l][j.l];
	if(p > i.r || q > j.r)
	{
		return i.r - i.l < j.r - j.l;
	}
	return s[p] < s[q];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	tot = 0;
	cin >> n >> m >> k >> s;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			a[tot].l = i;
			a[tot].r = j;
			tot++;
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = n - 1; j >= 0; j--)
		{
			lcp[i][j] = s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0;
		}
	}
	sort(a, a + tot, cmp);
	for(int i = 0; i < tot; i++)
	{
		si[a[i].l][a[i].r] = i;
	}
	int l = 0, r = tot - 1;
	while(l < r)
	{
		int midd = (r + l) / 2;
		if(cnt(midd) >= k)
		{
			l = midd + 1;
		}
		else
		{
			r = midd;
		}
	}
	for(int i = a[r].l; i <= a[r].r; i++)
	{
		cout << s[i];
	}
	return 0;
}