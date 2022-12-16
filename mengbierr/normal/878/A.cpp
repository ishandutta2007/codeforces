#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int op[500005],num[500005][15],n;
int ans[15][3],final[15][5];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		char s[15];
		scanf("%s",s+1);
		if(s[1]=='&') op[i]=1;
		else if(s[1]=='|') op[i]=2;
		else op[i]=3;
		int x=read();
		for(int j=0;j<=9;j++)
		{
			num[i][j]=x&1;
			x>>=1;
		}
	}
	for(int i=0;i<=9;i++)
	ans[i][1]=1;
	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(op[j]==1)
				ans[i][k]=ans[i][k]&num[j][i];
				else if(op[j]==2)
				ans[i][k]=ans[i][k]|num[j][i];
				else ans[i][k]=ans[i][k]^num[j][i];
			}
		}
	}
	printf("3\n");
	for(int i=0;i<=9;i++)
	{
		if(ans[i][0]==0&&ans[i][1]==0);
		else if(ans[i][0]==1&&ans[i][1]==1)
		{
			final[i][1]=1;final[i][2]=1;
		}
		else if(ans[i][0]==1&&ans[i][1]==0)
		{
			final[i][1]=1;final[i][3]=1;
		}
		else
		{
			final[i][1]=1;
		}
	}
	for(int i=1;i<=3;i++)
	{
		int temp=0;
		for(int j=9;j>=0;j--)
		{
			temp=temp*2+final[j][i];
		}
		if(i==1) printf("& ");
		else if(i==2) printf("| ");
		else printf("^ ");
		printf("%d\n",temp);
	}
}