#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define re register
int main()
{
	re int a,n,b,ans=0;
	scanf("%d%d",&b,&n);
	b%=2;
	for(re int i=1;i<n;i++)
	{
		scanf("%d",&a);
		a%=2;ans+=a*b;
		ans%=2;
	}
	scanf("%d",&a);a%=2;ans+=a;ans%=2;
	if(ans)puts("odd");
	else puts("even");
}