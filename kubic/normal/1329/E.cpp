#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const ll INF=1e18;char buf[LIM],*P1=buf,*P2=buf;
int T,n,tp;ll m,c,l,r,L,R,nw,ans,a[N];struct Node {ll l,r;}b[N];
ll rd()
{
	ll res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
bool cmp(Node x,Node y) {return x.l==y.l?x.r>y.r:x.l<y.l;}
void slv()
{
	c=rd();n=rd();m=rd();l=1;r=c;tp=0;ans=INF;
	for(int i=1;i<=n;++i) a[i]=rd();a[++n]=c;m+=n;
	for(int i=n;i;--i) a[i]-=a[i-1];
	while(l<=r)
	{
		ll mid=(l+r)/2,s=0;for(int i=1;i<=n;++i) s+=a[i]/mid;
		if(s>=m) l=mid+1;else r=mid-1;
	}L=r;l=1;r=c;
	while(l<=r)
	{
		ll mid=(l+r)/2,s=0;for(int i=1;i<=n;++i) s+=(a[i]-1)/mid+1;
		if(s<=m) r=mid-1;else l=mid+1;
	}R=l;
	for(int i=1;i<=n;++i)
	{
		l=1;r=c;
		while(l<=r)
		{
			ll mid=(l+r)/2,t=mid<=a[i]?(a[i]-1)/(a[i]/mid)+1:INF;
			if(t>R) r=mid-1;else l=mid+1;
		}if(l<=L) b[++tp]=(Node) {l,l<=a[i]?(a[i]-1)/(a[i]/l)+1:INF};
	}sort(b+1,b+tp+1,cmp);b[++tp]=(Node) {L+1,R};nw=R;
	for(int i=1;i<=tp;++i)
		ans=min(ans,nw-b[i].l+1),nw=max(nw,b[i].r);printf("%lld\n",ans);
}
int main() {T=rd();while(T--) slv();return 0;}