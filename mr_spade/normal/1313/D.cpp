#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,K=8,ninf=0xc0c0c0c0;
int n,m,k;
int l[N],r[N];
vector<int> V;
int w[N],id[N];
vector<int> in[N],out[N];
int hpy[1<<K];
int ed[N],dp[N][1<<K];
signed main()
{
	int _;
	register int i,j,s,t;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]),V.push_back(l[i]-1),V.push_back(r[i]);
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	for(i=1;i<=n;i++)
	{
		l[i]=lower_bound(V.begin(),V.end(),l[i]-1)-V.begin()+1;
		r[i]=lower_bound(V.begin(),V.end(),r[i])-V.begin();
		in[l[i]].push_back(i);out[r[i]].push_back(i);
	}
	m=(int)V.size()-1;
	for(i=1;i<=m;i++)
		w[i]=V[i]-V[i-1];
	_=0;
	for(i=1;i<=m;i++)
	{
		for(int x:in[i])
			for(j=0;j<k;j++)
				if(!(_>>j&1))
				{
					_|=1<<j,id[x]=j;
					break;
				}
		for(int x:out[i])
			_^=1<<id[x];
		ed[i]=_;
	}
	for(i=0;i<1<<k;i++)
		hpy[i]=i&1?!hpy[i^1]:hpy[i>>1];
	memset(dp,0xc0,sizeof(dp));
	dp[0][0]=0;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<1<<k;j++)
			if((j&ed[i-1])!=j)
				dp[i-1][j&ed[i-1]]=max(dp[i-1][j&ed[i-1]],dp[i-1][j]),dp[i-1][j]=ninf;
		_=0;
		for(int x:in[i])
			_|=1<<id[x];
		for(s=_;~s;s=s?((s-1)&_):-1)
			for(t=ed[i-1];~t;t=t?((t-1)&ed[i-1]):-1)
				if(dp[i-1][t]>ninf)
					dp[i][s|t]=max(dp[i][s|t],dp[i-1][t]);
		for(j=0;j<1<<k;j++)
			if(dp[i][j]>ninf&&hpy[j])
				dp[i][j]+=w[i];
	}
	int ans=0;
	for(i=0;i<1<<k;i++)
		ans=max(ans,dp[m][i]);
	printf("%d\n",ans);
	return 0;
}