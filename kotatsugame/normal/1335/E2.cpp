#include<cstdio>
#include<algorithm>
#include<vector>
const int MAXN=200002;
using namespace std;
int T,N;
int A[MAXN];
vector<int>id[200];
int cnt[200][MAXN];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<200;i++)
		{
			id[i].clear();
			id[i].push_back(0);
		}
		for(int i=1;i<=N;i++)
		{
			scanf("%d",&A[i]);
			A[i]--;
			id[A[i]].push_back(i);
		}
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<200;j++)cnt[j][i]=cnt[j][i-1];
			cnt[A[i]][i]++;
		}
		for(int i=0;i<200;i++)
		{
			cnt[i][N+1]=cnt[i][N];
			id[i].push_back(N+1);
		}
		int ans=0;
		for(int k=0;k<200;k++)
		{
			int L=0,R=id[k].size()-1;
			int now=0;
			while(L<R)
			{
				for(int x=0;x<200;x++)ans=max(ans,now*2+cnt[x][id[k][R]-1]-cnt[x][id[k][L]]);
				L++;
				R--;
				now++;
			}
		}
		printf("%d\n",ans);
	}
}