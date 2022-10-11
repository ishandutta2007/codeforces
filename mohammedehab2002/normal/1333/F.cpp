#include <bits/stdc++.h>
using namespace std;
int lp[500005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		if (!lp[i])
		{
			for (int j=i;j<=n;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
		lp[i]=i/lp[i];
	}
	sort(lp+2,lp+n+1);
	for (int i=2;i<=n;i++)
	printf("%d ",lp[i]);
}