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
const int N=2e5+5;
int n;
int a[N],s[N];
signed main()
{
	register int i;
	scanf("%d",&n);
	a[0]=s[0]=a[1]=s[1]=1;
	for(i=2;i<=n;i++)
		a[i]=s[i-1],s[i]=add(s[i-2],a[i]);
	printf("%d\n",mul(a[n],qpow(qpow(2,n),mod-2)));
}