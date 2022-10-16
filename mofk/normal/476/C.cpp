#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define B 1
#define W -1
typedef long long ll;
using namespace std;
const int MAX=(int)1e5+5;
const ll mod=(ll)1e9+7;
int main(void)
{
	ll a,b,ans=1,tmp;
	scanf("%I64d%I64d",&a,&b);
	ans=(a*b)%mod;
	ans=(ans*(b-1))%mod;
	tmp=2*ans%mod;
	ans=(ans*(a+1))%mod;
	ans=(ans*b)%mod;
	ans=(ans+tmp)%mod;
	while(ans%4!=0) ans+=mod;
	ans=(ans/4)%mod;
	printf("%I64d",ans);
}