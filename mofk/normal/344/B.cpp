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
	long int a,b,c,d;
	scanf("%ld%ld%ld",&a,&b,&c);
	d=(a+b+c)/2;
	if((a+b+c)%2!=0) printf("Impossible");
	else if(d<a||d<b||d<c) printf("Impossible");
	else printf("%ld %ld %ld",d-c,d-a,d-b);
}