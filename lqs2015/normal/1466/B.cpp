#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a[111111],used[222222],ans;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=2*n+1;i++) used[i]=0;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			if (!used[a[i]])
			{
				used[a[i]]=1;
				ans++;
			}
			else if (!used[a[i]+1])
			{
				used[a[i]+1]=1;
				ans++;
			}
		} 
		printf("%d\n",ans);
	}
	return Accepted;
}