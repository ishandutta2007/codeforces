#include<cstdio>
using namespace std;
int H,M,D;
main()
{
	scanf("%d:%d%d",&H,&M,&D);
	H+=D/60;
	M+=D%60;
	H+=M/60;M%=60;
	H%=24;
	printf("%02d:%02d\n",H,M);
}