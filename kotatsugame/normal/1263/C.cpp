#include<cstdio>
#include<vector>
using namespace std;
int T,N;
main()
{
	scanf("%d",&T);
	for(int ccc=0;ccc<T;ccc++)
	{
		scanf("%d",&N);
		vector<int>ans;
		int i=0;
		while(i*i<=N)
		{
			ans.push_back(i);
			i++;
		}
		int lim=i-1;
		for(;i>0;i--)
		{
			if(N/i>lim)ans.push_back(N/i);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
	}
}