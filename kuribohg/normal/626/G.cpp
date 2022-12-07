#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
const double INF=1e20;
int n,t,q,l[MAXN],p[MAXN],a[MAXN];
double add[MAXN],sub[MAXN],ans;
struct Seg
{
	int l,r;
	int Max,Min;
}T[MAXN<<2];
void update(int x)
{
	if(a[x]>=l[x]) add[x]=0;
	else add[x]=p[x]*((a[x]+1)*1.0/(a[x]+l[x]+1)-a[x]*1.0/(a[x]+l[x]));
	if(a[x]>l[x]) sub[x]=0;
	else if(a[x]) sub[x]=p[x]*(a[x]*1.0/(a[x]+l[x])-(a[x]-1)*1.0/(a[x]+l[x]-1));
	else sub[x]=INF;
}
void maintain(int x)
{
	if(add[T[x<<1].Max]>add[T[x<<1|1].Max]) T[x].Max=T[x<<1].Max;
	else T[x].Max=T[x<<1|1].Max;
	if(sub[T[x<<1].Min]<sub[T[x<<1|1].Min]) T[x].Min=T[x<<1].Min;
	else T[x].Min=T[x<<1|1].Min;
}
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r) {T[x].Max=T[x].Min=l;return;}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	maintain(x);
}
void Modify(int x,int pos)
{
	if(T[x].l==T[x].r) return;
	int mid=(T[x].l+T[x].r)>>1;
	if(pos<=mid) Modify(x<<1,pos);
	else Modify(x<<1|1,pos);
	maintain(x);
}
int main()
{
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	for(int i=1;i<=n;i++) update(i);
	MakeTree(1,1,n);
	for(int i=1;i<=t;i++)
	{
		int x=T[1].Max;
		ans+=add[x];
		a[x]++,update(x);
		Modify(1,x);
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ans-=p[y]*min(0.5,a[y]*1.0/(l[y]+a[y]));
		if(x==1) l[y]++;
		else l[y]--;
		ans+=p[y]*min(0.5,a[y]*1.0/(l[y]+a[y]));
		update(y);
		Modify(1,y);
		int xx=T[1].Max,yy=T[1].Min;
		if(add[xx]-sub[yy]>0)
		{
			ans+=add[xx]-sub[yy];
			a[xx]++,a[yy]--;
			update(xx),update(yy);
			Modify(1,xx),Modify(1,yy);
		}
		printf("%.010lf\n",ans);
	}
	return 0;
}