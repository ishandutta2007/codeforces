#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,Q,p[MAXN],q[MAXN],pos[MAXN];
int l1,r1,l2,r2,lastans=-1;
void Decode()
{
	int x=lastans+1;
	l1=(l1-1+x)%n+1;
	r1=(r1-1+x)%n+1;
	l2=(l2-1+x)%n+1;
	r2=(r2-1+x)%n+1;
	if(l1>r1) swap(l1,r1);
	if(l2>r2) swap(l2,r2);
}
struct Functional_Seg_Tree
{
	int lch,rch;
	int l,r;
	int size;
}T[MAXN*23];
int tot,root[MAXN];
int MakeTree(int l,int r)
{
	int o=++tot;
	T[o].l=l,T[o].r=r;
	if(l==r) return o;
	int mid=(l+r)>>1;
	T[o].lch=MakeTree(l,mid);
	T[o].rch=MakeTree(mid+1,r);
	return o;
}
int Change(int x,int tar)
{
	int o=++tot;
	T[o]=T[x],T[o].size++;
	if(T[o].l==T[o].r) return o;
	int mid=(T[o].l+T[o].r)>>1;
	if(tar<=mid) T[o].lch=Change(T[x].lch,tar);
	else T[o].rch=Change(T[x].rch,tar);
	return o;
}
int Query(int x,int tar)
{
	if(T[x].l==T[x].r) return T[x].size;
	int mid=(T[x].l+T[x].r)>>1;
	if(tar<=mid) return Query(T[x].lch,tar);
	else return T[T[x].lch].size+Query(T[x].rch,tar);
}
int Solve(int l,int r)
{
	if(l==0||r==0) return 0;
	return Query(root[l],r);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=1;i<=n;i++) pos[q[i]]=i;
	for(int i=1;i<=n;i++) p[i]=pos[p[i]];
	root[0]=MakeTree(1,n);
	for(int i=1;i<=n;i++) root[i]=Change(root[i-1],p[i]);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		Decode();
		lastans=Solve(r1,r2)-Solve(l1-1,r2)-Solve(r1,l2-1)+Solve(l1-1,l2-1);
		printf("%d\n",lastans);
	}
	return 0;
}