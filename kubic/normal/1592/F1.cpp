#include <bits/stdc++.h>
using namespace std;
#define N 505
int n,m,ans,w,w1,w2,a[N][N];char a1[N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{scanf("%s",a1+1);for(int j=1;j<=m;++j) a[i][j]=a1[j]=='B';}
	for(int i=n;i;--i) for(int j=m;j;--j)
		a[i][j]=a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
	for(int i=2;i<=n;++i) for(int j=2;j<=m;++j)
		if(a[i][j]) ++w,a[1][1]^=1,a[i][1]^=1,a[1][j]^=1;
	for(int i=2;i<=n;++i) if(a[i][1]) ++w1,a[1][1]^=1;
	for(int i=2;i<=m;++i) if(a[1][i]) ++w2,a[1][1]^=1;
	ans=w+w1+w2+a[1][1];
	for(int i=2;i<=n;++i) for(int j=2;j<=m;++j)
		if(a[1][1] && a[i][1] && a[1][j] && a[i][j])
		{printf("%d\n",ans-1);return 0;}
	printf("%d\n",ans);return 0;
}