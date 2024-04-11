#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,cur,sum[5555][5555],ans;
bool mp[5555][5555];
char s[5555];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		x=strlen(s);
		for (int j=0;j<x;j++)
		{
			if (s[j]>='A' && s[j]<='F') cur=10+s[j]-'A';
			else cur=s[j]-'0';
			for (int k=0;k<4;k++)
			{
				mp[i][j*4+k+1]=(bool)(cur&(1<<(3-k)));
			} 
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+mp[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (n%i==0)
		{
			bool f=0;
			for (int j=i;j<=n;j+=i)
			{
				for (int k=i;k<=n;k+=i)
				{
					cur=sum[j][k]-sum[j-i][k]-sum[j][k-i]+sum[j-i][k-i];
					if (cur!=i*i && cur)
					{
						f=1;
						break;
					}
				}
				if (f) break;
			}
			if (!f) ans=i;
		}
	}
	printf("%d\n",ans);
	return Accepted;
}