// LUOGU_RID: 90302157
#include<cstdio>
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
constexpr int N=5e5+5,M=1e6+5;
template<typename T,int N>struct BIT
{
	int n;
	T c[N];
	void init(int n_){n=n_;F(i,1,n+1)c[i]=0;}
	void add(int x,T y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	T sum(int x){T ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
	int binary(T x)
	{
		int ans=0;
		for(int delta=1<<(31-__builtin_clz(n));delta;delta>>=1)
			if(ans+delta<=n&&c[ans+delta]<=x)x-=c[ans+=delta];
		return ans;
	}
};
BIT<int,N> cb;
BIT<long long,N> ca;
int n,m,ia,ib,fa[M],fb[M],sa[M][2],sb[M][2],siz[M];
long long ans[N];
vector<int> a[M],b[M],add[M],del[M],q[N];
int finda(int x){return fa[x]==x?x:fa[x]=finda(fa[x]);}
int findb(int x){return fb[x]==x?x:fb[x]=findb(fb[x]);}
void dfsb(int u)
{
	for(int i:del[u])cb.add(i,1);
	if(u<n)
	{
		for(int i:q[u])
		{
			int t=cb.sum(i);
			ans[i]=t?cb.binary(--t)+1:0;
		}
	}
	else
	{
		dfsb(sb[u][0]);
		dfsb(sb[u][1]);
	}
	for(int i:del[u])cb.add(i,-1);
}
void dfsa(int u)
{
	for(int i:add[u])ca.add(i,siz[u]);
	if(u<n)for(int i:q[u])ans[i]=ca.sum(i)-ca.sum((int)ans[i]);
	else
	{
		dfsa(sa[u][0]);
		dfsa(sa[u][1]);
	}
	for(int i:add[u])ca.add(i,-siz[u]);
}
int main()
{
	read(n,m);
	ia=ib=n;
	F(i,0,2*n)fa[i]=fb[i]=i;
	F(i,0,n)siz[i]=1;
	F(i,0,m)
	{
		char tmp[2],opt;
		scanf("%s",tmp);opt=tmp[0]^32;
		if(opt=='u')
		{
			int c,d;read(c,d);--c,--d;
			c=finda(c);d=finda(d);
			sa[ia][0]=c;
			sa[ia][1]=d;
			siz[ia]=siz[c]+siz[d];
			fa[c]=fa[d]=ia++;
		}
		if(opt=='m')
		{
			int c,d;read(c,d);--c,--d;
			c=findb(c);d=findb(d);
			sb[ib][0]=c;
			sb[ib][1]=d;
			fb[c]=fb[d]=ib++;
		}
		if(opt=='a')
		{
			int c;--read(c);
			c=finda(c);
			add[c].emplace_back(i);
		}
		if(opt=='z')
		{
			int c;--read(c);
			c=findb(c);
			del[c].emplace_back(i);
		}
		if(opt=='q')
		{
			int c;--read(c);
			q[c].emplace_back(i);
		}
	}
	F(i,0,m)ans[i]=-1;
	cb.init(m);
	F(i,0,ib)if(fb[i]==i)dfsb(i);
	ca.init(m);
	F(i,0,ia)if(fa[i]==i)dfsa(i);
	F(i,0,m)if(~ans[i])printf("%lld\n",ans[i]);
	return 0;
}