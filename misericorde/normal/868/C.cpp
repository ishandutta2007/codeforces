#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005][15],vis[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
	{
		int fl=1;
		for(int j=1;j<=n;j++)
			if(!a[j][i]) fl=0;
		if(fl)
		{
			printf("NO");
			return 0;
		} 
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0,sum=0;
		for(int j=1;j<=m;j++)
		{
			cnt+=a[i][j];
			sum=(sum<<1)+a[i][j];
		}
		if(cnt==0)
		{
			printf("YES");
			return 0;
		}
		if(cnt>m/2) continue;
		if(cnt==1)
		{
			printf("YES");
			return 0;
		}
		vis[sum]=1;
	}
	if(m!=4) printf("NO");
	else
	{
		for(int i=1;i<16;i++)
			if(vis[i]&&vis[i^15])
			{
				printf("YES");
				return 0;
			}
		printf("NO");
	}
	return 0;
}