#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int P[1<<20];
bool vis[1<<20];
int ans[1<<20];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&P[i]);
		P[i]--;
	}
	vector<vector<int> >A;
	for(int i=0;i<N;i++)if(!vis[i])
	{
		int u=i;
		vector<int>now;
		do{
			now.push_back(u);
			vis[u]=true;
			u=P[u];
		}while(u!=i);
		A.push_back(now);
	}
	sort(A.begin(),A.end(),[](vector<int>&a,vector<int>&b){return a.size()<b.size();});
	for(int i=0;i<A.size();i++)
	{
		if(A[i].size()%2==1)
		{
			int n=(A[i].size()+1)/2;
			for(int j=0;j<A[i].size();j++)ans[A[i][j]]=A[i][(j+n)%A[i].size()];
		}
		else
		{
			if(i+1==A.size()||A[i+1].size()!=A[i].size())
			{
				puts("-1");
				return 0;
			}
			for(int j=0;j<A[i].size();j++)
			{
				ans[A[i][j]]=A[i+1][j];
				ans[A[i+1][j]]=A[i][(j+1)%A[i].size()];
			}
			i++;
		}
	}
	for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?10:32);
}