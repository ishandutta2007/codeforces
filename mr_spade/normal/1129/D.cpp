#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
using std::max;
using std::min;
using std::deque;
const int mod=998244353;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=1e5+5,unit=320,SQRTN=505;
int n,k;
int a[N],pos[N];
int c[N],dp[N];
int lp[SQRTN],rp[SQRTN];
int low[SQRTN],high[SQRTN];
int tag[SQRTN],sum[SQRTN][SQRTN];
int book[SQRTN];
deque<int> last[N];
inline void rebuild(int x)
{
	if(!book[x])
		return;
	register int i;
	for(i=lp[x];i<=rp[x];i++)
		c[i]+=tag[x];
	tag[x]=0;low[x]=n;high[x]=0;
	for(i=lp[x];i<=rp[x];i++)
		low[x]=min(low[x],c[i]),high[x]=max(high[x],c[i]);
	memset(sum[x],0,sizeof(int)*(high[x]-low[x]+1));
	for(i=lp[x];i<=rp[x];i++)
		sum[x][c[i]-low[x]]=add(sum[x][c[i]-low[x]],dp[i-1]);
	for(i=1;i<=high[x]-low[x];i++)
		sum[x][i]=add(sum[x][i-1],sum[x][i]);
	return;
}
inline void modify(int l,int r,int k)
{
	register int i;
	if(pos[l]==pos[r])
	{
		for(i=l;i<=r;i++)
			c[i]+=k;
		rebuild(pos[l]);
		return;
	}
	for(i=l;i<=rp[pos[l]];i++)
		c[i]+=k;
	rebuild(pos[l]);
	for(i=pos[l]+1;i<=pos[r]-1;i++)
		low[i]+=k,high[i]+=k,tag[i]+=k;
	for(i=lp[pos[r]];i<=r;i++)
		c[i]+=k;
	rebuild(pos[r]);
	return;
}
signed main()
{
	int x;
	register int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		last[i].push_front(0);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		pos[i]=(i-1)/unit+1;
	for(i=1;i<=n;i++)
		rp[pos[i]]=i;
	for(i=n;i>=1;i--)
		lp[pos[i]]=i;
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		modify(last[a[i]][0]+1,i,1);
		if((int)last[a[i]].size()>1)
			modify(last[a[i]][1]+1,last[a[i]][0],-1);
		if(rp[pos[i]]==i)
			book[pos[i]]=1,rebuild(pos[i]);
		last[a[i]].push_front(i);
		for(j=1;j<pos[i];j++)
		{
			if(low[j]>k)
				continue;
			x=min(high[j]-low[j],k-low[j]);
			dp[i]=add(dp[i],sum[j][x]);
		}
		for(j=lp[pos[i]];j<=i;j++)
			if(c[j]<=k)
				dp[i]=add(dp[i],dp[j-1]);
	}
	printf("%d\n",dp[n]);
	return 0;
}