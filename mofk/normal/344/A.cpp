#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int main(void)
{
	long int i,n,c[MAX],cnt=1;
	scanf("%ld",&n);
	f(i,n) 
	{
		scanf("%d",&c[i]);
		if(i>1&&c[i]!=c[i-1]) cnt++;
	}
	printf("%ld",cnt);
}