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
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	printf("%d\n",k*(6*n-1));
	f(i,n) printf("%d %d %d %d\n",k*(6*i-5),k*(6*i-4),k*(6*i-3),k*(6*i-1));
}