#include<cstdio>
#include<cstring>
#include<algorithm>
#define abs Mr_abs
using std::reverse;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int mod=998244353;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a-mod:a;
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
int fact[N],ifact[N];
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
inline int choose(int n,int m)
{
	return mul(fact[n],mul(ifact[m],ifact[n-m]));
}
int n,m,ans;
char s[N];
int a[N];
int f[N];
signed main()
{
	int b=0,f=0,f1=0;
	register int i;
	scanf("%d%d",&n,&m);init(n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		a[i]=[&](char ch)->int
		{
			switch(ch)
			{
				case '?':f++;f1+=(i&1);return 2;
				case 'b':b+=((i&1)?-1:1);return 0;
				case 'w':return 1;
				default:return -1;
			}
		}(s[i]);
	for(i=0;i<=f;i++)
		if(!(abs(b-f1+i)&1))
			ans=add(ans,mul(abs(b-f1+i),choose(f,i)));
	printf("%d\n",mul(ans,qpow(qpow(2,mod-2),f)));
	return 0;
}