#include<iostream>
#include<cstdio>
#define XXX {puts("No");return 0;}
using namespace std;
int n,m,a[105][105],b[105][105];bool flag;
bool pd(int x,int y)
{
	int x1,y1;
	for (x1=x;a[x1][y]==4;x1++);x1--;
	for (y1=y;a[x][y1]==4;y1++);y1--;
	for (int i=x;i<=x1;i++)
		for (int j=y;j<=y1;j++)
		{
			if (a[i][j]!=4) return 0;
			b[i][j]=-1;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if ((!(a[i][j]==4&&b[i][j]==-1))&&(
			(b[i-1][j-1]||b[i][j-1]||b[i-1][j])+
			(b[i-1][j+1]||b[i][j+1]||b[i-1][j])+
			(b[i+1][j-1]||b[i][j-1]||b[i+1][j])+
			(b[i+1][j+1]||b[i][j+1]||b[i+1][j])!=a[i][j])) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char c=getchar();
			while(c<'0'||c>'9')c=getchar();
			a[i][j]=c-'0';
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]==4)
			{
				if (!pd(i,j))XXX
				else{puts("Yes");return 0;}
			}
	XXX
	return 0;
}