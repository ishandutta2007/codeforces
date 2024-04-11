#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,ans,tp,tp1,a[N],b[N],vl[N],st[N];
ll ds[N],pr[N],sf[N],pr1[N],sf1[N],pr2[N],sf2[N];
struct Node {int id;ll x,y,z;}z[N],z1[N];
ll max(ll x,ll y) {return x>y?x:y;}
bool cmp(Node x,Node y)
{
	if(x.x!=y.x) return x.x<y.x;if(x.y!=y.y) return x.y<y.y;
	if(x.z!=y.z) return x.z<y.z;return x.id<y.id;
}
void upd(int x,int w)
{
	if(w) st[++st[0]]=x;
	for(;x<=ds[0];x+=x&-x) vl[x]=w?max(vl[x],w):0;
}
int qMx(int x)
{int res=0;for(;x;x-=x&-x) res=max(res,vl[x]);return res;}
void slv1(int l,int r)
{
	if(l==r) return;int mid=(l+r)/2,t=l;
	slv1(l,mid);slv1(mid+1,r);tp1=0;
	for(int i=mid+1;i<=r;++i)
	{
		while(t<=mid && z[t].y<=z[i].y)
		{if(z[t].id<0) upd(z[t].z,n+z[t].id+1);z1[++tp1]=z[t++];}
		if(z[i].id>0) ans=max(ans,z[i].id+qMx(z[i].z)-n);
		z1[++tp1]=z[i];
	}while(t<=mid) z1[++tp1]=z[t++];
	while(st[0]) upd(st[st[0]--],0);
	for(int i=l;i<=r;++i) z[i]=z1[i-l+1];
}
void slv(int l,int r)
{
	if(l==r) return;int mid=(l+r)/2;
	ll nw,pr,pr1,pr2,sf,sf1,sf2;slv(l,mid);slv(mid+1,r);
	nw=pr=pr1=sf=sf1=b[mid];pr2=sf2=tp=ds[0]=0;
	for(int i=mid+1;i<=r;++i)
	{
		pr+=a[i]-b[i-1];pr1=max(pr1,pr);
		pr2=max(max(pr2,nw+a[i]-b[i-1]),b[i-1]);
		nw=max(nw+a[i]-b[i-1],b[i]);
		z[++tp]=(Node) {i,pr,pr-pr1,pr-pr2};ds[++ds[0]]=z[tp].z;
	}nw=b[mid];
	for(int i=mid;i>=l;--i)
	{
		sf+=a[i]-b[i];sf1=max(sf1,sf);
		sf2=max(max(sf2,nw+a[i]-b[i]),b[i]);
		nw=max(nw+a[i]-b[i],b[i-1]);
		z[++tp]=(Node) {-i,b[mid]-m-sf+sf2,-m-sf+sf1,b[mid]-m-sf};
		ds[++ds[0]]=z[tp].z;
	}sort(ds+1,ds+ds[0]+1);sort(z+1,z+tp+1,cmp);
	ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=tp;++i)
		z[i].z=lower_bound(ds+1,ds+ds[0]+1,z[i].z)-ds;slv1(1,tp);
}
int main()
{
	scanf("%d %d",&n,&m);ans=1;
	for(int i=1;i<n;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	slv(1,n);printf("%d\n",ans);return 0;
}