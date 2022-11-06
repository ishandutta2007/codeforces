#include<cstdio>
#include<algorithm>
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
inline int count(int l,int r)
{
	if(l>r)
		return 0;
	return r-l+1;
}
const int N=1e6+5;
int n,ans;
int a[N],fact[N],ifact[N];
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
	int l,r;
	register int i;
	scanf("%d",&n);init(2*n);
	for(i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+2*n+1);
	for(i=1;i<=2*n;i++)
		a[i]%=mod;
	for(i=1;i<=n;i++)
		ans=sub(ans,a[i]);
	for(i=n+1;i<=2*n;i++)
		ans=add(ans,a[i]);
	printf("%d\n",mul(ans,choose(2*n,n)));
	return 0;
}