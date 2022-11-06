#include<cstdio>
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
int n,ans;
signed main()
{
	register int i;
	scanf("%d",&n);
	ans=1;
	for(i=1;i<=n;i++)
		ans=mul(ans,i);
	ans=sub(ans,qpow(2,n-1));
	printf("%d\n",ans);
	return 0;
}