#include<bits/stdc++.h>
using namespace std;
const long long magic=100000;
long long a,b,ans,p,ll,rr,kl,kr,al,bl;
long long l,r,mid;
void fuck(long long a,long long b)
{
	l=1;r=2e9;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (a/mid<=b) r=mid-1;
		else l=mid+1;
	}
	kl=(long long)l;
	l=1;r=2e9;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (a/mid<b) r=mid-1;
		else l=mid+1;
	}
	kr=(long long)r;
}
int main()
{
	scanf("%lld%lld",&a,&b);
	for (long long i=1;i<=magic && i<=a+b;i++)
	{
		p=(a+b)/i;ll=rr=0;
		if (a%(p+1)==0) al=(a/(p+1));
		else al=(a/(p+1)+1);
		if (b%(p+1)==0) bl=(b/(p+1));
		else bl=(b/(p+1)+1);
		if (al>a/p || bl>b/p) continue;
		rr=(a/p)+(b/p);ll=bl+al;
		if (i>=ll && i<=rr) ans++;
	}
	for (long long i=1;i<=magic;i++)
	{
		ll=rr=0;p=i;
		if (a%(p+1)==0) al=(a/(p+1));
		else al=(a/(p+1)+1);
		if (b%(p+1)==0) bl=(b/(p+1));
		else bl=(b/(p+1)+1);
		if (al>a/p || bl>b/p) continue;
		rr=(a/p)+(b/p);ll=bl+al;
		ll=max(ll,magic+1);
		fuck(a+b,p);
		ll=max(ll,kl);rr=min(rr,kr);
		if (ll>rr) continue;
		ans+=(rr-ll+1);
	}
	printf("%lld\n",ans);
	return 0;
}