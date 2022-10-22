// LUOGU_RID: 90275039
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=15005,K=1005,bas=10000019,MOD=1000000007;
vector<int> s[(1<<16)+5];
int v[N],w[N],f[N][K],top,k;
#define lc (p<<1)
#define rc (p<<1|1)
void update(int p,int l,int r,int x,int y,int i)
{
	if(x==l&&r==y)return s[p].emplace_back(i),void();
	int mid=(l+r)>>1;
	if(y<=mid)update(lc,l,mid,x,y,i);
	else if(mid<=x)update(rc,mid,r,x,y,i);
	else update(lc,l,mid,x,mid,i),update(rc,mid,r,mid,y,i);
}
void dfs(int p,int l,int r)
{
	for(int i:s[p])
	{
		F(j,0,w[i])f[top+1][j]=f[top][j];
		F(j,w[i],k)f[top+1][j]=max(f[top][j],f[top][j-w[i]]+v[i]);
		++top;
	}
	if(r-l==1)
	{
		long long ans=0;
		for(int i=k;--i;)ans=(ans*bas+f[top][i])%MOD;
		printf("%lld\n",ans);
	}
	else
	{
		int mid=(l+r)>>1;
		dfs(lc,l,mid);dfs(rc,mid,r);
	}
	for(int i:s[p])~i&&--top;
}
#undef lc
#undef rc
int n,l[N],r[N],q,m;
int main()
{
	memset(r,0xff,sizeof(r));
	read(n,k);++k;
	F(i,0,n)read(v[i],w[i]);
	read(q);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			read(v[n],w[n]);
			l[n++]=m;
		}
		if(opt==2)
		{
			int x;read(x);
			r[--x]=m;
		}
		if(opt==3)++m;
	}
	F(i,0,n)
	{
		if(!~r[i])r[i]=m;
		if(l[i]<r[i])update(1,0,m,l[i],r[i],i);
	}
	dfs(1,0,m);
	return 0;
}