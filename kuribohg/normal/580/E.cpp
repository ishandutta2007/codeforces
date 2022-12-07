#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const LL MOD1=998244353;
const LL MOD2=1000000007;
const LL p1=97;
const LL p2=101;
int n,m,k,Q;
char str[MAXN];
LL Pow[2][MAXN],sPow[2][MAXN];
struct Seg
{
	int l,r;
	LL Hash[2],lazy;
}T[MAXN<<2];
void PushUp(int x)
{
	int sz=T[x<<1|1].r-T[x<<1|1].l+1;
	T[x].Hash[0]=(T[x<<1].Hash[0]*Pow[0][sz]+T[x<<1|1].Hash[0])%MOD1;
	T[x].Hash[1]=(T[x<<1].Hash[1]*Pow[1][sz]+T[x<<1|1].Hash[1])%MOD2;
}
void PushDown(int x)
{
	if(T[x].lazy!=-1)
	{
		int lc=x<<1,rc=lc|1,ls=T[lc].r-T[lc].l+1,rs=T[rc].r-T[rc].l+1;
		T[lc].lazy=T[x].lazy;
		T[rc].lazy=T[x].lazy;
		T[lc].Hash[0]=(T[x].lazy*sPow[0][ls-1])%MOD1;
		T[lc].Hash[1]=(T[x].lazy*sPow[1][ls-1])%MOD2;
		T[rc].Hash[0]=(T[x].lazy*sPow[0][rs-1])%MOD1;
		T[rc].Hash[1]=(T[x].lazy*sPow[1][rs-1])%MOD2;
		T[x].lazy=-1;
	}
}
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r,T[x].lazy=-1;
	if(l==r)
	{
		T[x].Hash[0]=T[x].Hash[1]=str[l]-'0';
		return;
	}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	PushUp(x);
}
void Change(int x,int l,int r,int d)
{
	if(T[x].l==l&&T[x].r==r)
	{
		T[x].lazy=d;
		int sz=T[x].r-T[x].l+1;
		T[x].Hash[0]=(T[x].lazy*sPow[0][sz-1])%MOD1;
		T[x].Hash[1]=(T[x].lazy*sPow[1][sz-1])%MOD2;
		return;
	}
	PushDown(x);
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) Change(x<<1,l,r,d);
	else if(l>mid) Change(x<<1|1,l,r,d);
	else Change(x<<1,l,mid,d),Change(x<<1|1,mid+1,r,d);
	PushUp(x);
}
pair<LL,LL> Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return make_pair(T[x].Hash[0],T[x].Hash[1]);
	PushDown(x);
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else
	{
		pair<LL,LL> L=Query(x<<1,l,mid);
		pair<LL,LL> R=Query(x<<1|1,mid+1,r);
		int sz=r-mid;
		pair<LL,LL> res;
		res.first=(L.first*Pow[0][sz]+R.first)%MOD1;
		res.second=(L.second*Pow[1][sz]+R.second)%MOD2;
		return res;
	}
}
int main()
{
	Pow[0][0]=Pow[1][0]=1;
	for(int i=1;i<=100000;i++) Pow[0][i]=(Pow[0][i-1]*p1)%MOD1,Pow[1][i]=(Pow[1][i-1]*p2)%MOD2;
	sPow[0][0]=sPow[1][0]=1;
	for(int i=1;i<=100000;i++) sPow[0][i]=(sPow[0][i-1]+Pow[0][i])%MOD1,sPow[1][i]=(sPow[1][i-1]+Pow[1][i])%MOD2;
	scanf("%d%d%d%s",&n,&m,&k,str+1),Q=m+k;
	MakeTree(1,1,n);
	while(Q--)
	{
		int op,l,r,d;
		scanf("%d%d%d%d",&op,&l,&r,&d);
		if(op==1) Change(1,l,r,d);
		else
		{
			if(d==r-l+1) {puts("YES");continue;}
			int Len=r-l+1-d;
			pair<LL,LL> x=Query(1,l,l+Len-1);
			pair<LL,LL> y=Query(1,r-Len+1,r);
			if(x==y) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}