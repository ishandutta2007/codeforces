#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int cnt[1<<20];
int now[5][5],nxt[5][5];
main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a;scanf("%d",&a);cnt[a-1]++;
	}
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)now[i][j]=-1e9;
	now[0][0]=0;
	for(int a=0;a<m;a++)
	{
		for(int i=0;i<5;i++)for(int j=0;j<5;j++)nxt[i][j]=-1e9;
		for(int i=0;i<5;i++)for(int j=0;j<5;j++)
		{
			if(now[i][j]<0)continue;
			int c=min(i,j);
			for(int k=0;k<=c&&k<=cnt[a];k++)
			{
				for(int l=0;l<5&&k+l<=cnt[a];l++)
				{
					nxt[l][i-k]=max(nxt[l][i-k],now[i][j]+(cnt[a]-k-l)/3+k);
				}
			}
		}
		for(int i=0;i<5;i++)for(int j=0;j<5;j++)now[i][j]=nxt[i][j];
	}
	int ans=0;
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)ans=max(ans,now[i][j]);
	printf("%d\n",ans);
}