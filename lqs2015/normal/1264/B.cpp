#include<bits/stdc++.h>
using namespace std;
int a[4],ans[222222],n,cur,b[4];
bool f;
int main()
{
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	n=a[0]+a[1]+a[2]+a[3];
	for (int i=0;i<=3;i++)
	{
		for (int j=0;j<=3;j++) b[j]=a[j];
		cur=i;f=0;
		for (int j=1;j<=n;j++)
		{
			if (cur>3 || cur<0 || !b[cur])
			{
				f=1;
				break;
			}
			ans[j]=cur;b[cur]--;
			if (cur>=1 && b[cur-1]) cur--;
			else cur++;
		}
		if (!f)
		{
			printf("YES\n");
			for (int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}