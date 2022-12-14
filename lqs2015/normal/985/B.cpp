#include<iostream>
#include<cstdio>
using namespace std;
bool mp[2222][2222],f;
int cnt[2222],n,m;
char c;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		getchar();
		for (int j=1;j<=m;j++)
		{
			c=getchar();
			mp[i][j]=c-'0';
			cnt[j]+=mp[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		f=0;
		for (int j=1;j<=m;j++)
		{
			if (mp[i][j])
			{
				if (cnt[j]==1) f=1;
			}
			else 
			{
				if (!cnt[j]) f=1;
			}
		}
		if (!f)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}