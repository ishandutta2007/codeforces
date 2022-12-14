#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,test,a[333][333],d;
bool flg;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		}
		flg=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				d=4;
				if (i==1) d--;
				if (j==1) d--;
				if (j==m) d--;
				if (i==n) d--;
				if (a[i][j]>d) flg=1;
				a[i][j]=d;
			}
		}
		if (flg) printf("NO\n");
		else 
		{
			printf("YES\n");
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=m;j++)
				{
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
		}
	}
	return Accepted;
}