#include<cstdio>
using namespace std;
int N,M;
int cnt[10];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		cnt[A-1]++;
	}
	int ans=0;
	for(int i=0;i<M;i++)for(int j=i+1;j<M;j++)ans+=cnt[i]*cnt[j];
	printf("%d\n",ans);
}