#include<bits/stdc++.h>
using namespace std;
#define re register
int main()
{
	re int n,a1=0,x,b1=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>a1)a1=x;
	}
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>b1)b1=x;
	}
	printf("%d %d\n",a1,b1);
}