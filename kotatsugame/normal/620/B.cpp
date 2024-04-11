#include<cstdio>
using namespace std;
int c[10]={6,2,5,5,4,5,6,3,7,6};
main()
{
	int A,B;
	scanf("%d%d",&A,&B);
	int ans=0;
	for(int x=A;x<=B;x++)
	{
		int t=x;
		while(t)ans+=c[t%10],t/=10;
	}
	printf("%d\n",ans);
}