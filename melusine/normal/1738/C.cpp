#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int f[1005][1005][2];
int a[1005];
int main()
{
	f[0][0][0]=1;
	f[0][0][1]=0;
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(i==0&&j==0)continue;
			if(i>0)
			{
				if((i-1)%2==0&&f[i-1][j][0]==0)f[i][j][0]=1;
				if((i-1)%2==0&&f[i-1][j][1]==0)f[i][j][1]=1;
				if((i-1)%2==1&&f[i-1][j][0]==0)f[i][j][1]=1;
				if((i-1)%2==1&&f[i-1][j][1]==0)f[i][j][0]=1;
			}
			if(j>0)
			{
				if((i)%2==0&&f[i][j-1][0]==0)f[i][j][1]=1;
				if((i)%2==0&&f[i][j-1][1]==0)f[i][j][0]=1;
				if((i)%2==1&&f[i][j-1][0]==0)f[i][j][0]=1;
				if((i)%2==1&&f[i][j-1][1]==0)f[i][j][1]=1;
			}
			//if(f[i][j][0]==0)printf("%d %d\n",i,j);
		}
	}
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		k=0;
		for(int i=1;i<=n;i++)if(a[i]%2!=0)k++;
		if(f[k][n-k][0]==0)printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}