#include<bits/stdc++.h>
using namespace std;
int t,a,b,x,y;
int main()
{
	scanf("%d",&t);
	for(int am=1;am<=t;am++)
	{
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(a*2<=b) printf("%lld\n",1LL*(x+y)*a);
		else 
		{
			if(x>y) swap(x,y);
			printf("%lld\n",1LL*x*b+1LL*(y-x)*a);
		}
	}
	return 0;
}