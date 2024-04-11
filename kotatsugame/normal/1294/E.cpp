#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
main()
{
	scanf("%d%d",&N,&M);
	vector<vector<int> >A(N,vector<int>(M));
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)
	{
		scanf("%d",&A[i][j]);
		A[i][j]--;
	}
	long long ans=0;
	for(int j=0;j<M;j++)
	{
		vector<int>cnt(N,0);
		for(int i=0;i<N;i++)
		{
			if(A[i][j]%M==j&&A[i][j]<N*M)
			{
				int k=A[i][j]/M;
				if(k<=i)cnt[i-k]++;
				else cnt[i-k+N]++;
			}
		}
		int now=2e9;
		for(int i=0;i<N;i++)
		{
			now=min(now,i+N-cnt[i]);
		}
		ans+=now;
	}
	printf("%lld\n",ans);
}