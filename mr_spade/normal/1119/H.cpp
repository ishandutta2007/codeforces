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
const int inv4=qpow(4,mod-2);
const int N=1e5+5,M=(1<<17)+5;
int n,m,e;
int alpha,beta,gama;
int a[N],b[N];
int f[M],g[M],h[M];
int ans[M],tans[M];
inline void fwt(int *f,int n,int p)
{
	int w,u,t;
	register int i,j,k;
	for(i=1;i<<1<=n;i<<=1)
		for(j=0;j<n;j+=i<<1)
			for(k=0;k<i;k++)
				u=f[j+k],t=f[j+k+i],f[j+k]=add(u,t),f[j+k+i]=sub(u,t);
	if(!~p)
		for(w=qpow(n,mod-2),i=0;i<n;i++)
			f[i]=mul(w,f[i]);
	return;
}
signed main()
{
	int x,y,z;
	register int i;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&alpha,&beta,&gama);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",&x,&a[i],&b[i]),e^=x,a[i]^=x,b[i]^=x;
	for(i=1;i<=n;i++)
		f[a[i]]=add(f[a[i]],1);
	fwt(f,1<<m,1);
	for(i=1;i<=n;i++)
		g[b[i]]=add(g[b[i]],1);
	fwt(g,1<<m,1);
	for(i=1;i<=n;i++)
		h[a[i]^b[i]]=add(h[a[i]^b[i]],1);
	fwt(h,1<<m,1);
	for(i=0;i<1<<m;i++)
	{
		x=mul(add(add(n,f[i]),add(g[i],h[i])),inv4);
		y=mul(add(sub(n,f[i]),sub(g[i],h[i])),inv4);
		z=mul(sub(add(n,f[i]),add(g[i],h[i])),inv4);
		ans[i]=1;
		ans[i]=mul(ans[i],qpow(add(add(alpha,beta),gama),x));
		ans[i]=mul(ans[i],qpow(add(sub(alpha,beta),gama),y));
		ans[i]=mul(ans[i],qpow(sub(add(alpha,beta),gama),z));
		ans[i]=mul(ans[i],qpow(sub(sub(alpha,beta),gama),n-x-y-z));
	}
	fwt(ans,1<<m,-1);
	for(i=0;i<1<<m;i++)
		tans[i^e]=ans[i];
	for(i=0;i<1<<m;i++)
		printf("%d ",tans[i]);
	putchar('\n');
	return 0;
}