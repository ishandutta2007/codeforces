#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define mid ((l+r)>>1)
using namespace std;
struct node
{
	int x,y;
}a[N],b[N],c[N];
bool cmpx(node a,node b){return a.y==b.y?a.x<b.x:a.y>b.y;}
set<int> S;
struct segt
{
	struct dat{int c,l,r;}a[N*50];int tot=1;void bil(int &t){if (!t) t=++tot;}
	void upd(int t,int l,int r,int x)
	{
		if (l==r) {a[t].c=1;return;}bil(a[t].l);bil(a[t].r);
		if (x<=mid) upd(a[t].l,l,mid,x);else upd(a[t].r,mid+1,r,x);a[t].c=a[a[t].l].c+a[a[t].r].c;
	}
	int qry(int t,int l,int r,int x)
	{
		if (x==0) return 0;int res=0;
		while (l<r){if (x<=mid) bil(a[t].l),r=mid,t=a[t].l;else res+=a[a[t].l].c,bil(a[t].r),l=mid+1,t=a[t].r;}return res+a[t].c;
	}
}sgt;
int main()
{
	int n,lst=1,i,j;ll ans=0;cin>>n;
	for (i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmpx);
	for (i=2;i<=n+1;i++) if (a[i].y!=a[i-1].y)
	{
		for (j=lst+1;j<i;j++)
		{
			sgt.upd(1,1,1e9,a[j-1].x);ll t=sgt.qry(1,1,1e9,a[j].x-1)-sgt.qry(1,1,1e9,a[j-1].x-1);
			ans+=t*sgt.qry(1,1,1e9,a[j-1].x);//cout<<t<<' '<<a[j-1].x<<' '<<ans<<endl;
		}
			sgt.upd(1,1,1e9,a[j-1].x);ll t=sgt.qry(1,1,1e9,1e9)-sgt.qry(1,1,1e9,a[j-1].x-1);
			ans+=t*sgt.qry(1,1,1e9,a[j-1].x);//cout<<t<<' '<<a[j-1].x<<' '<<ans<<endl<<endl;
		lst=i;
	}
	cout<<ans;
}