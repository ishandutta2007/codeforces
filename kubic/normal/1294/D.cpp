#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define mid ((l+r)>>1)
int n,m;struct Seg {int v,ps;}sg[N<<2];
void pu(int p)
{
	if(sg[p<<1].v<=sg[p<<1|1].v) sg[p]=sg[p<<1];
	else sg[p]=sg[p<<1|1];
}
void build(int p,int l,int r)
{
	if(l==r) {sg[p].ps=l;return;}
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int x)
{
	if(l==r) {++sg[p].v;return;}
	if(x<=mid) upd(p<<1,l,mid,x);
	else upd(p<<1|1,mid+1,r,x);pu(p);
}
int main()
{
	scanf("%d %d",&n,&m);build(1,0,m-1);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);upd(1,0,m-1,x%m);
		printf("%d\n",sg[1].v*m+sg[1].ps);
	}return 0;
}