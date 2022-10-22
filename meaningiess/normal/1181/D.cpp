#include<bits/stdc++.h>
#define ll long long
#define N 500010
#define mid ((l+r)>>1)
#define ls a[t].l
#define rs a[t].r
using namespace std;
struct dat
{
	int a,b;
	bool operator<(const dat&x) const{return (b==x.b)?a<x.a:b<x.b;}
}d[N];ll ans[N];int l[N],r[N],rt[N];
bool cmp(dat x,dat y){return x.a<y.a;}
struct ksegt
{
	struct fck{int c,l,r;}a[N*60];int tot;
	void bil(int &t,int k){a[t=++tot]=a[k];}
	void upd(int t,int l,int r,int x,int k)
	{
		if (l==r){a[t].c+=k;return;}if (x<=mid) {bil(ls,ls);upd(ls,l,mid,x,k);}
		else {bil(rs,rs);upd(rs,mid+1,r,x,k);}a[t].c=a[ls].c+a[rs].c;
	}
	int qry(int t,int l,int r,int k)
	{
		while (l<r){if (a[ls].c>=k) t=ls,r=mid;else l=mid+1,k-=a[ls].c,t=rs;}return r;
	}
}sgt;
int main()
{
	int n,m,q,i,lst=1,tp=0;ll t;cin>>n>>m>>q;
	for (i=1;i<=n;i++) scanf("%lld",&t),d[t].b++;
	for (i=1;i<=m;i++) d[i].a=i;sort(d+1,d+m+1);
	sgt.bil(rt[1],rt[0]);sgt.upd(rt[1],1,m,d[1].a,1);
	for (i=2;i<=m+1;i++)
	{
		if (d[i].b!=d[i-1].b)
		{
			ans[++tp]=ans[tp-1]+(1ll*d[i].b-d[i-1].b)*(i-1);
			l[tp]=lst;r[tp]=i-1;
			lst=i;
		}
		if (i<=m) sgt.bil(rt[i],rt[i-1]),sgt.upd(rt[i],1,m,d[i].a,1);
	}
	ans[tp]=1e18+1;l[tp]=1;r[tp]=m;
	while (q--)
	{
		scanf("%lld",&t);t-=n;
		int p=lower_bound(ans+1,ans+tp+1,t)-ans;t-=ans[p-1];
		printf("%d\n",sgt.qry(rt[r[p]],1,m,(r[p]-1+t)%r[p]+1));
	}
}