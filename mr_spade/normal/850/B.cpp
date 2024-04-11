#include<cstdio>
#include<cstring>
#include<algorithm>
using std::min;
using std::max;
#define int long long
const int N=5e5+5,M=1e6+5,inf=0x3f3f3f3f3f3f3f3f;
int n,m=1000000,x,y,lim,ans=inf;
int cnt[M],sum[M];
bool isprime[M];
signed main()
{
	int _,now;
	int i,j;
	scanf("%lld%lld%lld",&n,&x,&y);
	lim=x/y;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&_);
		cnt[_]++;
	}
	for(i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+cnt[i]*i;
		cnt[i]+=cnt[i-1];
	}
	memset(isprime+1,1,sizeof(bool)*m);
	isprime[1]=0;
	for(i=1;i<=m;i++)
		if(isprime[i])
		{
			_=max(0ll,i-1-lim);now=0;
			for(j=i<<1;j<=m;j+=i)
				isprime[j]=0;
			for(j=i;j<=m;j+=i)
			{
				now+=(cnt[j-i+_]-cnt[j-i])*x;
				now+=((cnt[j]-cnt[j-i+_])*j-(sum[j]-sum[j-i+_]))*y;
			}
			now+=(cnt[min(m,j-i+_)]-cnt[min(m,j-i)])*x;
			now+=((cnt[min(m,j)]-cnt[min(m,j-i+_)])*j-(sum[min(m,j)]-sum[min(m,j-i+_)]))*y;
			if(ans>now)
				ans=now;
		}
	printf("%lld\n",ans);
	return 0;
}