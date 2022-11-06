#include<cstdio>
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
const int N=1e6+5;
int n,ans;
int fact[N],ifact[N];
inline int choose(int x,int y)
{
	return mul(fact[x],mul(ifact[y],ifact[x-y]));
}
signed main()
{
	register int i;
	scanf("%d",&n);
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[n]=qpow(fact[n],mod-2);
	for(i=n-1;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	for(i=0;i<=n;i++)
		ans=add(ans,sub(fact[n],mul(fact[n],ifact[n-i])));
	printf("%d\n",add(ans,1));
	return 0;
}