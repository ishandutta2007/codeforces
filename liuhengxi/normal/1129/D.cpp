// LUOGU_RID: 90342162
#include<cstdio>
#include<algorithm>
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
constexpr int N=1e5+5,B=325,MOD=998244353;
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
namespace block
{
	int b,a[N],t[N],s[B][2*B];
	const int *w;
	inline void pushdown(int u)
	{
		if(t[u]==0)return;
		F(i,b*u,b*u+b)a[i]+=t[u];
		t[u]=0;
	}
	inline void pushup(int u)
	{
		int d=a[b*u]-b;
		F(i,0,2*b+1)s[u][i]=0;
		F(i,b*u,b*u+b)reduce(s[u][a[i]-d]+=w[i]);
		F(i,0,2*b)reduce(s[u][i+1]+=s[u][i]);
	}
	void update(int l,int r,int v)
	{
		if(r-l<2*b)
		{
			pushdown(l/b);
			if((r-1)/b!=l/b)pushdown((r-1)/b);
			F(i,l,r)a[i]+=v;
			pushup(l/b);
			if((r-1)/b!=l/b)pushup((r-1)/b);
			return;
		}
		if(l%b)
		{
			pushdown(l/b);
			F(i,l,l/b*b+b)a[i]+=v;
			pushup(l/b);
			l=l/b*b+b;
		}
		if(r%b)
		{
			pushdown(r/b);
			F(i,r/b*b,r)a[i]+=v;
			pushup(r/b);
			r=r/b*b;
		}
		F(i,l/b,r/b)t[i]+=v;
	}
	int query(int l,int r,int k)
	{
		int ans=0;
		if(r-l<2*b)
		{
			pushdown(l/b);
			if((r-1)/b!=l/b)pushdown((r-1)/b);
			F(i,l,r)if(a[i]<=k)reduce(ans+=w[i]);
			return ans;
		}
		if(l%b)
		{
			pushdown(l/b);
			F(i,l,l/b*b+b)if(a[i]<=k)reduce(ans+=w[i]);
			l=l/b*b+b;
		}
		if(r%b)
		{
			pushdown(r/b);
			F(i,r/b*b,r)if(a[i]<=k)reduce(ans+=w[i]);
			r=r/b*b;
		}
		F(i,l/b,r/b)if(k-t[i]-a[b*i]>=-b)reduce(ans+=s[i][min(k-t[i]-a[b*i]+b,2*b)]);
		return ans;
	}
}
using block::b;
using block::update;
using block::query;
int n,k,a[N],last[N],pre[N],f[N];
int main()
{
	read(n,k);while(b*b<n)++b;
	F(i,0,n)last[i]=-1;
	F(i,0,n)pre[i]=last[--read(a[i])],last[a[i]]=i;
	block::w=f;
	f[0]=1;
	F(i,0,n)
	{
		update(pre[i]+1,i+1,1);
		if(~pre[i])update(pre[pre[i]]+1,pre[i]+1,-1);
		f[i+1]=query(0,i+1,k);
		block::pushup((i+1)/b);
	}
	printf("%d\n",f[n]);
	return 0;
}