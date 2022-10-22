#include<bits/stdc++.h>
#define ll long long
#define N 1000005
using namespace std;
struct segt
{
	int a[N<<2],tg[N<<2];
	void bil(int x,int l,int r)
	{
		a[x]=l;tg[x]=0;if (l==r) {return;}int mid=(l+r)>>1;bil(x<<1,l,mid);bil(x<<1|1,mid+1,r);
	}
	void psd(int x)
	{
		if (!tg[x]) return;
		tg[x<<1]+=tg[x];tg[x<<1|1]+=tg[x];a[x<<1]+=tg[x];a[x<<1|1]+=tg[x];tg[x]=0;
	}
	void upd(int x,int l,int r,int p,int q,int c)
	{
		if (p<=l && r<=q) {a[x]+=c;tg[x]+=c;return;}int mid=(l+r)>>1;psd(x);
		if (p<=mid) upd(x<<1,l,mid,p,q,c);if (q>mid) upd(x<<1|1,mid+1,r,p,q,c);
		a[x]=min(a[x<<1],a[x<<1|1]);
	}
}sgt;
int a[N],b[N],c[N],d[N];ll ans;
void mer(int l,int r)
{
	if (l==r) return;int mid=(l+r)>>1;
	mer(l,mid);mer(mid+1,r);
	int t1=l,t2=mid+1,k=l;
	while (t1<=mid && t2<=r)
	{
		if (a[t1]<=a[t2])
		{
			d[k]=c[t1];
			b[k++]=a[t1++];
		}
		else
		{
			d[k]=c[t2];
			b[k++]=a[t2++];
			ans+=mid-t1+1;
		}
	}
	while (t1<=mid) d[k]=c[t1],b[k++]=a[t1++];
	while (t2<=r) d[k]=c[t2],b[k++]=a[t2++];
	for (k=l;k<=r;k++) a[k]=b[k],c[k]=d[k];
}
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;scanf("%d%d",&n,&m);ans=0;
		for (i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=i;
		mer(1,n);sgt.bil(1,0,n);
		for (i=1;i<=m;i++) scanf("%d",&b[i]);
		int nw=1,nw2=1;
		sort(b+1,b+m+1);
		for (i=1;i<=m;i++)
		{
			while (nw<=n && a[nw]<b[i])
			{
				sgt.upd(1,0,n,0,c[nw]-1,1);nw++;
			}
			while (nw2<=n && a[nw2]<=b[i])
			{
				sgt.upd(1,0,n,c[nw2],n,-1);nw2++;
			}
			ans+=sgt.a[1];
		}
		printf("%lld\n",ans);
	}
}
/*
 5 4 3 2 1
0 1 2 3 4 5
1 2 3 4 5 5
1 2 3 4 5 4
2 3 4 5 5 4
2 3 4 5 4 3
3 4 5 5 4 3
3 4 5 4 3 2
*/