#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const int MOD=1000000007;
struct Seg
{
	int l,r;
	LL a[6];
	LL lazy;
}T[MAXN<<2];
int n,m,a[MAXN],Temp[MAXN][6];
char op[10];
int l,r,k;
LL C[6][6];
void PushDown(int x)
{
	int lc=x<<1,rc=x<<1|1;
	int ls=T[lc].r-T[lc].l+1,rs=T[rc].r-T[rc].l+1;
	T[lc].lazy=T[rc].lazy=T[x].lazy;
	for(int k=0;k<=5;k++)
		T[lc].a[k]=(Temp[ls][k]*T[x].lazy)%MOD,T[rc].a[k]=(Temp[rs][k]*T[x].lazy)%MOD;
	T[x].lazy=-1;
}
Seg Merge(const Seg &p,const Seg &q)
{
	Seg con;
	con.lazy=-1;
	con.l=p.l,con.r=q.r;
	LL ls[6]={1};
	ls[1]=p.r-p.l+1;
	for(int i=2;i<=5;i++) ls[i]=(ls[i-1]*ls[1])%MOD;
	for(int i=0;i<=5;i++)
	{
		con.a[i]=p.a[i];
		for(int j=0;j<=i;j++)
			con.a[i]=(con.a[i]+((C[i][j]*ls[j])%MOD)*q.a[i-j])%MOD;
	}
	return con;
}
void MakeTree(int x,int l,int r)
{
	T[x].lazy=-1;
	T[x].l=l,T[x].r=r;
	if(l==r)
	{
		for(int k=0;k<=5;k++)
			T[x].a[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	T[x]=Merge(T[x<<1],T[x<<1|1]);
}
void Change(int x,int l,int r,LL tar)
{
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].lazy=tar;
		for(int k=0;k<=5;k++)
			T[x].a[k]=(Temp[T[x].r-T[x].l+1][k]*tar)%MOD;
		return;
	}
	int mid=(T[x].l+T[x].r)>>1;
	if(T[x].lazy!=-1) PushDown(x);
	if(r<=mid) Change(x<<1,l,r,tar);
	else if(l>mid) Change(x<<1|1,l,r,tar);
	else Change(x<<1,l,mid,tar),Change(x<<1|1,mid+1,r,tar);
	T[x]=Merge(T[x<<1],T[x<<1|1]);
}
Seg Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x];
	int mid=(T[x].l+T[x].r)>>1;
	if(T[x].lazy!=-1) PushDown(x);
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Merge(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
}
int main()
{
	C[0][0]=1;
	C[1][0]=1,C[1][1]=1;
	C[2][0]=1,C[2][1]=2,C[2][2]=1;
	C[3][0]=1,C[3][1]=3,C[3][2]=3,C[3][3]=1;
	C[4][0]=1,C[4][1]=4,C[4][2]=6,C[4][3]=4,C[4][4]=1;
	C[5][0]=1,C[5][1]=5,C[5][2]=10,C[5][3]=10,C[5][4]=5,C[5][5]=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		LL x=1;
		for(int j=0;j<=5;j++)
			Temp[i][j]=(Temp[i-1][j]+x)%MOD,x=(x*i)%MOD;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	MakeTree(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d%d",op,&l,&r,&k);
		if(op[0]=='=') Change(1,l,r,(LL)k);
		else
		{
			Seg A=Query(1,l,r);
			printf("%I64d\n",A.a[k]);
		}
	}
	return 0;
}