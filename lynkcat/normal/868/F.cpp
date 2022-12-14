// Lynkcat.
// Problem: C. Yet Another Minimization Problem
// Contest: Codeforces - 10.9
// URL: https://codeforces.com/gym/403061/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 100005
using namespace std;
int dp[21][N];
int cnt[N];
int n,m;
int a[N];
int sum;
int lf,rt;
void ins(int x)
{
	sum+=cnt[x];
	cnt[x]++;
}
void del(int x)
{
	cnt[x]--;
	sum-=cnt[x];
}
inline void work(int L,int R)
{
	while (rt<R)
	{
		++rt;
		ins(a[rt]);
	}
	while (lf>L)
	{
		--lf;
		ins(a[lf]);
	}
	while (rt>R)
	{
		del(a[rt]);
		--rt;
	}
	while (lf<L)
	{
		del(a[lf]);
		++lf;
	}
}		
void solve(int l,int r,int L,int R,int dep)
{
	if (L>R) return;
	int mid=(L+R)/2;
	int s=inf;
	int now=l;
	for (int i=l;i<=min(r,mid-1);i++)
	{
		work(i+1,mid);
		if (dp[dep-1][i]+sum<s)
		{
			now=i;
			s=sum+dp[dep-1][i];
		}
	}
	// cout<<now<<" "<<s<<" "<<mid<<" "<<dep<<endl;
	dp[dep][mid]=s;
	solve(now,r,mid+1,R,dep);
	solve(l,now,L,mid-1,dep);
}		
void BellaKira()
{
	cin>>n>>m;
	memset(dp,0x3f,sizeof(dp));
	int s=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		s+=cnt[a[i]];
		cnt[a[i]]++;
		dp[1][i]=s;
	}
	for (int i=1;i<=n;i++) cnt[a[i]]=0;
	lf=1,rt=0;
	for (int j=2;j<=m;j++)
	{
		int l=j-1;
		int s=0;
		solve(j-1,n,j,n,j);
	}
	cout<<dp[m][n]<<'\n';
				
		
		
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}