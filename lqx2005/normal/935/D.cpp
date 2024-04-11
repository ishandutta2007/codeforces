#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=100000;
const ll MOD=1e9+7;
ll n,m;
ll a[N+5],b[N+5];
ll qpow(ll a,ll b)
{
	ll sum=1;
	while(b>0)
	{
		if(b%2==1) sum=(sum*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return sum;
}
ll inv(ll x)
{
	return qpow(x,MOD-2);
}
void add(ll &x,ll y)
{
	y%=MOD;
	x+=y;
	if(x>=MOD) x-=MOD;
	return;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
	ll ans=0,sum=1;
	for(ll i=1;i<=n;i++)
	{
		if(a[i]!=0&&b[i]!=0)
		{
			if(a[i]!=b[i])
			{
				if(a[i]>b[i]) add(ans,sum);
				break;
			} 
			else continue;
		} 
		if(a[i]==0&&b[i]!=0) 
		{
			sum=sum*inv(m)%MOD;
			add(ans,sum*(m-b[i]));
		}
		if(a[i]!=0&&b[i]==0) 
		{
			sum=sum*inv(m)%MOD;
			add(ans,sum*(a[i]-1));			
		}
		if(a[i]==0&&b[i]==0) 
		{
			sum=sum*inv(m)%MOD;
			add(ans,sum*(m-1)%MOD*inv(2));
		}
		//cout<<sum<<endl;
		//cout<<inv(m)<<endl;
	} 
	printf("%lld\n",ans);
	return 0;
}