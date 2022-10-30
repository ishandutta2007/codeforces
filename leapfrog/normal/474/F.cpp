//
//!
//
//
//!
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;
struct node{int min,mnn,gcd;}t[400005];
int n,q,a[100005];
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline node up(node a,node b)
{
	node r;r.min=min(a.min,b.min),r.gcd=gcd(a.gcd,b.gcd);
	r.mnn=(a.min==r.min?a.mnn:0)+(b.min==r.min?b.mnn:0);return r;
}
inline void build(int x,int l,int r)
{
	if(l==r) t[x].gcd=t[x].min=a[l],t[x].mnn=1;
	else build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x]=up(t[x<<1],t[x<<1|1]);
}
inline node query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return (node){(int)1e9,0,0};else if(dl<=l&&r<=dr) return t[x];
	return up(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(build(1,1,n),scanf("%d",&q);q--;)
	{
		int l,r;scanf("%d%d",&l,&r);
		node t=query(1,1,n,l,r);
		// printf("%d , %d : %d\n",t.gcd,t.min,t.mnn);
		printf("%d\n",r-l+1-(t.gcd==t.min?t.mnn:0));
	}
	return 0;
}