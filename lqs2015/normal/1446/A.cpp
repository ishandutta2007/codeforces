#include<bits/stdc++.h>
using namespace std;
int n,a[222222],test,flg;
long long w,all;
vector<int> ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%lld",&n,&w);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		flg=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]>=((w+1)/2) && a[i]<=w)
			{
				printf("1\n");
				printf("%d\n",i);
				flg=1;break;
			}
		}
		if (!flg)
		{
			ans.clear();all=0;
			for (int i=1;i<=n;i++)
			{
				if (a[i]<=w)
				{
					all+=a[i];
					ans.push_back(i);
					if (all>=(w+1)/2 && all<=w) break;
				} 
			}
			if (all<(w+1)/2) printf("-1\n");
			else 
			{
				printf("%d\n",(int)ans.size());
				for (int i=0;i<ans.size();i++)
				{
					printf("%d ",ans[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}