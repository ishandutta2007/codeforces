#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if (!c && a<b)
	{
		printf("%d\n",2*a+1);
		return 0;
	}
	if (a==b) printf("%lld\n",2ll*min(a,b)+2ll*c);
	else printf("%lld\n",2ll*min(a,b)+1ll+2ll*c);
	return Accepted;
}