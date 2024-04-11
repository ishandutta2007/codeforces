#include <bits/stdc++.h>
using namespace std;
#define N 505
int T,n,m;char a[N][N];
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=n%3?1:2;i<=n;i+=3)
	{
		for(int j=1;j<=m;++j) a[i][j]='X';
		if(i<n-1) for(int j=1;j<=n;++j)
		{
			if(a[i+1][j]=='X') {a[i+2][j]='X';break;}
			if(a[i+2][j]=='X') {a[i+1][j]='X';break;}
			if(j==n) a[i+1][1]=a[i+2][1]='X';
		}
	}
	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=m;++j)
		putchar(a[i][j]);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}