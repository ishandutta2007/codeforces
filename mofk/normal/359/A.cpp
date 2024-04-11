#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<cstdlib>
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
const int MAX=(int)1e5+5;
int main(void)
{
	int a[55][55],n,m,i,j,ans=4;
	scanf("%d%d",&n,&m);
	f(i,n) f(j,m)
	{
		scanf("%d",&a[i][j]);
		if((i==1||j==1||i==n||j==m)&&a[i][j]==1) ans=2;
	}
	printf("%d",ans);
}