#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ls[p]
#define rc rs[p]
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
	int type,left,right,max;
	node(){}
	node(int a){type=a?-1:0;left=right=max=a;}
	node operator+(node b)
	{
		node c;
		c.type=type&b.type;
		c.left=left+(type&b.left);
		c.right=b.right+(b.type&right);
		c.max=std::max(std::max(max,b.max),right+b.left);
		return c;
	}
}val[N<<5];
int n,a[N],m,id[N],ver[N],ind,ls[N<<5],rs[N<<5];
bool cmp(int u,int v){return a[u]<a[v];}
int build(int l,int r)
{
	int mid=(l+r)>>1,p=ind++;
	if(r-l==1)return val[p]=node(1),p;
	lc=build(l,mid);rc=build(mid,r);
	val[p]=val[lc]+val[rc];
	return p;
}
int update(int q,int l,int r,int x)
{
	int mid=(l+r)>>1,p=ind++;
	if(r-l==1)return val[p]=node(0),p;
	lc=ls[q];rc=rs[q];
	if(x<mid)lc=update(lc,l,mid,x);
	else rc=update(rc,mid,r,x);
	val[p]=val[lc]+val[rc];
	return p;
}
node query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return node(0);
	if(x<=l&&r<=y)return val[p];
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int solve(int x,int y,int k)
{
	int l=0,r=n,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(query(ver[mid],0,n,x,y).max>=k)l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),id[i]=i;
	std::sort(id,id+n,cmp);
	ver[0]=build(0,n);
	F(i,0,n)ver[i+1]=update(ver[i],0,n,id[i]);
	read(m);
	F(i,0,m)
	{
		int l,r,w;
		read(l);read(r);read(w);
		printf("%d\n",a[id[solve(--l,r,w)]]);
	}
	return 0;
}