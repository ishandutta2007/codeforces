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
	int i,a[7]={0};
	f(i,6) scanf("%d",&a[i]);
	sort(a,a+7);
	if(a[1]==a[2]&a[2]==a[3]&&a[3]==a[4])
	{
		if(a[5]==a[6]) printf("Elephant");else printf("Bear");
	}
	else if(a[5]==a[2]&a[2]==a[3]&&a[3]==a[4])
	{
		if(a[1]==a[6]) printf("Elephant");else printf("Bear");
	}
	else if(a[5]==a[6]&a[6]==a[3]&&a[3]==a[4])
	{
		if(a[1]==a[2]) printf("Elephant");else printf("Bear");
	}
	else printf("Alien");
}