#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int B[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	if(N==1)
	{
		puts("0");
		return 0;
	}
	int D=B[1]-B[0];
	int ans=1e9;
	for(int d=D-2;d<=D+2;d++)for(int a=B[0]-1;a<=B[0]+1;a++)
	{
		int now=0;
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			int u=a+d*i;
			if(abs(B[i]-u)<=1)now+=abs(B[i]-u);
			else
			{
				ok=false;
				break;
			}
		}
		if(ok)ans=min(ans,now);
	}
	printf("%d\n",ans==(int)1e9?-1:ans);
}