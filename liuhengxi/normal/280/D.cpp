#include<cstdio>
#include<cstring>
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
constexpr int N=1e5+5,NN=(1<<18)+5;
#define lc (p<<1)
#define rc (p<<1|1)
struct half
{
	int pre,pl,suf,sl,sum,ans,al,ar,len;
	void operator()(int x)
	{
		if((sum=x)>0)pre=suf=ans=x,pl=sl=ar=1,al=0;
		else pre=suf=ans=0,pl=sl=al=ar=0;
		len=1;
	}
	friend half operator+(half a,half b)
	{
		half c;
		if(a.pre>a.sum+b.pre)c.pre=a.pre,c.pl=a.pl;
		else c.pre=a.sum+b.pre,c.pl=a.len+b.pl;
		if(b.suf>b.sum+a.suf)c.suf=b.suf,c.sl=b.sl;
		else c.suf=b.sum+a.suf,c.sl=b.len+a.sl;
		c.sum=a.sum+b.sum;
		c.ans=max(max(a.ans,b.ans),a.suf+b.pre);
		if(c.ans==a.ans)c.al=a.al,c.ar=a.ar;
		else if(c.ans==b.ans)c.al=b.al+a.len,c.ar=b.ar+a.len;
		else c.al=a.len-a.sl,c.ar=a.len+b.pl;
		c.len=a.len+b.len;
		return c;
	}
};
struct data
{
	half h[2];bool neg;
	void operator()(int x){h[0](x);h[1](-x);neg=false;}
	void negate(){swap(h[0],h[1]);neg=!neg;}
	friend data operator+(data a,data b)
	{
		data c;
		c.neg=false;
		c.h[0]=a.h[0]+b.h[0];
		c.h[1]=a.h[1]+b.h[1];
		return c;
	}
}seg[NN];
int n,a[N];
void build(int p,int l,int r)
{
	if(r-l==1)return seg[p](a[l]);
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid,r);
	seg[p]=seg[lc]+seg[rc];
}
inline void negate(int p){seg[p].negate();}
inline void pushdown(int p){if(seg[p].neg)seg[p].neg=false,negate(lc),negate(rc);}
void update(int p,int l,int r,int x)
{
	if(r-l==1)return seg[p](a[l]);
	int mid=(l+r)>>1;
	pushdown(p);
	if(x<mid)update(lc,l,mid,x);
	else update(rc,mid,r,x);
	seg[p]=seg[lc]+seg[rc];
}
void negate(int p,int l,int r,int x,int y)
{
	if(x==l&&r==y)return negate(p);
	int mid=(l+r)>>1;
	pushdown(p);
	if(y<=mid)return negate(lc,l,mid,x,y),seg[p]=seg[lc]+seg[rc],void();
	if(mid<=x)return negate(rc,mid,r,x,y),seg[p]=seg[lc]+seg[rc],void();
	negate(lc,l,mid,x,mid);negate(rc,mid,r,mid,y);
	seg[p]=seg[lc]+seg[rc];
}
half query(int p,int l,int r,int x,int y)
{
	if(x==l&&r==y)return seg[p].h[0];
	int mid=(l+r)>>1;
	pushdown(p);
	if(y<=mid)return query(lc,l,mid,x,y);
	if(mid<=x)return query(rc,mid,r,x,y);
	return query(lc,l,mid,x,mid)+query(rc,mid,r,mid,y);
}
#undef lc
#undef rc
int m,il[25],ir[25];
int main()
{
	F(i,0,read(n))read(a[i]);
	build(1,0,n);
	read(m);
	while(m--)
	{
		int opt;read(opt);
		if(opt==0)
		{
			int x,v;read(x,v);a[--x]=v;
			update(1,0,n,x);
		}
		if(opt==1)
		{
			int l,r,k;long long ans=0;
			read(l,r,k);--l;
			F(i,0,k)
			{
				half res=query(1,0,n,l,r);
				if(res.ans>0)
				{
					ans+=res.ans;
					il[i]=l+res.al;
					ir[i]=l+res.ar;
					negate(1,0,n,il[i],ir[i]);
				}
				else{k=i;break;}
			}
			printf("%lld\n",ans);
			F(i,0,k)negate(1,0,n,il[i],ir[i]);
		}
	}
	return 0;
}