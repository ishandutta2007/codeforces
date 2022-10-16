#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;++i)
#define F(i,n) for(i=n;i>=1;--i)
#define FF(i,a,b) for(i=a;i>=b;--i)
#define ff(i,a,b) for(i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main(void)
{
	long int n,m,a,b;
	scanf("%ld%ld%ld%ld",&n,&m,&a,&b);
	if(a*m>b) printf("%ld",(n/m)*b+min((n%m)*a,b));
	else printf("%ld",n*a);
}