#include<bits/stdc++.h>
using namespace std;
int test,n,a[111],sum,mx;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);sum=0;mx=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if (mx*2>sum || (sum&1)) printf("T\n");
		else printf("HL\n");
	}
	return 0;
}