#include<cstdio>
#include<vector>
#include<unordered_set>
using std::vector;
using std::unordered_set;
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
const int N=(1<<20)+5;
inline void fwt(int *f,int n,int p)
{
	int w,u,t;
	register int i,j,k;
	for(i=1;i<<1<=1<<n;i<<=1)
		for(j=0;j<1<<n;j+=i<<1)
			for(k=0;k<i;k++)
				u=f[j+k],t=f[j+k+i],f[j+k]=add(u,t),f[j+k+i]=sub(u,t);
	if(!~p)
		for(w=qpow(inv2,n),i=0;i<1<<n;i++)
			f[i]=mul(w,f[i]);
	return;
}
int n,m;
int bk[N],w[N];
vector<int> e[N];
unordered_set<int> S[N];
int f[N];
void dfs(int x)
{
	if(bk[x])
		return;
	bk[x]=1;
	for(int y:e[x])
		dfs(y),S[x].insert(w[y]);
	for(w[x]=0;S[x].find(w[x])!=S[x].end();w[x]++);
	return;
}
signed main()
{
	int x,y,_;
	register int i;
	scanf("%d%d",&n,&m);
	while(m--)
		scanf("%d%d",&x,&y),e[x].push_back(y);
	for(i=1;i<=n;i++)
		if(!bk[i])
			dfs(i);
	int p=qpow(n+1,mod-2);
	for(i=1;i<=n;i++)
		f[w[i]]=add(f[w[i]],p);
	for(_=1;1<<_<=n;_++);
	fwt(f,_,1);
	for(i=0;i<1<<_;i++)
		f[i]=qpow(sub(1,f[i]),mod-2);
	fwt(f,_,-1);
	printf("%d\n",sub(1,mul(f[0],p)));
	return 0;
}