#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=300020;
const int MOD=1000000009;
int n,m;
LL a[MAXN],fib[MAXN],k1[MAXN],k2[MAXN],sk1[MAXN],sk2[MAXN];
struct Seg
{
	int l,r;
	LL sum,x1,x2;
}T[MAXN<<2];
void PushDown(int x)
{
	if(T[x].x1==0&&T[x].x2==0) return;
	int lc=x<<1,rc=x<<1|1;
	LL ls=T[lc].r-T[lc].l+1,rs=T[rc].r-T[rc].l+1,X1,X2;
	T[lc].sum=(T[lc].sum+sk1[ls]*T[x].x1+sk2[ls]*T[x].x2)%MOD;
	T[lc].x1=(T[lc].x1+T[x].x1)%MOD;
	T[lc].x2=(T[lc].x2+T[x].x2)%MOD;
	X1=(k1[ls+1]*T[x].x1+k2[ls+1]*T[x].x2)%MOD;
	X2=(k1[ls+2]*T[x].x1+k2[ls+2]*T[x].x2)%MOD;
	T[rc].sum=(T[rc].sum+sk1[rs]*X1+sk2[rs]*X2)%MOD;
	T[rc].x1=(T[rc].x1+X1)%MOD;
	T[rc].x2=(T[rc].x2+X2)%MOD;
	T[x].x1=T[x].x2=0;
}
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r) {T[x].sum=a[l];return;}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	T[x].sum=(T[x<<1].sum+T[x<<1|1].sum)%MOD;
}
void Change(int x,int l,int r,LL x1,LL x2)
{
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].x1=(T[x].x1+x1)%MOD;
		T[x].x2=(T[x].x2+x2)%MOD;
		T[x].sum=(T[x].sum+sk1[r-l+1]*x1+sk2[r-l+1]*x2)%MOD;
		return;
	}
	PushDown(x);
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) Change(x<<1,l,r,x1,x2);
	else if(l>mid) Change(x<<1|1,l,r,x1,x2);
	else
	{
		Change(x<<1,l,mid,x1,x2);
		LL X1=(k1[mid-l+2]*x1+k2[mid-l+2]*x2)%MOD;
		LL X2=(k1[mid-l+3]*x1+k2[mid-l+3]*x2)%MOD;
		Change(x<<1|1,mid+1,r,X1,X2);
	}
	T[x].sum=(T[x<<1].sum+T[x<<1|1].sum)%MOD;
}
LL Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].sum;
	PushDown(x);
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return (Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r))%MOD;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	fib[1]=1,fib[2]=1;
	for(int i=3;i<=n+10;i++) fib[i]=(fib[i-1]+fib[i-2])%MOD;
	k1[1]=1,k1[2]=0,k2[1]=0,k2[2]=1;
	for(int i=3;i<=n+10;i++) k1[i]=(k1[i-1]+k1[i-2])%MOD,k2[i]=(k2[i-1]+k2[i-2])%MOD;
	for(int i=1;i<=n+10;i++) sk1[i]=(sk1[i-1]+k1[i])%MOD,sk2[i]=(sk2[i-1]+k2[i])%MOD;
	MakeTree(1,1,n);
	while(m--)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1) Change(1,l,r,1,1);
		else printf("%I64d\n",Query(1,l,r));
	}
	return 0;
}