#include<cstdio>
using namespace std;
int N,K;
int id[101];
int ans[100];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int a;scanf("%d",&a);
		id[a]=i+1;
	}
	int sz=0;
	for(int i=1;i<=100;i++)if(id[i])ans[sz++]=id[i];
	if(sz<K)puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<K;i++)printf("%d%c",ans[i],i+1==K?10:32);
	}
}