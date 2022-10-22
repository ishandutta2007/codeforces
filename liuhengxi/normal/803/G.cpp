#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=19,M=1.5e7+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,logn,k,b[N][LogN],lg2[N],m,ls[M],rs[M],mn[M],cnt,q,tg[M];
inline int queryst(int l,int r){return l==r?INF:min(b[l][lg2[r-l]],b[r-(1<<lg2[r-l])][lg2[r-l]]);}
inline int query(int l,int r)
{
	if(r-l>=n)return queryst(0,n);
	r-=l/n*n;l-=l/n*n;
	return min(queryst(l,min(n,r)),queryst(0,max(0,r-n)));
}
inline void assign(int p,int x){mn[p]=tg[p]=x;}
inline int create(int l,int r)
{
	tg[++cnt]=-1;
	mn[cnt]=query(l,r);
	return cnt;
}
void pushdown(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(!ls[p])ls[p]=create(l,mid);
	if(!rs[p])rs[p]=create(mid,r);
	if(~tg[p])
	{
		assign(ls[p],tg[p]);
		assign(rs[p],tg[p]);
		tg[p]=-1;
	}
}
void assign(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return assign(p,v);
	pushdown(p,l,r);
	assign(ls[p],l,mid,x,y,v);
	assign(rs[p],mid,r,x,y,v);
	mn[p]=min(mn[ls[p]],mn[rs[p]]);
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return INF;
	if(x<=l&&r<=y)return mn[p];
	pushdown(p,l,r);
	return min(query(ls[p],l,mid,x,y),query(rs[p],mid,r,x,y));
}
int main()
{
	read(n);read(k);m=n*k;
	F(i,1,n+1)lg2[i]=1<<(lg2[i-1]+1)<=i?lg2[i-1]+1:lg2[i-1];
	logn=lg2[n];
	F(i,0,n)read(b[i][0]);
	F(i,0,logn)
	{
		int half=1<<i;
		F(j,0,n-(half<<1)+1)b[j][i+1]=min(b[j][i],b[j+half][i]);
	}
	mn[++cnt]=query(0,m);
	tg[cnt]=-1;
	read(q);
	while(q--)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int l,r,x;read(l);read(r);read(x);--l;
			assign(1,0,m,l,r,x);
		}
		if(opt==2)
		{
			int l,r;read(l);read(r);--l;
			printf("%d\n",query(1,0,m,l,r));
		}
	}
	return 0;
}