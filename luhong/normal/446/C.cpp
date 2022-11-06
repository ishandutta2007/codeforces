#include<iostream>
#include<cstdio>
#define mod 1000000009
using namespace std;
int l1[1201000],l2[1200000],sum[1200000],l[1200000],r[1200000];
int F[301000],val[301000];
void rw(int &a,int b){a=(a+b)%mod;}
int fib(int x,int a,int b){if(x==1)return a;return (1ll*a*F[x-2]+1ll*b*F[x-1])%mod;}
void add(int x,int a,int b)
{
	rw(l1[x],a);rw(l2[x],b);
	rw(sum[x],(fib(r[x]-l[x]+1+2,a,b)-b+mod)%mod);
}
void pushdown(int x)
{
	if(l1[x]||l2[x])add(x<<1,l1[x],l2[x]),add(x<<1|1,fib(r[x<<1]-l[x<<1]+1+1,l1[x],l2[x]),fib(r[x<<1]-l[x<<1]+1+2,l1[x],l2[x])),l1[x]=l2[x]=0;
}
void build(int x,int L,int R)
{
	l[x]=L;r[x]=R;if(L==R){sum[x]=val[L];return;}
	build(x<<1,L,L+R>>1);build(x<<1|1,(L+R>>1)+1,R);
	sum[x]=(sum[x<<1]+sum[x<<1|1])%mod;
}
void modify(int x,int L,int R,int a,int b)
{
	if(l[x]==L&&r[x]==R){add(x,a,b);return;}
	pushdown(x);int mid=l[x]+r[x]>>1;
	if(R<=mid)modify(x<<1,L,R,a,b);
	else if(L>mid)modify(x<<1|1,L,R,a,b);
	else modify(x<<1,L,mid,a,b),modify(x<<1|1,mid+1,R,fib(mid-L+1+1,a,b),fib(mid-L+1+2,a,b));
	sum[x]=(sum[x<<1]+sum[x<<1|1])%mod;
}
int query(int x,int L,int R)
{
	if(l[x]==L&&r[x]==R)return sum[x];
	pushdown(x);int mid=l[x]+r[x]>>1;
	if(R<=mid)return query(x<<1,L,R);
	else if(L>mid)return query(x<<1|1,L,R);
	else return (query(x<<1,L,mid)+query(x<<1|1,mid+1,R))%mod;
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	build(1,1,n);
	F[1]=F[2]=1;for(int i=3;i<=n+10;i++)F[i]=(F[i-1]+F[i-2])%mod;
	for(int i=1;i<=m;i++)
	{
		int k,L,R;scanf("%d%d%d",&k,&L,&R);
		if(k==1)modify(1,L,R,1,1);
		else printf("%d\n",query(1,L,R));
	}
	return 0;
}
/* 
fib
a,ba,b
1 0
0 1
1 1
1 2
2 3
3 5
5 8
a=b=1fibF 
fib[i]=a*F[i-2]+b*F[i-1]

fib[i]=fib[i-1]+fib[i-2]
fib[i-1]=fib[i-2]+fib[i-3]
fib[i-2]=fib[i-3]+fib[i-4]
...
fib[4]=fib[3]+fib[2]
fib[3]=fib[2]+fib[1]

 
fib[i]=fib[j](j<=i-2) +fib[2]
fib[i]=fib[i+2]-fib[2] 
*/