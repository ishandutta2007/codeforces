#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=21,M=4e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,len[N],f[N][M],l[N],sum[1<<N],dp[1<<N],ans;
char s[N][M];
int main()
{
	read(n);
	F(i,0,n)
	{
		scanf("%s",s[i]);
		while(s[i][len[i]])++len[i];
	}
	F(i,0,n)
	{
		int cnt=0;
		F(j,0,len[i])
		{
			cnt+=s[i][j]=='('?1:-1;
			if(-cnt>l[i])l[i]=-cnt;
			if(-cnt==l[i])++f[i][-cnt];
		}
		sum[1<<i]=cnt;
	}
	F(i,0,1<<n)sum[i]=sum[i&-i]+sum[i^(i&-i)];
	F(i,1,(1<<n)-1)dp[i]=-INF;
	F(i,1,1<<n)
	{
		F(j,0,n)if(i>>j&1)
		{
			if(sum[i^(1<<j)]>=l[j])dp[i]=max(dp[i],dp[i^(1<<j)]+f[j][sum[i^(1<<j)]]);
			else if(sum[i^(1<<j)]>=0)ans=max(ans,dp[i^(1<<j)]+f[j][sum[i^(1<<j)]]);
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}