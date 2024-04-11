#include<cstdio>
#include<cstring>
#define int long long
const int mod=1e9+7;
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
const int N=5e5+5;
int n;
int a[N];
int pow2[N],cnt[N];
inline void solve()
{
	int ans=0,xa,xo;
	register int i,j;
	scanf("%lld",&n);
	memset(cnt,0,sizeof(int)*60);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(j=0;j<60;j++)
			if(a[i]>>j&1)
				cnt[j]++;
	}
	for(i=1;i<=n;i++)
	{
		xa=xo=0;
		for(j=0;j<60;j++)
			if(a[i]>>j&1)
				xa=add(xa,mul(pow2[j],cnt[j]));
		for(j=0;j<60;j++)
			if(a[i]>>j&1)
				xo=add(xo,mul(pow2[j],n));
			else
				xo=add(xo,mul(pow2[j],cnt[j]));
		ans=add(ans,mul(xa,xo));
	}
	printf("%lld\n",ans);
	return;
}
signed main()
{
	int T;
	register int i;
	pow2[0]=1;
	for(i=1;i<=60;i++)
		pow2[i]=mul(pow2[i-1],2);
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}