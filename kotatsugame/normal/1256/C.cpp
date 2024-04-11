#include<cstdio>
using namespace std;
int N,M,D;
int C[1000];
int ans[1000];
main()
{
	scanf("%d%d%d",&N,&M,&D);
	int sum=0;
	for(int i=0;i<M;i++)
	{
		scanf("%d",&C[i]);
		sum+=C[i];
	}
	sum=N-sum;
	int id=0;
	for(int i=0;i<M;i++)
	{
		int T=sum;
		if(T>D-1)T=D-1;
		sum-=T;
		id+=T;
		for(int k=0;k<C[i];k++)ans[id+k]=i+1;
		id+=C[i];
	}
	if(sum>D-1)puts("NO");
	else
	{
		puts("YES");
		for(int i=0;i<N;i++)printf("%d%c",ans[i],i+1==N?10:32);
	}
}