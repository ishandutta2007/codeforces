#include<cstdio>
using namespace std;
int K;
main()
{
	scanf("%d",&K);
	printf("2 3\n%d %d 0\n%d %d %d\n",(1<<18)-1,K,1<<17,(1<<18)-1,K);
}