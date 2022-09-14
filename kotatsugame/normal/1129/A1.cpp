#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
vector<int>B[5050];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		B[a].push_back((b-a+N)%N);
	}
	for(int i=0;i<N;i++)sort(B[i].rbegin(),B[i].rend());
	for(int i=0;i<N;i++)
	{
		int ans=0;
		for(int j=0;j<N;j++)if(!B[(i+j)%N].empty())
		{
			ans=max(ans,j-N+(int)B[(i+j)%N].size()*N+B[(i+j)%N].back());
		}
		printf("%d%c",ans,i+1==N?10:32);
	}
}