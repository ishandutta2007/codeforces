#include<cstdio>
#include<vector>
using namespace std;
int T,X;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&X);
		vector<int>ans;
		for(int i=10;i--;)
		{
			if(X>i)
			{
				ans.push_back(i);
				X-=i;
			}
			else
			{
				ans.push_back(X);
				X=0;
				break;
			}
		}
		if(X)puts("-1");
		else
		{
			for(int i=ans.size();i--;)printf("%d",ans[i]);
			puts("");
		}
	}
}