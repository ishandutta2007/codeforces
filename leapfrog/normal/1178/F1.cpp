#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n,m,c[505],dp[505][505],ans,pos[505];
std::vector<int> v[505];

int ksm(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1; 
	}
	return res;
}

struct Segment_Tree
{
	int mini[2005];
	void pushup(int now)
	{
		mini[now] = min(mini[now << 1],mini[now << 1 | 1]);
	}
	void build(int now,int l,int r)
	{
		if (l == r)
		{
			mini[now] = c[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		pushup(now);
	}
	int query(int now,int l,int r,int ll,int rr)
	{
		if (ll <= l && rr >= r)
		{
			return mini[now];
		}
		int mid = (l + r) >> 1,ans = 0x7f7f7f7f7f7f7f;
		if (ll <= mid) ans = min(ans,query(now << 1,l,mid,ll,rr));
		if (rr > mid) ans = min(ans,query(now << 1 | 1,mid + 1,r,ll,rr));
		return ans;
	}
}T;

int dfs(int i,int j)
{
	if (dp[i][j] != -1) return dp[i][j];
	if (i > j) return 1;
	int tmp = T.query(1,1,m,i,j);
	int res1 = 0;
	for (int k = i; k <= pos[tmp]; k++)
	{
		res1 += (dfs(i,k - 1) * dfs(k,pos[tmp] - 1)) % mod;
		res1 %= mod;
	}
	int res2 = 0;
	for (int k = pos[tmp]; k <= j; k++)
	{
		res2 += (dfs(k + 1,j) * dfs(pos[tmp] + 1,k)) % mod;
		res2 %= mod;
	}
	dp[i][j] = (res1 * res2) % mod;
	return dp[i][j];
}

signed main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld",&c[i]);
		pos[c[i]] = i;
	}
	T.build(1,1,m);
	printf("%lld\n",dfs(1,m));
	return 0;
}