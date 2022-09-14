#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int T,A,B;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&A,&B);
		int N=A+B;
		vector<int>ans;
		for(int k=0;k<=1;k++)
		{
			int a=(N+k)/2;
			for(int l=0;l<=a&&l<=A;l++)if(a-l<=B)
			{
				int br=a-l+A-l;
				ans.push_back(br);
			}
		}
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d%c",ans[i],i+1==ans.size()?10:32);
	}
}