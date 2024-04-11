#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;++i)
#define F(i,n) for(i=n;i>=1;--i)
#define ff(i,a,b) for(i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main(void)
{
	long int i,n,a[300005];ll ans=0;
	scanf("%ld",&n);
	f(i,n) scanf("%ld",&a[i]);
	sort(a,a+n+1);
	f(i,n-1) ans+=(ll)a[i]*(i+1);
	ans+=(ll)a[n]*n;
	printf("%I64d",ans);
}