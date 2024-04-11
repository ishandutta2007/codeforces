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
const int N=1e6+5;
int n,m,ans;
int fact[N],ifact[N];
inline int choose(int n,int m)
{
	return mul(fact[n],mul(ifact[m],ifact[n-m]));
}
inline void init(int n)
{
	register int i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[n]=qpow(fact[n],mod-2);
	for(i=n-1;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	return;
}
signed main()
{
	register int i;
	scanf("%d%d",&n,&m);
	init(1000000);
	for(i=1;i<=m&&i<=n-1;i++)
		ans=add(ans,mul(mul(choose(n-2,i-1),fact[i-1]),mul(mul(qpow(n,((n-i-2)%(mod-1)+(mod-1))%(mod-1)),i+1),mul(choose(m-1,i-1),qpow(m,n-1-i)))));
	printf("%d\n",ans);
	return 0;
}