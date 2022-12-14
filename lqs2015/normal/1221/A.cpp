#include<bits/stdc++.h>
using namespace std;
int test,n,a[111],sum;
bool f;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sum=0;f=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==2048) 
			{
				f=1;
				break;
			}
			if (a[i]<2048) sum+=a[i];
		}
		if (f || sum>=2048) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}