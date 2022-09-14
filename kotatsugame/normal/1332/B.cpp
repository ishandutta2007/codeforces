#include<cstdio>
using namespace std;
int ps[11]={2,3,5,7,11,13,17,19,23,29,31};
int T,N;
int A[1000],c[1000];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			c[i]=0;
		}
		int sm=0;
		for(int pi=0;pi<11;pi++)
		{
			bool fd=false;
			for(int i=0;i<N;i++)if(c[i]==0&&A[i]%ps[pi]==0)fd=true;
			if(fd)
			{
				sm++;
				for(int i=0;i<N;i++)if(c[i]==0&&A[i]%ps[pi]==0)c[i]=sm;
			}
		}
		printf("%d\n",sm);
		for(int i=0;i<N;i++)printf("%d%c",c[i],i+1==N?'\n':' ');
	}
}