#include<cstdio>
#include<algorithm>
using namespace std;
int T,N,K;
int x[100],y[100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&K);
		for(int i=0;i<N;i++)scanf("%d%d",&x[i],&y[i]);
		bool ok=false;
		for(int i=0;i<N;i++)
		{
			bool all=true;
			for(int j=0;j<N;j++)
			{
				if(abs(x[i]-x[j])+abs(y[i]-y[j])>K)
				{
					all=false;
					break;
				}
			}
			if(all)
			{
				ok=true;
				break;
			}
		}
		puts(ok?"1":"-1");
	}
}