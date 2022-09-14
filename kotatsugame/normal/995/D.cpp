#include<cstdio>
using namespace std;
int N,R;
int c[1<<18];
main()
{
	scanf("%d%d",&N,&R);
	long long sum=0;
	for(int i=0;i<1<<N;i++)
	{
		scanf("%d",&c[i]);
		sum+=c[i];
	}
	printf("%.16f\n",(double)sum/(1<<N));
	for(;R--;)
	{
		int z,g;scanf("%d%d",&z,&g);
		sum-=c[z];
		c[z]=g;
		sum+=g;
		printf("%.16f\n",(double)sum/(1<<N));
	}
}