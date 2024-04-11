#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::swap;
const int mod=998244353,inv2=(mod+1)/2;
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
const int N=2e6+5;
int rev[N],inv[N];
inline void ntt(int *f,int n,int p)
{
	int w,wi,u,t;
	register int i,j,k;
	for(i=0;i<n;i++)
		if(i<(rev[i]=i&1?rev[i^1]|n>>1:rev[i>>1]>>1))
			swap(f[i],f[rev[i]]);
	for(i=1;wi=qpow(qpow(3,(mod-1)/(i<<1)),p^1?mod-2:1),i<<1<=n;i<<=1)
		for(j=0;w=1,j<n;j+=i<<1)
			for(k=0;k<i;w=mul(w,wi),k++)
				u=f[j+k],t=mul(w,f[j+k+i]),f[j+k]=add(u,t),f[j+k+i]=sub(u,t);
	if(!~p)
		for(w=qpow(n,mod-2),i=0;i<n;i++)
			f[i]=mul(w,f[i]);
	return;
}
int F[N],G[N];
inline void poly_mul(int *f,int *g,int n)
{
	register int i;
	memset(f+n,0,sizeof(int)*n);
	memset(g+n,0,sizeof(int)*n);
	ntt(f,n<<1,1);f==g?void():ntt(g,n<<1,1);
	for(i=0;i<n<<1;i++)
		f[i]=mul(f[i],g[i]);
	ntt(f,n<<1,-1);f==g?void():ntt(g,n<<1,-1);
	return;
}
int _g[N];
inline void poly_inv(int *f,int n)
{
	register int i,j;
	memset(_g,0,sizeof(int)*n);
	_g[0]=qpow(f[0],mod-2);
	for(i=1;i<<1<=n;i<<=1)
	{
		memcpy(F,f,sizeof(int)*(i<<1));
		memcpy(G,_g,sizeof(int)*i);
		poly_mul(G,G,i);poly_mul(F,G,i<<1);
		for(j=0;j<i<<1;j++)
			_g[j]=sub(mul(2,_g[j]),F[j]);
	}
	memcpy(f,_g,sizeof(int)*n);
	return;
}
inline void poly_rev(int *f,int n)
{
  register int i;
  for(i=0;i<n-1-i;i++)
    swap(f[i],f[n-1-i]);
  return;
}
int _q[N];
inline void poly_mod(int *f,int n,int *g,int m)
{
  register int i;
  poly_rev(f,n);poly_rev(g,m);
  memset(g+m,0,sizeof(int)*(n-m));
  poly_inv(g,n);
  memcpy(F,f,sizeof(int)*n);
  memcpy(G,g,sizeof(int)*n);
  poly_mul(F,G,n);
  memcpy(_q,F,sizeof(int)*(n-m+1));
  poly_inv(g,n);poly_rev(g,m);
  poly_rev(f,n);poly_rev(_q,n-m+1);
  memcpy(F,g,sizeof(int)*n);
  memcpy(G,_q,sizeof(int)*n);
  poly_mul(F,G,n);
  for(i=0;i<m-1;i++)
    f[i]=sub(f[i],F[i]);
  memset(f+m-1,0,sizeof(int)*(n-m+1));
  return;
}
inline void poly_der(int *f,int n)
{
	register int i;
	for(i=0;i<n-1;i++)
		f[i]=mul(i+1,f[i+1]);
	f[n-1]=0;
	return;
}
inline void poly_int(int *f,int n)
{
	register int i;
	for(i=n-1;i>0;i--)
		f[i]=mul(inv[i],f[i-1]);
	f[0]=0;
	return;
}
int _f_[N];
inline void poly_ln(int *f,int n)
{
	memcpy(_f_,f,sizeof(int)*n);
	poly_inv(f,n);poly_der(_f_,n);
	poly_mul(f,_f_,n);
	memset(f+n,0,sizeof(int)*n);
	poly_int(f,n);
	return;
}
int _g_[N],_lg_[N];
inline void poly_exp(int *f,int n)
{
	register int i,j;
	memset(_g_,0,sizeof(int)*n);
	memset(_lg_,0,sizeof(int)*n);
	_g_[0]=1;
	for(i=1;i<<1<=n;i<<=1)
	{
		memcpy(_lg_,_g_,sizeof(int)*i);
		poly_ln(_lg_,i<<1);
		for(j=0;j<i<<1;j++)
			F[j]=sub(f[j],_lg_[j]);
		F[0]=add(F[0],1);
		poly_mul(F,_g_,i<<1);
		memcpy(_g_,F,sizeof(int)*(i<<1));
	}
	memcpy(f,_g_,sizeof(int)*n);
	return;
}
int _r[N],_r_[N];
inline void poly_sqrt(int *f,int n)
{
	register int i,j;
	memset(_r,0,sizeof(int)*n);
	_r[0]=1;
	for(i=1;i<<1<=n;i<<=1)
	{
		memcpy(_r_,_r,sizeof(int)*(i<<1));
		poly_inv(_r_,i<<1);
		memcpy(F,f,sizeof(int)*(i<<1));
		poly_mul(F,_r_,i<<1);
		for(j=0;j<i<<1;j++)
			_r[j]=mul(inv2,add(_r[j],F[j]));
	}
	memcpy(f,_r,sizeof(int)*n);
	return;
}
int n,m;
int a[N];
signed main()
{
	int _=1<<17,x;
	register int i;
	scanf("%d%d",&n,&m);
	while(n--)
		scanf("%d",&x),a[x]=sub(0,4);
	a[0]=1;
	poly_sqrt(a,_);
	a[0]=add(a[0],1);
	poly_inv(a,_);
	for(i=0;i<_;i++)
		a[i]=mul(2,a[i]);
	for(i=1;i<=m;i++)
		printf("%d\n",a[i]);
	return 0;
}