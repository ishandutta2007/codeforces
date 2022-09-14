#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	if(N%3!=2)printf("1 1 %d\n",N-2);
	else printf("1 2 %d\n",N-3);
}