#include<cstdio>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	int mx=0;
	for(;N--;)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(mx<x+y)mx=x+y;
	}
	printf("%d\n",mx);
}