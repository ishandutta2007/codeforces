#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int n;
char s[5205];
int mp[5205][5205],sum[5205][5205];
int getsum(int x1,int yy1,int x2,int y2)
{
	return sum[x2][y2]+sum[x1-1][yy1-1]-sum[x2][yy1-1]-sum[x1-1][y2];
}
bool check(int x)
{
	for(int i=1;i<=n/x;i++)
	{
		for(int j=1;j<=n/x;j++)
		{
			if(getsum((i-1)*x+1,(j-1)*x+1,i*x,j*x)!=0&&getsum((i-1)*x+1,(j-1)*x+1,i*x,j*x)!=x*x)
			return 0;
		}
	}
	return 1;
}
int main()
{
	n=read();
	for(int ii=1;ii<=n;ii++)
	{
		scanf("%s",s+1);
		int len=n/4;
		for(int i=1;i<=len;i++)
		{
			int temp;
			if(s[i]>='0'&&s[i]<='9') temp=s[i]-'0';
			else temp=s[i]-'A'+10;
			for(int j=4;j;j--)
			{
				mp[ii][4*(i-1)+j]=temp&1;temp>>=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
		}
	}
	for(int i=n;i;i--)
	{
		if(n%i) continue;
		if(check(i))
		{
			cout<<i;
			return 0;
		}
	}
}