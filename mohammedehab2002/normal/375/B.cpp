#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int mat[5005][5005],first[5005][5005],cnt[5005],tmp[5005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		getchar();
		for (int x=1;x<=m;x++)
		{
			mat[i][x]=getchar()-'0';
			if (!mat[i][x])
			first[i][x]=x;
		}
		first[i][m+1]=m+1;
		for (int x=m;x>=1;x--)
		{
			if (!first[i][x])
			first[i][x]=first[i][x+1];
		}
	}
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		memset(cnt,0,sizeof(cnt));
		for (int x=1;x<=n;x++)
		cnt[first[x][i]]++;
		int cur=1;
		for (int x=m+1;x>0;x--)
		{
			while (cnt[x])
			{
				tmp[cur++]=x;
				cnt[x]--;
			}
		}
		for (int x=1;x<=n;x++)
		ans=max(ans,(tmp[x]-i)*x);
	}
	printf("%d",ans);
}