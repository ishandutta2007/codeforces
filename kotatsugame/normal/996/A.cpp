#include<cstdio>
#include<vector>
using namespace std;
int N;
main()
{
	scanf("%d",&N);
	int ans=0;
	for(int c:{100,20,10,5,1})
	{
		ans+=N/c;
		N%=c;
	}
	printf("%d\n",ans);
}