#include <bits/stdc++.h>
using namespace std;
int col[50],ans[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		memset(col,0,sizeof(col));
		int n,cc=0;
		scanf("%d",&n);
		for (int j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			for (int i=2;;i++)
			{
				if (a%i==0)
				{
					if (!col[i])
					col[i]=++cc;
					ans[j]=col[i];
					break;
				}
			}
		}
		printf("%d\n",cc);
		for (int j=0;j<n;j++)
		printf("%d ",ans[j]);
		printf("\n");
	}
}