#include<cstdio>
using namespace std;
int T,a,b;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&a,&b);
		int X=0;
		if(a%4==0)X=0;
		else if(a%4==1)X=a-1;
		else if(a%4==2)X=a-1^a-2;
		else X=a-1^a-2^a-3;
		int ans=a;
		if(X!=b)
		{
			if((X^b)!=a)ans++;
			else ans+=2;
		}
		printf("%d\n",ans);
	}
}