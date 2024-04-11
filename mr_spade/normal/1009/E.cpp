#include<cstdio>
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)
		a-=mod;
	return a;
}
inline int sub(int a,int b)
{
	if((a-=b)<0)
		a+=mod;
	return a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int p)
{
	int res=1;
	for(;p;a=mul(a,a),p>>=1)
		if(p&1)
			res=mul(res,a);
	return res;
}
const int N=1e6+5;
int n,ans;
int a[N];
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		ans=add(ans,mul(a[i],qpow(2,n-i)));
	for(i=1;i<=n-1;i++)
		ans=add(ans,mul(a[i],mul(qpow(2,n-1-i),n-i)));
	printf("%d\n",ans);
	return 0;
}