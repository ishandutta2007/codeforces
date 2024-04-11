#include<cstdio>
#include<algorithm>
using namespace std;
int N,W;
main()
{
	scanf("%d%d",&N,&W);
	int now=0,mx=0,mn=0;
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		now+=x;
		mx=max(mx,now);
		mn=min(mn,now);
	}
	printf("%d\n",max(W-mx+mn+1,0));
}