#include<iostream>
#include<cstdio>
using namespace std;
char s[1999],c;
int n,sum[1999][1999],ans[1999][33],pos[33][1999],cnt[33],h,q,x;
bool check(int h,int col,int num)
{
	if (h>cnt[col]) return 0;
	if (!h) return 1;
	for (int i=1;i<=cnt[col]-h+1;i++)
	{
		if (sum[i][i+h-1]<=num) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
	{
		cnt[s[i]-'a']++;
		pos[s[i]-'a'][cnt[s[i]-'a']]=i;
	}
	for (int i=0;i<26;i++)
	{
		for (int j=1;j<=cnt[i];j++)
		{
			sum[j][j]=0;
			for (int k=j+1;k<=cnt[i];k++)
			{
				sum[j][k]=sum[j][k-1]+pos[i][k]-pos[i][k-1]-1;
			}
		}
		h=0;
		for (int j=1;j<=n;j++)
		{
			while(check(h,i,j)) h++;
			h--;
			ans[j][i]=min(j+h,n);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %c",&x,&c);
		printf("%d\n",ans[x][c-'a']);
	}
	return 0;
}