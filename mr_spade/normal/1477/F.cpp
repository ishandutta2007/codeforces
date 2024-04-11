#include<cstdio>
#include<cstring>
#include<algorithm>
using std::swap;
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
const int N=55,M=2005;
int fact[M],ifact[M],inv[M];
inline void init(int n)
{
	register int i;
	fact[0]=1;
	for(i=1;i<=n;i++)
		fact[i]=mul(fact[i-1],i);
	ifact[n]=qpow(fact[n],mod-2);
	for(i=n-1;i>=0;i--)
		ifact[i]=mul(ifact[i+1],i+1);
	for(i=1;i<=n;i++)
		inv[i]=mul(ifact[i],fact[i-1]);
	return;
}
int rev[M<<2];
int *F[M<<2],*G[M<<2];
inline void ntt(int **f,int n,int m,int p)
{
	int w,wi,u,t;
	register int v,i,j,k;
	for(v=0;v<n;v++)
	{
		for(i=0;i<m;i++)
			if(i<(rev[i]=i&1?rev[i^1]|m>>1:rev[i>>1]>>1))
				swap(f[v][i],f[v][rev[i]]);
		for(i=1;wi=qpow(p^1?inv[3]:3,(mod-1)/(i<<1)),i<<1<=m;i<<=1)
			for(j=0;w=1,j<m;j+=i<<1)
				for(k=0;k<i;w=mul(w,wi),k++)
					u=f[v][j+k],t=mul(w,f[v][j+k+i]),f[v][j+k]=add(u,t),f[v][j+k+i]=sub(u,t);
		if(!~p)
			for(w=qpow(m,mod-2),i=0;i<m;i++)
				f[v][i]=mul(w,f[v][i]);
	}
	for(v=0;v<m;v++)
	{
		for(i=0;i<n;i++)
			if(i<(rev[i]=i&1?rev[i^1]|n>>1:rev[i>>1]>>1))
				swap(f[i][v],f[rev[i]][v]);
		for(i=1;wi=qpow(p^1?inv[3]:3,(mod-1)/(i<<1)),i<<1<=n;i<<=1)
			for(j=0;w=1,j<n;j+=i<<1)
				for(k=0;k<i;w=mul(w,wi),k++)
					u=f[j+k][v],t=mul(w,f[j+k+i][v]),f[j+k][v]=add(u,t),f[j+k+i][v]=sub(u,t);
		if(!~p)
			for(w=qpow(n,mod-2),i=0;i<n;i++)
				f[i][v]=mul(w,f[i][v]);
	}
	return;
}
inline void poly_mul(int **f,int nf,int mf,int **g,int ng,int mg,int **h)
{
	int n,m;
	register int i,j;
	for(n=1;n<nf||n<ng;n<<=1);
	for(m=1;m<mf||m<mg;m<<=1);
	for(i=0;i<n<<1;i++)
		memset(F[i],0,sizeof(int)*(m<<1)),memset(G[i],0,sizeof(int)*(m<<1));
	for(i=0;i<nf;i++)
		memcpy(F[i],f[i],sizeof(int)*mf);
	for(i=0;i<ng;i++)
		memcpy(G[i],g[i],sizeof(int)*mg);
	ntt(F,n<<1,m<<1,1);ntt(G,n<<1,m<<1,1);
	for(i=0;i<n<<1;i++)
		for(j=0;j<m<<1;j++)
			F[i][j]=mul(F[i][j],G[i][j]);
	ntt(F,n<<1,m<<1,-1);
	for(i=0;i<nf+ng-1;i++)
		memcpy(h[i],F[i],sizeof(int)*(mf+mg-1));
	return;
}
int n,K,L,omega,ans;
int l[N];
int **pool[N<<2],nlen[N<<2],mlen[N<<2];
int a[M][N];
void run(int x,int lp,int rp)
{
	register int i,j;
	if(lp==rp)
	{
		int w=mul(l[lp],qpow(L,mod-2)),wi;
		nlen[x]=l[lp]/K+1;mlen[x]=2;
		pool[x]=new int *[l[lp]/K+1];
		for(i=0;i<=l[lp]/K;i++)
			pool[x][i]=new int [2],pool[x][i][0]=pool[x][i][1]=0;
		pool[x][0][0]=1;
		for(i=1;i<=l[lp]/K;i++)
		{
			wi=sub(w,mul(i,omega));
			if(i&1)
				pool[x][i][0]=sub(0,mul(qpow(wi,i),ifact[i])),pool[x][i][1]=sub(0,mul(wi?qpow(wi,i-1):0,ifact[i-1]));
			else
				pool[x][i][0]=mul(qpow(wi,i),ifact[i]),pool[x][i][1]=mul(wi?qpow(wi,i-1):0,ifact[i-1]);
		}
		return;
	}
	int mid=(lp+rp)>>1;
	run(x<<1,lp,mid);run(x<<1|1,mid+1,rp);
	nlen[x]=nlen[x<<1]+nlen[x<<1|1]-1;mlen[x]=mlen[x<<1]+mlen[x<<1|1]-1;
	pool[x]=new int *[nlen[x]];
	for(i=0;i<nlen[x];i++)
		pool[x][i]=new int [mlen[x]];
	poly_mul(pool[x<<1],nlen[x<<1],mlen[x<<1],pool[x<<1|1],nlen[x<<1|1],mlen[x<<1|1],pool[x]);
	return;
}
inline int sum(int k,int c)
{
	return mul(fact[k],qpow(qpow(sub(1,c),mod-2),k+1));
}
signed main()
{
	int w;
	register int i,j;
	for(i=0;i<M<<2;i++)
		F[i]=new int[N<<2],G[i]=new int[N<<2];
	scanf("%d%d",&n,&K);
	for(i=1;i<=n;i++)
		scanf("%d",&l[i]),L+=l[i];
	init(L);
	omega=mul(K,qpow(L,mod-2));
	run(1,1,n);
	for(i=0;i<nlen[1];i++)
		for(j=0;j<mlen[1];j++)
			a[i][j]=sub(0,pool[1][i][j]);
	a[0][0]=add(a[0][0],1);
	for(i=0;i<nlen[1];i++)
		for(j=0;j<mlen[1];j++)
			if(a[i][j])
				ans=add(ans,mul(a[i][j],sum(i-j,sub(1,mul(i,omega)))));
	printf("%d\n",ans);
	return 0;
}