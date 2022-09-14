#include<cstdio>
using namespace std;
int t;
main()
{
	scanf("%d",&t);
	for(;t--;)
	{
		int n,k1,k2;scanf("%d%d%d",&n,&k1,&k2);
		bool f1=false,f2=false;
		for(int i=0;i<k1;i++)
		{
			int a;scanf("%d",&a);
			if(a==n)f1=true;
		}
		for(int i=0;i<k2;i++)
		{
			int a;scanf("%d",&a);
			if(a==n)f2=true;
		}
		puts(f1?"YES":"NO");
	}
}