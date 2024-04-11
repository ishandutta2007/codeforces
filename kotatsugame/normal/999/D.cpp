#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N,M;
vector<int>ids[2<<17];
int A[2<<17];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		ids[A[i]%M].push_back(i);
	}
	long long ans=0;
	queue<int>P;
	for(int i=0;i<2*M;i++)
	{
		if(i<M&&ids[i].size()>N/M)
		{
			for(int k=N/M;k<ids[i].size();k++)P.push(ids[i][k]);
		}
		else if(ids[i%M].size()<N/M)
		{
			int d=N/M-ids[i%M].size();
			while(d>0&&!P.empty())
			{
				d--;
				int id=P.front();
				P.pop();
				ans+=i-A[id]%M;
				A[id]+=i-A[id]%M;
				ids[i%M].push_back(id);
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=0;i<N;i++)printf("%d%c",A[i],i+1==N?10:32);
}