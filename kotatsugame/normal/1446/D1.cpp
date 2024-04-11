#include<cstdio>
#include<vector>
using namespace std;
int N;
int A[2<<17];
int cnt[100];
main()
{
	scanf("%d",&N);
	int maxcnt=0,maxA;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		cnt[A[i]]++;
		if(maxcnt<cnt[A[i]])
		{
			maxA=A[i];
			maxcnt=cnt[A[i]];
		}
	}
	for(int i=0;i<100;i++)if(maxA!=i&&maxcnt==cnt[i])
	{
		printf("%d\n",N);
		return 0;
	}
	int ans=0;
	for(int c=0;c<100;c++)if(maxA!=c)
	{
		int score=maxcnt-cnt[c];
		vector<int>R(N+1);
		int cumsum=0;
		R[N]=cumsum;
		int cummin=0,cummax=0;
		for(int i=N;i--;)
		{
			if(A[i]==maxA)cumsum++;
			else if(A[i]==c)cumsum--;
			R[i]=cumsum;
			cummin=min(cummin,cumsum);
			cummax=max(cummax,cumsum);
		}
		vector<int>Rid(cummax-cummin+1,-1);
		for(int i=N;i>=0;i--)
		{
			int r=R[i]-cummin;
			if(Rid[r]==-1)Rid[r]=i;
		}
		cumsum=0;
		ans=max(ans,Rid[score-cummin]);
		for(int i=0;i<N;i++)
		{
			if(A[i]==maxA)cumsum++;
			else if(A[i]==c)cumsum--;
			if(score-cumsum>=cummin&&score-cumsum<=cummax)ans=max(ans,Rid[score-cumsum-cummin]-i-1);
		}
	}
	printf("%d\n",ans);
}