#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=2e5+5;
#define ls rt<<1
#define rs rt<<1|1
struct node
{
	int l,r,lazy;
}tr[maxn*4];
int a[maxn],b[maxn],c[maxn],n,m,x,y,z,k;
void push(int rt)
{
	if(tr[rt].lazy==1)
	{
		tr[ls].lazy=1,tr[rs].lazy=1;
		tr[ls].r=tr[rt].l+(tr[ls].r-tr[ls].l),tr[ls].l=tr[rt].l;
		tr[rs].l=tr[ls].r+1;tr[rs].r=tr[rt].r;
	}tr[rt].lazy=0;
}
void build(int rt,int l,int r)
{
	tr[rt].l=l,tr[rt].r=r;tr[rt].lazy=0;
	if(l==r)return;
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);
}
void change(int rt,int l,int r,int L,int R,int x)
{
	
	if(l>R||r<L)return;
	if(l>=L&&r<=R)
	{
		tr[rt].l=x+(l-L);tr[rt].r=x+(r-L);//cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<x<<endl;
		tr[rt].lazy=1;return;
	}
	push(rt);int mid=l+r>>1;
	change(ls,l,mid,L,R,x),change(rs,mid+1,r,L,R,x);
}
int query(int rt,int l,int r,int x)
{
	
	if(l>x||r<x)return 0;
	if(l==x&&r==x)
	{//cout<<l<<" "<<r<<" "<<tr[rt].l<<endl;
		if(tr[rt].lazy==1)return a[tr[rt].l];
		else return b[l];
	}
	push(rt);int mid=l+r>>1;
	return query(ls,l,mid,x)+query(rs,mid+1,r,x);
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		k=read();
		if(k==1)x=read(),y=read(),z=read(),change(1,1,n,y,y+z-1,x);
		else x=read(),printf("%d\n",query(1,1,n,x));
		
		//for(int j=1;j<=n;j++)printf("%d ",query(1,1,n,j));puts("");
	}
	return 0;
}