#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,a[222222],ans;
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		f=0;
		for (int i=1;i<n;i++)
		{
			if (abs(a[i+1]-a[i])>=2) 
			{
				f=1;
				ans=i;
				break;
			}
		}
		if (!f) printf("NO\n");
		else 
		{
			printf("YES\n");
			printf("%d %d\n",ans,ans+1);
		}
	}
	return Accepted;
}