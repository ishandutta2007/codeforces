#include<cstdio>
using namespace std;
int id[2<<17];
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			int p;
			scanf("%d",&p);
			id[p-1]=i;
		}
		int L=id[0],R=id[0];
		printf("1");
		for(int i=1;i<N;i++)
		{
			int t=id[i];
			if(L>t)L=t;
			if(R<t)R=t;
			printf(R-L==i?"1":"0");
		}
		puts("");
	}
}