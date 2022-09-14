#include<cstdio>
#include<vector>
using namespace std;
int T;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		int N;
		scanf("%d",&N);
		vector<int>ans;
		for(int i=2;i*i<=N;i++)
		{
			if(N%i==0)
			{
				N/=i;
				ans.push_back(i);
			}
			if(ans.size()==2)break;
		}
		if(ans.size()==2&&N>1&&ans[0]!=N&&ans[1]!=N)
		{
			printf("YES\n%d %d %d\n",ans[0],ans[1],N);
		}
		else puts("NO");
	}
}