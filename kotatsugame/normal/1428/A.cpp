#include<cstdio>
#include<cmath>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans;
		if(a==c)ans=abs(b-d);
		else if(b==d)ans=abs(a-c);
		else ans=abs(b-d)+abs(a-c)+2;
		printf("%d\n",ans);
	}
}