#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
const int maxn=100000+100;
int n,m;
struct Node
{
	int l,r;
	ll sum,col,lazy;
	ll size()
	{
		return r-l+1;
	}
}	a[maxn<<2];
void build(int t,int l,int r)
{
	a[t].l=l;
	a[t].r=r;
	a[t].col=a[t].sum=a[t].lazy=0;
	if (a[t].l==a[t].r)
	{
		a[t].col=l;
		return;
	}
	int mid=(l+r)>>1;
	build(L(t),l,mid);
	build(R(t),mid+1,r);
	return;
}

void push_down(int t)
{
	if (a[t].l==a[t].r)	return;
	if (a[t].lazy)
	{
		a[L(t)].lazy+=a[t].lazy;
		a[R(t)].lazy+=a[t].lazy;
		a[L(t)].sum+=a[L(t)].size()*a[t].lazy;
		a[R(t)].sum+=a[R(t)].size()*a[t].lazy;
		a[t].lazy=0;
	}
	if (a[t].col)	a[L(t)].col=a[R(t)].col=a[t].col;
}

void update(int t,int l,int r,ll col)
{
	push_down(t);
	if (a[t].l==l && r==a[t].r && a[t].col)
	{
		a[t].sum+=a[t].size()*abs(a[t].col-col);
		a[t].lazy+=abs(a[t].col-col);
		a[t].col=col;
		return;
	}
	int mid=(a[t].l+a[t].r)>>1;
	if (l>mid)	update(R(t),l,r,col);else
	if (r<=mid)	update(L(t),l,r,col);else
	{
		update(L(t),l,mid,col);
		update(R(t),mid+1,r,col);
	}
	if	(a[L(t)].col==a[R(t)].col && a[L(t)].col)	a[t].col=a[L(t)].col;
	else	a[t].col=0;
	a[t].sum=a[L(t)].sum+a[R(t)].sum;
}
ll query(int t,int l,int r)
{
	push_down(t);
	if (l==a[t].l && r==a[t].r)	return a[t].sum;
	int mid=(a[t].l+a[t].r)>>1;
	if (l>mid)	return query(R(t),l,r);else
	if (r<=mid)	return query(L(t),l,r);else
	return query(L(t),l,mid)+query(R(t),mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while (m--)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		if (x==1)
		{
			ll q;
			scanf("%lld",&q);
			update(1,l,r,q);
		}	else
		printf("%lld\n",query(1,l,r));
	}
	return 0;
}