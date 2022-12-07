#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
struct Functional_Seg_Tree
{
	int l,r;
	int lch,rch;
	int size;
}T[MAXN*100];
int root[MAXN],tot;
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
	if(T[x].l==T[x].r) return o;
	int mid=(T[x].l+T[x].r)>>1;
	if(tar<=mid) T[o].lch=Change(T[x].lch,tar);
	else T[o].rch=Change(T[x].rch,tar);
	return o;
}
int Query(int x,int y,int tar)
{
	if(T[x].l==T[x].r) return 0;
	int mid=(T[x].l+T[x].r)>>1;
	if(tar<=mid) return Query(T[x].lch,T[y].lch,tar);
	else return T[T[y].lch].size-T[T[x].lch].size+Query(T[x].rch,T[y].rch,tar);
}
int n,a[MAXN],b[MAXN],tot_c,ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	tot_c=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+tot_c+1,a[i])-b;
	root[0]=MakeTree(1,tot_c);
	for(int i=1;i<=n;i++) root[i]=Change(root[i-1],a[i]);
	for(int k=1;k<n;k++)
		for(int i=1;i<=n;i++)
		{
			if(k*(i-1)+2>n) break;
			int L=k*(i-1)+2,R=min(n,k*i+1);
			ans[k]+=Query(root[L-1],root[R],a[i]);
		}
	for(int i=1;i<n;i++) printf("%d ",ans[i]);
	return 0;
}