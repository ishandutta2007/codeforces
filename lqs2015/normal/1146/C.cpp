#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int t,n,ans,x;
vector<int> a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for (int i=0;i<7;i++)
		{
			a.clear();b.clear();
			for (int j=1;j<=n;j++)
			{
				if (j&(1<<i)) a.push_back(j);
				else b.push_back(j); 
			}
			if (!a.size() || !b.size()) continue;
			printf("%d %d ",(int)a.size(),(int)b.size());
			for (int i=0;i<a.size();i++) printf("%d ",a[i]);
			for (int i=0;i<b.size();i++) printf("%d ",b[i]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&x);
			ans=max(ans,x);
		}
		printf("-1 %d\n",ans);
		fflush(stdout);
	}
	return Accepted;
}