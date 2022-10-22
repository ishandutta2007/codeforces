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
unsigned int readtoken()
{
	unsigned int c=getchar();
	while(c<=32)c=getchar();
	while(getchar()>32);
	return c;
}
constexpr int N=2e5+5,m=200001;
constexpr long long LLINF=0x3fffffffffffffffll;
namespace seg
{
	constexpr int N=1e7+5;
	struct node
	{
		int ls,rs;
		long long mn,tg;
	}s[N];
#define ls(x) s[x].ls
#define rs(x) s[x].rs
#define mn(x) s[x].mn
#define tg(x) s[x].tg
	int ind;
	int merge(int p,int q)
	{
		if(!(p&&q))return p|q;
		if(ls(p))tg(ls(p))+=tg(p),mn(ls(p))+=tg(p);
		if(rs(p))tg(rs(p))+=tg(p),mn(rs(p))+=tg(p);
		tg(p)=0;
		if(ls(q))tg(ls(q))+=tg(q),mn(ls(q))+=tg(q);
		if(rs(q))tg(rs(q))+=tg(q),mn(rs(q))+=tg(q);
		tg(q)=0;
		ls(p)=merge(ls(p),ls(q));
		rs(p)=merge(rs(p),rs(q));
		mn(p)=min(mn(p),mn(q));
		return p;
	}
	int build(int l,int r,int x,long long v)
	{
		int p=++ind;
		mn(p)=v;
		if(r-l==1)return p;
		int mid=(l+r)>>1;
		if(x<mid)ls(p)=build(l,mid,x,v);
		else rs(p)=build(mid,r,x,v);
		return p;
	}
	long long query(int p,int l,int r,int x)
	{
		if(!p)return LLINF;
		if(r-l==1)return mn(p);
		int mid=(l+r)>>1;
		if(ls(p))tg(ls(p))+=tg(p),mn(ls(p))+=tg(p);
		if(rs(p))tg(rs(p))+=tg(p),mn(rs(p))+=tg(p);
		tg(p)=0;
		if(x<mid)return query(ls(p),l,mid,x);
		return query(rs(p),mid,r,x);
	}
	long long query(int p,int x)
	{
		return query(p,0,m,x);
	}
	long long query(int p,int l,int r,int x,int y)
	{
		int mid=(l+r)>>1;
		if(!p)return LLINF;
		if(x==l&&r==y)return mn(p);
		if(ls(p))tg(ls(p))+=tg(p),mn(ls(p))+=tg(p);
		if(rs(p))tg(rs(p))+=tg(p),mn(rs(p))+=tg(p);
		tg(p)=0;
		if(y<=mid)return query(ls(p),l,mid,x,y);
		if(mid<=x)return query(rs(p),mid,r,x,y);
		return min(query(ls(p),l,mid,x,mid),query(rs(p),mid,r,mid,y));
	}
	long long query(int p,int x,int y)
	{
		if(x>=y)return LLINF;
		return query(p,0,m,x,y);
	}
	void update(int p,int l,int r,int x,int y,long long v)
	{
		int mid=(l+r)>>1;
		if(!p||y<=l||r<=x)return;
		if(x<=l&&r<=y)
		{
			tg(p)+=v;mn(p)+=v;
			return;
		}
		if(ls(p))tg(ls(p))+=tg(p),mn(ls(p))+=tg(p);
		if(rs(p))tg(rs(p))+=tg(p),mn(rs(p))+=tg(p);
		tg(p)=0;
		if(x<mid)update(ls(p),l,mid,x,y,v);
		if(mid<y)update(rs(p),mid,r,x,y,v);
		mn(p)=min(mn(ls(p)),mn(rs(p)));
	}
	void update(int p,int x,int y,long long v)
	{
		if(x>=y)return;
		update(p,0,m,x,y,v);
	}
}
using seg::merge;
using seg::build;
using seg::query;
using seg::update;
int n,s;
int dfs(int x,long long w)
{
	int rt=x!=s?build(0,m,x,w):0;
	while(true)
	{
		unsigned opt=readtoken();--n;
		if(opt=='e')return rt;
		if(rt)
		{
			if(opt=='i')
			{
				int y;read(y);
				long long t=query(rt,y);
				if(t!=LLINF)update(rt,y,y+1,LLINF-t);
				rt=merge(rt,dfs(y,t));
			}
			if(opt=='s')
			{
				int y,v;read(y,v);
				long long t=query(rt,0,m);
				update(rt,0,y,v);
				update(rt,y+1,m,v);
				if(y!=s)rt=merge(rt,build(0,m,y,t));
			}
		}
		else
		{
			if(opt=='i')
			{
				int y;read(y);
				dfs(s,s);
			}
			if(opt=='s')
			{
				int y,v;read(y,v);
			}
		}
	}
}
int main()
{
	seg::mn(0)=LLINF;
	read(n,s);
	int rt=build(0,m,0,0);
	while(n>0)
	{
		unsigned opt=readtoken();--n;
		if(opt=='i')
		{
			int y;read(y);
			long long t=query(rt,y);
			if(t!=LLINF)update(rt,y,y+1,LLINF-t);
			rt=merge(rt,dfs(y,t));
		}
		if(opt=='s')
		{
			int y,v;read(y,v);
			long long t=query(rt,0,m);
			update(rt,0,y,v);
			update(rt,y+1,m,v);
			if(y!=s)rt=merge(rt,build(0,m,y,t));
		}
	}
	printf("%lld\n",min(query(rt,0,s),query(rt,s+1,m)));
	return 0;
}