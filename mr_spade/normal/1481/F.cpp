#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::max;
using std::swap;
using std::vector;
const int mod=1004535809;
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
const int inv3=qpow(3,mod-2);
const int N=8e5+5;
int rev[N];
inline void ntt(int *f,int n,int p)
{
	int w,wi,u,t;
	register int i,j,k;
	for(i=0;i<n;i++)
		if(i<(rev[i]=i&1?rev[i^1]|n>>1:rev[i>>1]>>1))
			swap(f[i],f[rev[i]]);
	for(i=1;wi=qpow(p^1?inv3:3,(mod-1)/(i<<1)),i<<1<=n;i<<=1)
		for(j=0;w=1,j<n;j+=i<<1)
			for(k=0;k<i;w=mul(w,wi),k++)
				u=f[j+k],t=mul(w,f[j+k+i]),f[j+k]=add(u,t),f[j+k+i]=sub(u,t);
	if(!~p)
		for(w=qpow(n,mod-2),i=0;i<n;i++)
			f[i]=mul(w,f[i]);
	return;
}
int F[N],G[N];
inline int poly_mul(int *f,int n,int *g,int m,int *h)
{
	int _;
	register int i;
	for(_=1;_<n||_<m;_<<=1);
	memcpy(F,f,sizeof(int)*n);
	memset(F+n,0,sizeof(int)*((_<<1)-n));
	memcpy(G,g,sizeof(int)*m);
	memset(G+m,0,sizeof(int)*((_<<1)-m));
	ntt(F,_<<1,1);ntt(G,_<<1,1);
	for(i=0;i<_<<1;i++)
		F[i]=mul(F[i],G[i]);
	ntt(F,_<<1,-1);
	memcpy(h,F,sizeof(int)*(n+m-1));
	return n+m-1;
}
int n,x,maxd;
vector<int> e[N];
int dep[N],cnt[N],cntl[N];
int bk[N];
int *pool[N],len[N];
void dfs(int x,int father)
{
	dep[x]=dep[father]+1;
	maxd=max(maxd,dep[x]);
	cnt[dep[x]]++;
	if(e[x].empty())
		cntl[dep[x]]++;
	for(int y:e[x])
		dfs(y,x);
	return;
}
void solve(int x,int l,int r)
{
	if(l==r)
	{
		len[x]=cnt[l]+1;
		pool[x]=new int[len[x]];
		memset(pool[x],0,sizeof(int)*len[x]);
		pool[x][0]=1;pool[x][cnt[l]]=1;
		return;
	}
	int mid=(l+r)>>1;
	solve(x<<1,l,mid);solve(x<<1|1,mid+1,r);
	len[x]=len[x<<1]+len[x<<1|1]-1;
	pool[x]=new int[len[x]];
	poly_mul(pool[x<<1],len[x<<1],pool[x<<1|1],len[x<<1|1],pool[x]);
	return;
}
void run(int x,int l,int r,int t)
{
	if(l==r)
		return bk[l]=!!t,void();
	int mid=(l+r)>>1;
	register int i;
	for(i=0;i<len[x<<1]&&t-i>=0;i++)
		if(t-i<len[x<<1|1]&&pool[x<<1][i]&&pool[x<<1|1][t-i])
			return run(x<<1,l,mid,i),run(x<<1|1,mid+1,r,t-i);
	throw;
}
void clear(int x,int l,int r)
{
	delete [] pool[x];
	if(l==r)
		return;
	int mid=(l+r)>>1;
	clear(x<<1,l,mid);
	clear(x<<1|1,mid+1,r);
	return;
}
signed main()
{
	int _,y;
	register int i;
	scanf("%d%d",&n,&x);
	for(i=2;i<=n;i++)
		scanf("%d",&_),e[_].push_back(i);
	dfs(1,0);
	solve(1,1,maxd);
	if(pool[1][x])
	{
		run(1,1,maxd,x);
		printf("%d\n",maxd);
		for(i=1;i<=n;i++)
			putchar(bk[dep[i]]?'a':'b');
		putchar('\n');
		return 0;
	}
	clear(1,1,maxd);
	_=1;
	for(i=2;i<=maxd;i++)
		if(cntl[i]>cntl[_])
			_=i;
	cnt[_]-=cntl[_];
	solve(1,1,maxd);
	for(i=0;i<=cntl[_];i++)
		if(x-i<len[1]&&pool[1][x-i])
		{
			run(1,1,maxd,x-i);y=i;
			printf("%d\n",maxd+1);
			for(i=1;i<=n;i++)
				if(dep[i]!=_)
					putchar(bk[dep[i]]?'a':'b');
				else if(!e[i].empty())
					putchar(bk[dep[i]]?'a':'b');
				else
					putchar((y--)>0?'a':'b');
			putchar('\n');
			clear(1,1,maxd);
			return 0;
		}
}