#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
ll a[N];map<ll,int> b,c;
int main()
{
	int n,p,k,i,j;ll ans=0;scanf("%d%d%d",&n,&p,&k);
	for (i=1;i<=n;i++) {scanf("%d",&a[i]);ll t=1ll*a[i]*a[i]%p;b[(t*t%p-1ll*k*a[i]%p+p)%p]++;}
	for (i=1;i<=n;i++)
	{
		ll t=1ll*a[i]*a[i]%p,m=(t*t%p-1ll*k*a[i]%p+p)%p;if (!c[m]) ans+=1ll*b[m]*(b[m]-1);c[m]=1;
	}
	cout<<ans/2;
}