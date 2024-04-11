#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
int N;
pair<int,int>A[2<<17];
pair<int,int>F[5000001];
pair<int,int>B[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i].first);
		A[i].second=i+1;
	}
	sort(A,A+N);
	int bsz=0;
	pair<int,int>TWO=make_pair(0,0);
	int two=0;
	for(int i=0;i<N;)
	{
		int j=i;
		while(j<N&&A[i].first==A[j].first)j++;
		B[bsz++]=A[i];
		if(j-i>=4)
		{
			printf("YES\n%d %d %d %d\n",A[i].second,
			A[i+1].second,
			A[i+2].second,
			A[i+3].second);
			return 0;
		}
		if(j-i>=2)
		{
			if(two!=0)
			{
				printf("YES\n%d %d %d %d\n",TWO.first,A[i].second,TWO.second,A[i+1].second);
				return 0;
			}
			two=A[i].first;
			TWO=make_pair(A[i].second,A[i+1].second);
		}
		i=j;
	}
	for(int i=0;i<bsz;i++)for(int j=i+1;j<bsz;j++)
	{
		int T=B[i].first+B[j].first;
		if(F[T].first==0)F[T]=make_pair(B[i].second,B[j].second);
		else
		{
			printf("YES\n%d %d %d %d\n",F[T].first,F[T].second,B[i].second,B[j].second);
			return 0;
		}
	}
	if(two!=0&&F[two*2].first!=0)
	{
		printf("YES\n%d %d %d %d\n",TWO.first,TWO.second,F[two*2].first,F[two*2].second);
	}
	else
	{
		puts("NO");
	}
}