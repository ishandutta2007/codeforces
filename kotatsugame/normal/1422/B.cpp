#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int N,M;
int A[100][100];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			scanf("%d",&A[i][j]);
		}
		long long ans=0;
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			vector<int>now;
			now.push_back(A[i][j]);
			now.push_back(A[N-i-1][j]);
			now.push_back(A[i][M-j-1]);
			now.push_back(A[N-i-1][M-j-1]);
			sort(now.begin(),now.end());
			ans+=abs(now[1]-A[i][j]);
		}
		printf("%lld\n",ans);
	}
}