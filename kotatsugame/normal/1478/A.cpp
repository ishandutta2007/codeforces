#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		int ans=0,cnt=0,p=0;
		for(;N--;)
		{
			int A;
			scanf("%d",&A);
			if(A==p)cnt++;
			else cnt=1;
			p=A;
			if(ans<cnt)ans=cnt;
		}
		printf("%d\n",ans);
	}
}