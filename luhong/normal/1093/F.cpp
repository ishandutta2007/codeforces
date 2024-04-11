#include <cstdio>
#include <set>
#include <algorithm> 
#define mod 998244353

int dp[101000][101];
int a[101000];
int cnt[110];
std::set<int> st;
int sum = 0;
int s[110];
int p = 0;

int qpow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

void rw(int &a, int b) {a = (a + b) % mod;}

int main()
{
	int n, k, len; scanf("%d%d%d", &n, &k, &len);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= len; i++)
	{
		if(a[i] == -1) continue;
		if(++cnt[a[i]] == 1) st.insert(a[i]);
	}
	
	for(int i = len; i <= n; i++)
	{
		int PP = qpow(k, p);
		for(int j = 1; j <= k; j++)
		{
			if(st.size() == 0 || st.size() == 1 && *st.begin() == j)
			{
				dp[i][j] = (1ll * PP - sum - s[j] + mod + mod) % mod;
			}
			else dp[i][j] = 0;
			rw(s[j], dp[i][j]);
		}
		if(a[i - len + 1] == -1) sum = 1ll * sum * k % mod, p++;
		else if(--cnt[a[i - len + 1]] == 0) st.erase(a[i - len + 1]);
		for(int j = 1; j <= k; j++)
		{
			rw(sum, dp[i - len + 1][j]);
			s[j] = (s[j] - dp[i - len + 1][j] + mod) % mod;
		}
		if(a[i + 1] != -1 && ++cnt[a[i + 1]] == 1) st.insert(a[i + 1]); 
	}
	
	for(int i = n - len + 2; i <= n; i++) if(a[i] == -1) p++;
	
	int ans = qpow(k, p);
	p = 0;
	
	for(int i = n; i >= len; i--)
	{
		int PP = qpow(k, p);
		for(int j = 1; j <= k; j++) ans = (ans - 1ll * dp[i][j] * PP % mod + mod) % mod;
		if(a[i] == -1) p++;
	}

	printf("%d\n", ans);
	return 0;
}

//2^(n-len+1)
/*
f[S]Slen
Ans =  - (-1)^(|S|+1) * f[S]
dp

dp[i][j]ilenjii
-1
*/