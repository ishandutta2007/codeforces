#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,t,ans,a,b,c,h[100005],s[100005],adv,tmp;
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	for(int i=1;i<=n;i++) scanf("%lld",h+i);
	sort(h+1,h+n+1),ans=0;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+h[i];
	adv=s[n]/n;
	for(int i=1;i<=n;i++) if(h[i]<=adv) ans+=adv-h[i];
	ans*=c,ans+=(s[n]-adv*n)*b,tmp=ans,ans=0,adv++;
	for(int i=1;i<=n;i++) if(h[i]>=adv) ans+=h[i]-adv;
	ans*=c,ans+=(adv*n-s[n])*a,ans=min(ans,tmp),tmp=0;
	for(int i=1;i<=n;i++)
	{
		int l=h[i]*(i-1)-s[i-1],r=s[n]-s[i]-h[i]*(n-i);
		if(l<r) ans=min(ans,l*c+(r-l)*b);else ans=min(ans,r*c+(l-r)*a);
	}
	for(int i=1;i<=n;i++) tmp+=h[n]-h[i];
	ans=min(ans,tmp*a),tmp=0;
	for(int i=1;i<=n;i++) tmp+=h[i]-h[1];
	ans=min(ans,tmp*b);
	for(int i=1;i<=n;i++)
	{
		int l=h[i]*(i-1)-s[i-1],r=s[n]-s[i]-h[i]*(n-i);
		ans=min(ans,l*a+r*b);
	}
	return printf("%lld\n",ans),0;
}