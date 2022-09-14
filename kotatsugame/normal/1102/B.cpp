#include<cstdio>
#include<vector>
using namespace std;
int N,K;
vector<int>ids[5050];
int ans[5050];
vector<int>col[5050];
main()
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);
		A--;
		ids[A].push_back(i);
	}
	for(int i=0;i<5000;i++)
	{
		if(ids[i].size()>K)
		{
			puts("NO");
			return 0;
		}
		for(int j=0;j<ids[i].size();j++)
		{
			ans[ids[i][j]]=j;
			col[j].push_back(ids[i][j]);
		}
	}
	int id=0;
	for(int i=0;i<K;i++)if(col[i].empty())
	{
		while(col[id].size()==1)id++;
		int j=col[id].back();
		col[id].pop_back();
		ans[j]=i;
		col[i].push_back(j);
	}
	puts("YES");
	for(int i=0;i<N;i++)printf("%d%c",ans[i]+1,i+1==N?10:32);
}