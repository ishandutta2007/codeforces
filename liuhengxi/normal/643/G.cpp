// LUOGU_RID: 90430380
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
constexpr int N=1.5e5+5,INF=0x3fffffff;
int k;
namespace seg
{
	struct data
	{
		int v[5],b[5],siz,tag;
	}s[(1<<19)+5];
#define lc (p<<1)
#define rc (p<<1|1)
	inline void merge(data &a,const data &c)
	{
		for(int i=0;i<k;++i)if(c.b[i])
		{
			int mn=c.b[i];
			int t=c.b[i];
			for(int j=0;j<k;++j)if(a.v[j]==c.v[i]){a.b[j]+=t,t=0;break;}
			else mn=min(mn,a.b[j]);
			if(!t)continue;
			if(!mn)
			{
				for(int j=0;j<k;++j)if(!a.b[j]){a.v[j]=c.v[i],a.b[j]=t;break;}
				continue;
			}
			t-=mn;
			for(int j=0;j<k;++j)if(!(a.b[j]-=mn)&&t)a.v[j]=c.v[i],a.b[j]=t,t=0;
		}
	}
	inline void merge(data &a,const data &b,const data &c)
	{
		a=b;
		a.tag=0;
		a.siz=b.siz+c.siz;
		for(int i=0;i<k;++i)if(c.b[i])
		{
			int mn=c.b[i];
			int t=c.b[i];
			for(int j=0;j<k;++j)if(a.v[j]==c.v[i]){a.b[j]+=t,t=0;break;}
			else mn=min(mn,a.b[j]);
			if(!t)continue;
			if(!mn)
			{
				for(int j=0;j<k;++j)if(!a.b[j]){a.v[j]=c.v[i],a.b[j]=t;break;}
				continue;
			}
			t-=mn;
			for(int j=0;j<k;++j)if(!(a.b[j]-=mn)&&t)a.v[j]=c.v[i],a.b[j]=t,t=0;
		}
	}
	inline void assign(int p,int v)
	{
		F(i,1,k)s[p].v[i]=s[p].b[i]=0;
		s[p].v[0]=v;s[p].b[0]=s[p].siz;
		s[p].tag=v;
	}
	inline void pushdown(int p)
	{
		if(!s[p].tag)return;
		assign(lc,s[p].tag);
		assign(rc,s[p].tag);
		s[p].tag=0;
	}
	void build(int p,int l,int r,int *a)
	{
		if(r-l==1)return s[p].v[0]=a[l],s[p].b[0]=1,s[p].siz=1,void();
		int mid=(l+r)>>1;
		build(lc,l,mid,a);build(rc,mid,r,a);
		merge(s[p],s[lc],s[rc]);
	}
	void assign(int p,int l,int r,int x,int y,int v)
	{
		if(x==l&&r==y)return assign(p,v);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)assign(lc,l,mid,x,y,v);
		else if(mid<=x)assign(rc,mid,r,x,y,v);
		else assign(lc,l,mid,x,mid,v),assign(rc,mid,r,mid,y,v);
		merge(s[p],s[lc],s[rc]);
	}
	void query(int p,int l,int r,int x,int y,data &ans)
	{
		if(x==l&&r==y)return merge(ans,s[p]);
		int mid=(l+r)>>1;
		pushdown(p);
		if(y<=mid)return query(lc,l,mid,x,y,ans);
		if(mid<=x)return query(rc,mid,r,x,y,ans);
		query(lc,l,mid,x,mid,ans),query(rc,mid,r,mid,y,ans);
	}
#undef lc
#undef rc
}
using seg::build;
using seg::assign;
using seg::query;
int n,m,p,a[N];
int main()
{
	read(n,m,p);k=100/p;
	F(i,0,n)read(a[i]);
	build(1,0,n,a);
	while(m--)
	{
		int opt,l,r;read(opt,l,r);--l;
		if(opt==1)
		{
			int v;read(v);
			assign(1,0,n,l,r,v);
		}
		if(opt==2)
		{
			seg::data ans;
			F(i,0,k)ans.v[i]=ans.b[i]=0;
			query(1,0,n,l,r,ans);
			printf("%d ",k);
			F(i,0,k)printf("%d ",ans.v[i]);
			puts("");
		}
	}
	return 0;
}