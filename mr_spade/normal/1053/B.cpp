#include<cstdio>
#include<algorithm>
#define int long long
using std::max;
const int N=3e5+5;
int n,ans;
int a[N],sum[N];
struct BIT
{
	signed bit[N*70];
	inline void add(int x,int k)
	{
		while(x<=sum[n])
			bit[x]+=k,x+=x&-x;
		return;
	}
	inline int ask(int x)
	{
		int res=0;
		while(x)
			res+=bit[x],x&=x-1;
		return res;
	}
}t0,t1;
inline int count(int x)
{
	int res=0;
	while(x)
		res++,x&=x-1;
	return res;
}
void solve(int l,int r)
{
	int now=l;
	register int i;
	if(l>r)
		return;
	for(i=l+1;i<=r;i++)
		if(a[i]>a[now]||(a[i]==a[now]&&max(i-l,r-i)<max(now-l,r-now)))
			now=i;
	for(i=l-1;i<=now-1;i++)
		if(sum[i]&1)
			t1.add(sum[i],1);
		else
			t0.add(sum[i],1);
	for(i=now;i<=r;i++)
		if(sum[i]&1)
		{
			if(sum[i]-a[now]*2>=0)
				ans+=t1.ask(sum[i]-a[now]*2);
		}
		else
		{
			if(sum[i]-a[now]*2>=0)
				ans+=t0.ask(sum[i]-a[now]*2);
		}
	for(i=l-1;i<=now-1;i++)
		if(sum[i]&1)
			t1.add(sum[i],-1);
		else
			t0.add(sum[i],-1);
	solve(l,now-1);solve(now+1,r);
	return;
}
signed main()
{
	register int i;
	scanf("%lld",&n);
	sum[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]=count(a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}