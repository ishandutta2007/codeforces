#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a[111],used[5555],ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		memset(used,0,sizeof(used));
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (!used[a[j]-a[i]]) 
				{
					used[a[j]-a[i]]=1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return Accepted;
}