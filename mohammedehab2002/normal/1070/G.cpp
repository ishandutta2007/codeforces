#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int n,arr[105],cop[105],dp[105];
int h[105],r[105],pos[105];
vector<int> ans;
bool go(int i,int dir)
{
	memset(dp,0,sizeof(dp));
	int l=-1,tmp=i;
	while (i>0 && i<=n)
	{
		dp[i]=min(0,dp[i-dir])+cop[i];
		if (r[i] && r[i]+dp[i]>=0)
		l=i;
		i+=dir;
	}
	if (l!=-1)
	{
		while (l!=tmp-dir)
		{
			if (r[l])
			ans.push_back(l);
			r[l]=0;
			cop[l]=0;
			l-=dir;
		}
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		h[a]=b;
		pos[a]=i+1;
	}
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cop[j]=arr[j];
			r[j]=h[j];
		}
		ans.clear();
		for (int j=1;j<=m;j++)
		{
			go(i,-1);
			go(i,1);
		}
		if (ans.size()==m)
		{
			printf("%d\n",i);
			for (int j:ans)
			printf("%d ",pos[j]);
			return 0;
		}
	}
	printf("-1");
}