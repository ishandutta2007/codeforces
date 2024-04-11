#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#define mod 1000000007
#define f(i,n) for(i=1;i<=n;i++)
#define F(i,n) for(i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define B 1
#define W -1
typedef long long ll;
using namespace std;
const int MAX=(int)1e5+5;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n<m) printf("-1");
	else printf("%d",(((n+1)/2-1)/m+1)*m);
}