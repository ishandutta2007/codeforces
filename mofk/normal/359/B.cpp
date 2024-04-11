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
	int i,n,k,a[MAX]={0};
	scanf("%d%d",&n,&k);
	f(i,2*n) a[i]=a[i-1]+1;
	f(i,k) swap(a[2*i-1],a[2*i]);
	f(i,2*n) printf("%d ",a[i]);
}