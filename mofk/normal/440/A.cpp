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
	int n,i,a[MAX]={0},b=0;
	scanf("%d",&n);
	f(i,n-1)
	{
		scanf("%d",&b);
		a[b]=1;
	}
	f(i,n) if(a[i]==0) {
	printf("%d",i);break;}
}