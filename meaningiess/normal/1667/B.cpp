#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
ll b[500010],s[500010],o[500010],f[500010];
struct segt
{
	ll a[3000010];
	void bil(int x,int l,int r)
	{
		a[x]=-1e8;if (l==r) return;int mid=(l+r)>>1;
		bil(x<<1,l,mid);bil(x<<1|1,mid+1,r);
	}
	void upd(int x,int l,int r,int p,ll v)
	{
		if (l==r){a[x]=max(a[x],v);return;}int mid=(l+r)>>1;
		if (p<=mid) upd(x<<1,l,mid,p,v);else upd(x<<1|1,mid+1,r,p,v);
		a[x]=max(a[x<<1],a[x<<1|1]);
	}
	int qry(int x,int l,int r,int p,int q)
	{
		if (p>q) return -1e7;
		if (p<=l && r<=q) return a[x];int mid=(l+r)>>1,res=-1e7;
		if (p<=mid) res=max(res,qry(x<<1,l,mid,p,q));if (q>mid) res=max(res,qry(x<<1|1,mid+1,r,p,q));
		return res;
	}
}sgt[3];
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,mn=0;cin>>n;
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&b[i]);
			s[i]=s[i-1]+b[i];
			o[i]=s[i];
		}
		o[n+1]=0;
		sort(o+1,o+n+2);
		int q=unique(o+1,o+n+2)-o-1;//cout<<q<<endl;
		for (int j=0;j<3;j++) sgt[j].bil(1,1,q);
		int id=lower_bound(o+1,o+q+1,0)-o;
		for (int j=0;j<3;j++)sgt[j].upd(1,1,q,id,0);
		for (i=1;i<=n;i++)
		{
			id=lower_bound(o+1,o+q+1,s[i])-o;//cout<<s[i]<<' '<<id<<endl;
			int a1=sgt[0].qry(1,1,q,1,id-1),a2=sgt[1].qry(1,1,q,id,id),a3=sgt[2].qry(1,1,q,id+1,q);
			//cout<<a1<<' '<<a2<<' '<<a3<<endl;
			f[i]=max(max(a1+i,a2),a3-i);
			sgt[0].upd(1,1,q,id,f[i]-i);
			sgt[1].upd(1,1,q,id,f[i]);
			sgt[2].upd(1,1,q,id,f[i]+i);//cout<<s[i]<<' '<<id<<' '<<f[i]<<endl;
		}
		cout<<f[n]<<endl;
	}
}