#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define il inline
using namespace std;
struct dat
{
	int x,l,r,k;
	void mem(int a,int b,int c,int d){x=a;l=b;r=c;k=d;}
	bool operator<(const dat&a)const{return x<a.x;}
}p[111];
int n,x[55],y[55],h[111],a[111];
il ll gets(int k)
{
	if (k<0) return 0;int i,j,cnt=0,l,r;ll ans=0;
	for (i=1;i<=n;i++)
	{
		p[++cnt].mem(x[i]-k,y[i]-k,y[i]+k+1,1);h[cnt]=y[i]+k+1;
		p[++cnt].mem(x[i]+k+1,y[i]-k,y[i]+k+1,-1);h[cnt]=y[i]-k;
	}
	sort(p+1,p+cnt+1);sort(h+1,h+cnt+1);
	cnt=unique(h+1,h+cnt+1)-h-1;
	for (i=1;i<=2*n;i++)
	{
		if (p[i].x!=p[i-1].x) for (j=1;j<cnt;j++)
			if (a[j]) ans+=(ll)(p[i].x-p[i-1].x)*(h[j+1]-h[j]);
		l=lower_bound(h+1,h+cnt+1,p[i].l)-h,r=lower_bound(h+1,h+cnt+1,p[i].r)-h;
		for (j=l;j<r;j++) a[j]+=p[i].k;
	}
	return ans;
}
il ll diff(int x){return gets(x)-gets(x-1);}
const ll inv2=499122177,inv6=166374059;
int main()
{
	int T,i,nw=0,l,r,to;ll ans=0;cin>>n>>T;for (i=1;i<=n;i++) cin>>x[i]>>y[i];
	while (nw<=T)
	{
		l=to=nw;r=T;ll g=diff(nw),e=diff(nw+1)-g;
		while (l<=r)
		{
			int mid=(l+r)>>1;ll t=diff(mid);if (t!=g+(mid-nw)*e) r=mid-1;
			else l=mid+1,to=mid;
		}
		ll t=e*(to-nw)%mod*(to-nw+1)%mod*(to-nw+2)%mod*inv6%mod;
		(g=g%mod*(to-nw)%mod*(to-nw+1)%mod*inv2%mod)%=mod;
		(ans+=gets(nw)%mod*(to-nw+1)%mod+t+g)%=mod;nw=to+1;
	}
	cout<<((gets(T)%mod*(T+1)%mod)-ans+mod)%mod;
}