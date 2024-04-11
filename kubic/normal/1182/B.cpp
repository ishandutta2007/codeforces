#include <bits/stdc++.h>
using namespace std;
#define N 505
int n,m,sX,sY;char a[N][N];bool vs[N][N];
int main()
{
	scanf("%d %d",&n,&m);for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
		if(a[i][j]=='*' && a[i-1][j]=='*' && a[i+1][j]=='*' && a[i][j-1]=='*' && a[i][j+1]=='*')
		{
			if(sX) {puts("NO");return 0;}
			sX=i;sY=j;
		}
	if(!sX) {puts("NO");return 0;}
	for(int i=sX;i>=1 && a[i][sY]=='*';--i) vs[i][sY]=1;
	for(int i=sX;i<=n && a[i][sY]=='*';++i) vs[i][sY]=1;
	for(int i=sY;i>=1 && a[sX][i]=='*';--i) vs[sX][i]=1;
	for(int i=sY;i<=m && a[sX][i]=='*';++i) vs[sX][i]=1;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]=='*' && !vs[i][j]) {puts("NO");return 0;}
	puts("YES");
}