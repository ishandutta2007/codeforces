#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath> 
using namespace std;
int Abs(int x){return x>0?x:-x;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int g[1001][1001];bool ok=0;int n;
void zh()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		if(i==j)continue;
		g[i][j]^=1;
	}
}
int main()
{
	int a,b;scanf("%d%d%d",&n,&a,&b);
	if(a<b)swap(a,b),ok=1;
	if(n==1)
	{
		puts("YES");
		puts("0");
		return 0;
	}
	if(n==2)
	{
		if(a==2&&b==1)
		{
			puts("YES");
			if(ok)zh();
			for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
			{
				printf("%d",g[i][j]);
			}
			return 0;
		}
		puts("NO");return 0;
	}
	if(n==3)
	{
		if(a==3&&b==1)
		{
			puts("YES");
			if(ok)zh();
			for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
			{
				printf("%d",g[i][j]);
			}
			return 0;
		}
		if(a==2&&b==1)
		{
			g[1][2]=g[2][1]=1;
			puts("YES");
			if(ok)zh();
			for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=n;j++)
			{
				printf("%d",g[i][j]);
			}
			return 0;
		}puts("NO");return 0;
	}
	if(a>1&&b>1)return 0*puts("NO");
	for(int i=1;i<=n-a;i++)
	{
		g[i][i+1]=g[i+1][i]=1;
	}
	puts("YES");
		if(ok)zh();
		for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
		{
			printf("%d",g[i][j]);
		}
		return 0;
}