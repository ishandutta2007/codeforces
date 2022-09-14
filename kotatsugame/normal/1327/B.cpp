#include<cstdio>
#include<vector>
using namespace std;
int T,N;
bool used[1<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)used[i]=false;
		int oki=-1;
		for(int i=0;i<N;i++)
		{
			int k;scanf("%d",&k);
			int marry=-1;
			for(int j=0;j<k;j++)
			{
				int a;scanf("%d",&a);
				a--;
				if(!used[a]&&marry==-1)
				{
					marry=a;
				}
			}
			if(marry==-1)
			{
				if(oki==-1)oki=i;
			}
			else used[marry]=true;
		}
		if(oki==-1)puts("OPTIMAL");
		else
		{
			puts("IMPROVE");
			int mi=0;
			while(used[mi])mi++;
			printf("%d %d\n",oki+1,mi+1);
		}
	}
}