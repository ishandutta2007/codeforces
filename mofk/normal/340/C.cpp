#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
void reduce(ll &p,ll &q)
{
	ll a=p,b=q,k;
	while(b!=0)
	{
		k=a;a=b;b=k%b;
	}
	p/=a;q/=a;
}
int main(void)
{
	ll ans=0,a[MAX],i,n;
	scanf("%I64d",&n);
	f(i,n) scanf("%I64d",&a[i]);
	sort(a,a+n+1);
	f(i,n) ans+=a[i]*(4*i-1-2*n);
	reduce(ans,n);
	printf("%I64d %I64d",ans,n);
}