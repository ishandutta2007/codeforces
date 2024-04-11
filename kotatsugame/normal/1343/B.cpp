#include<cstdio>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		if(N%4!=0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=0;i<N;i++)
		{
			int now;
			if(i<N/2)
			{
				now=i/2*8+(i%2==0?2:4);
			}
			else
			{
				now=(i-N/2)/2*8+(i%2==0?1:5);
			}
			printf("%d%c",now,i+1==N?'\n':' ');
		}
	}
}