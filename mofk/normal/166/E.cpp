#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
ll ans(ll n)
{
	ll a=1,i;
	f(i,n)
	{
		a=(a*3)%mod;
	}
	if(n%2==0) a+=3;else a-=3;
	while(a%4!=0) a+=mod;
	a/=4;
	return a;
}
int main(void)
{
	ll n;
	scanf("%I64d",&n);
	printf("%I64d",ans(n));
}