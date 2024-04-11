#include<cstdio>
#include<algorithm>
using namespace std;
int N,M[1<<17];
main()
{
	scanf("%d",&N);
	int S=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&M[i]);
		S+=M[i];
	}
	sort(M,M+N);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		int T=S/N;
		if(i+S%N>=N)T++;
		if(T>M[i])ans+=T-M[i];
	}
	printf("%d\n",ans);
}