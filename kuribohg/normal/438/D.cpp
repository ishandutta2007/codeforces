#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
typedef long long LL;
typedef pair<long long,long long> PLL;
const int MAXN=100010;
int n,m,l[MAXN<<2],r[MAXN<<2],op,in1,in2,in3;
LL dat[MAXN];
PLL tree[MAXN<<2];
PLL operator+(const PLL &a,const PLL &b)
{return make_pair(a.first+b.first,max(a.second,b.second));}
void maketree(int x,int ll,int rr)
{
	l[x]=ll,r[x]=rr;
	if(ll==rr) {tree[x]=make_pair(dat[ll],dat[ll]);return;}
	int m=(l[x]+r[x])>>1;
	maketree(x<<1,ll,m);
	maketree(x<<1|1,m+1,rr);
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
void change(int x,int pos,LL tar)
{
	if(l[x]==r[x]) {tree[x]=make_pair(tar,tar);return;}
	int m=(l[x]+r[x])>>1;
	if(pos<=m) change(x<<1,pos,tar);
	else change(x<<1|1,pos,tar);
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
LL query(int x,int ll,int rr)
{
	if(l[x]==ll&&r[x]==rr) return tree[x].first;
	int m=(l[x]+r[x])>>1;
	if(rr<=m) return query(x<<1,ll,rr);
	else if(ll>m) return query(x<<1|1,ll,rr);
	else return query(x<<1,ll,m)+query(x<<1|1,m+1,rr);
}
void opmod(int x,int ll,int rr,LL tar)
{
	if(tree[x].second<tar) return;
	if(l[x]==r[x]) {tree[x]=make_pair(tree[x].first%tar,tree[x].first%tar);return;}
	int m=(l[x]+r[x])>>1;
	if(rr<=m) opmod(x<<1,ll,rr,tar);
	else if(ll>m) opmod(x<<1|1,ll,rr,tar);
	else {opmod(x<<1,ll,m,tar);opmod(x<<1|1,m+1,rr,tar);}
	tree[x]=tree[x<<1]+tree[x<<1|1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&dat[i]);
	maketree(1,1,n);
	for(int cas=1;cas<=m;cas++)
	{
		scanf("%d%d%d",&op,&in1,&in2);
		if(op==2) scanf("%d",&in3);
		if(op==1) printf("%I64d\n",query(1,in1,in2));
		else if(op==2) opmod(1,in1,in2,(LL)in3);
		else change(1,in1,(LL)in2);
	}
	return 0;
}