#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=1e5+5;
#define ls rt<<1
#define rs rt<<1|1
struct node
{
	int l,r,tag,c[22];
}tr[maxn*4];
int a[maxn],b[22],n,m,x,y,z,k,t;
void x2(int x)
{
	t=0;
	while(x)
	{
		b[++t]=x%2;x=x/2;
	}
}
void pushup(int rt)
{
	for(int i=1;i<=21;i++)
		tr[rt].c[i]=tr[ls].c[i]+tr[rs].c[i];
}
void push(int rt)
{
	tr[rs].tag=tr[rt].tag^tr[rs].tag;tr[ls].tag=tr[ls].tag^tr[rt].tag;
	x2(tr[rt].tag);
	for(int i=1;i<=t;i++)
		if(b[i])tr[ls].c[i]=(tr[ls].r-tr[ls].l+1)-tr[ls].c[i];
	x2(tr[rt].tag);
	for(int i=1;i<=t;i++)
		if(b[i])tr[rs].c[i]=(tr[rs].r-tr[rs].l+1)-tr[rs].c[i];//,cout<<tr[rs].tag;
	tr[rt].tag=0;
	
}
void build(int rt,int l,int r)
{
	tr[rt].l=l,tr[rt].r=r;tr[rt].tag=0;
	if(l==r)
	{
		x2(a[l]);
		for(int i=1;i<=t;i++)tr[rt].c[i]=b[i];
		return;
	}
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);pushup(rt);
}
void change(int rt,int l,int r,int L,int R,int x)
{
	
	if(l>R||r<L)return;
	if(l>=L&&r<=R)
	{
		x2(x);
		for(int i=1;i<=t;i++)
			if(b[i])
				tr[rt].c[i]=(tr[rt].r-tr[rt].l+1)-tr[rt].c[i];//,cout<<tr[rt].c[i]<<endl;
		tr[rt].tag=tr[rt].tag^x;//cout<<tr[rt].tag;
		return;
	}
	push(rt);int mid=l+r>>1;
	change(ls,l,mid,L,R,x),change(rs,mid+1,r,L,R,x);pushup(rt);
}
int query(int rt,int l,int r,int x,int y)
{
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)
	{
		int p=1,res=0;
		for(int i=1;i<=21;i++)
			res+=p*tr[rt].c[i],p=p*2;
		return res;
	}
	push(rt);int mid=l+r>>1;
	return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	build(1,1,n);m=read();
	for(int i=1;i<=m;i++)
	{
		k=read();
		if(k==1)
		{
			x=read(),y=read();
			printf("%lld\n",query(1,1,n,x,y));
		}
		else 
		{
			x=read(),y=read(),z=read();
			change(1,1,n,x,y,z);
		}
	}
	return 0;
}