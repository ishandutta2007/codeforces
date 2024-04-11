#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define MAX (int)1e5+5
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(void)
{
	int i,n,p[105],q[105],ans=0;
	scanf("%d",&n);
	f(i,n)
	{
		scanf("%d%d",&p[i],&q[i]);
		if(q[i]-p[i]>1) ans++;
	}
	printf("%d",ans);
}