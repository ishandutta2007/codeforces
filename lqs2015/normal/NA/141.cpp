#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long bit[2222][2222],n,m,k,szn,szm,x,a,b,c,q,ask[4444][5],cnt,adj[2222][2222],ans;
long long que[1111111][6];
vector<pair<pair<long long,long long>,long long> > g[2222];
char opt[11];
bool f[2222];
void update(long long x,long long y,long long c)
{
	for (long long i=x;i<=szn;i+=i&(-i))
	{
		for (long long j=y;j<=szm;j+=j&(-j))
		bit[i][j]+=c;
	}
}
long long query(long long x,long long y)
{
	long long res=0;
	for (long long i=x;i>=1;i-=i&(-i))
	{
		for (long long j=y;j>=1;j-=j&(-j))
		res+=bit[i][j];
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for (long long i=1;i<=k;i++)
	{
		scanf("%I64d",&x);
		for (long long j=1;j<=x;j++)
		{
			scanf("%I64d%I64d%I64d",&a,&b,&c);
			g[i].push_back(make_pair(make_pair(a,b),c)); 
		}
	}
	szn=szm=1;
	while(szn<n) szn*=2;
	while(szm<m) szm*=2;
	scanf("%I64d",&q);
	for (long long i=1;i<=q;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='A')
		{
			que[i][0]=1;
			scanf("%I64d%I64d%I64d%I64d",&que[i][1],&que[i][2],&que[i][3],&que[i][4]);
			cnt++;
			ask[cnt][1]=que[i][1];ask[cnt][2]=que[i][2];ask[cnt][3]=que[i][3];ask[cnt][4]=que[i][4];
		}
		else
		{
			scanf("%I64d",&que[i][1]);
		}
	}
	for (long long i=1;i<=k;i++)
	{
		for (long long j=0;j<g[i].size();j++)
		{
			a=g[i][j].first.first;b=g[i][j].first.second;c=g[i][j].second;
			update(a,b,c);
		}
		for (long long j=1;j<=cnt;j++)
		{
			adj[j][i]=query(ask[j][3],ask[j][4])-query(ask[j][1]-1,ask[j][4])-query(ask[j][3],ask[j][2]-1)+query(ask[j][1]-1,ask[j][2]-1);
		}
		for (long long j=0;j<g[i].size();j++)
		{
			a=g[i][j].first.first;b=g[i][j].first.second;c=g[i][j].second;
			update(a,b,-c);
		}
	}
	cnt=0;
	for (long long i=1;i<=k;i++) f[i]=1;
	for (long long i=1;i<=q;i++)
	{
		if (que[i][0])
		{
			cnt++;ans=0;
			for (long long j=1;j<=k;j++) 
			{
				if (f[j]) ans+=adj[cnt][j];
			}
			printf("%I64d\n",ans);
		}
		else
		{
			f[que[i][1]]^=1;
		}
	}
	return 0;
}