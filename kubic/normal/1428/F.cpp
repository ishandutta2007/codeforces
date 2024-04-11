#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int n,pr[N],sf[N];ll sPr[N],sSf[N];ll ans;char a[N];
void slv(int l,int r)
{
	if(l==r) {ans+=a[l]-48;return;}
	int mid=(l+r)/2,tL=mid+1,tR=mid;
	if(a[mid]=='1' && a[mid+1]=='1')
	{
		for(int i=mid;i>=l && a[i]==a[mid];--i) tL=i;
		for(int i=mid+1;i<=r && a[i]==a[mid+1];++i) tR=i;
	}sf[tL]=pr[tR]=sSf[l-1]=sPr[r+1]=0;
	for(int i=tL-1,cnt=0;i>=l;--i)
	{if(a[i]=='0') cnt=0;else ++cnt;sf[i]=max(sf[i+1],cnt);}
	for(int i=l;i<tL;++i) sSf[i]=sSf[i-1]+sf[i];
	for(int i=tR+1,cnt=0,t=tL-1;i<=r;++i)
	{
		if(a[i]=='0') cnt=0;else ++cnt;pr[i]=max(pr[i-1],cnt);
		while(t>=l && sf[t]<=max(tR-tL+1,pr[i])) --t;
		ans+=1ll*max(tR-tL+1,pr[i])*(tL-t-1)+sSf[t]; 
	}for(int i=r;i>tR;--i) sPr[i]=sPr[i+1]+pr[i];
	for(int i=mid,t=tR+1;i>=tL;--i)
	{
		while(t<=r && pr[t]<=tR-i+1) ++t;
		ans+=1ll*(tR-i+1)*(t-tR-1)+sPr[t];
	}
	for(int i=mid+1,t=tL-1;i<=tR;++i)
	{
		while(t>=l && sf[t]<=i-tL+1) --t;
		ans+=1ll*(i-tL+1)*(tL-t-1)+sSf[t];
	}ans+=1ll*(tR-mid)*(tR-mid+1)/2*(mid-tL+1);
	ans+=1ll*(mid-tL+1)*(mid-tL+2)/2*(tR-mid);slv(l,mid);slv(mid+1,r);
}
int main()
{
	scanf("%d %s",&n,a+1);
	slv(1,n);printf("%lld\n",ans);return 0;
}