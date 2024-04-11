#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	long long F=1;
	for(int i=1;i<N;i++)F*=i;
	printf("%lld\n",F/(N/2));
}