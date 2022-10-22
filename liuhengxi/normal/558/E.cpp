#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct node
{
	int cnt[26];
	node(){}
	node(int sum)
	{
		int *p1=cnt;
		*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;
		*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;
		*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;
		*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;*p1=0;++p1;
		*p1=0;++p1;*p1=0;++p1;
		cnt[sum]=1;
	}
	node operator+(node b)const
	{
		node c;const int *p1=cnt,*p2=b.cnt;int *p3=c.cnt;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		*p3=*p1+*p2;++p1,++p2,++p3;*p3=*p1+*p2;++p1,++p2,++p3;
		return c;
	}
	node operator*(int b)const
	{
		node c;const int *p1=cnt;int *p2=c.cnt;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		*p2=b**p1;++p1,++p2;*p2=b**p1;++p1,++p2;
		return c;
	}
};
int n,q;
char s[N];
struct segtree
{
	#define lc (p<<1)
	#define rc ((p<<1)|1)
	node sum[N<<2],tag[N<<2];bool hastag[N<<2];
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return sum[p]=node(s[l]-'a'),void();
		build(lc,l,mid);build(rc,mid,r);
		sum[p]=sum[lc]+sum[rc];
	}
	node query(int p,int l,int r,int x,int y)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x)
		{
			node tmp(0);
			tmp.cnt[0]=0;
			return tmp;
		}
		if(x<=l&&r<=y)return sum[p];
		if(hastag[p])
		{
			tag[lc]=tag[rc]=tag[p];
			sum[lc]=tag[p]*(mid-l);
			sum[rc]=tag[p]*(r-mid);
			hastag[lc]=hastag[rc]=true;
			hastag[p]=false;
		}
		return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
	}
	void assign(int p,int l,int r,int x,int y,const node &v)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x)return;
		if(x<=l&&r<=y)return hastag[p]=true,sum[p]=(tag[p]=v)*(r-l),void();
		if(hastag[p])
		{
			tag[lc]=tag[rc]=tag[p];
			sum[lc]=tag[p]*(mid-l);
			sum[rc]=tag[p]*(r-mid);
			hastag[lc]=hastag[rc]=true;
			hastag[p]=false;
		}
		assign(lc,l,mid,x,y,v);assign(rc,mid,r,x,y,v);
		sum[p]=sum[lc]+sum[rc];
	}
	void dfs(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		if(r-l==1)
		{
			F(i,0,26)if(sum[p].cnt[i])s[l]='a'+i;
			return;
		}
		if(hastag[p])
		{
			tag[lc]=tag[rc]=tag[p];
			sum[lc]=tag[p]*(mid-l);
			sum[rc]=tag[p]*(r-mid);
			hastag[lc]=hastag[rc]=true;
			hastag[p]=false;
		}
		dfs(lc,l,mid);dfs(rc,mid,r);
	}
	#undef lc
	#undef rc
}a;
int main()
{
	read(n);read(q);
	scanf("%s",s);
	a.build(1,0,n);
	while(q--)
	{
		int l,r,k;node res;
		read(l);read(r);read(k);--l;
		res=a.query(1,0,n,l,r);
		if(k==1)
		{
			int pos=l;
			F(i,0,26)
			{
				a.assign(1,0,n,pos,pos+res.cnt[i],node(i));
				pos+=res.cnt[i];
			}
		}
		else
		{
			int pos=l;
			for(int i=25;~i;--i)
			{
				a.assign(1,0,n,pos,pos+res.cnt[i],node(i));
				pos+=res.cnt[i];
			}
		}
	}
	a.dfs(1,0,n);
	puts(s);
	return 0;
}