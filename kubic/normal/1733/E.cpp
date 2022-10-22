#include <bits/stdc++.h>
using namespace std;
#define N 205
#define ll long long
int T,n,m,x,y;ll c,z[N][N];
void slv()
{
	scanf("%lld %d %d",&c,&n,&m);c-=n+m;
	if(c<0) {printf("NO\n");return;}
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j)
		z[i][j]=0;z[0][0]=c;
	for(int i=0;i<=n;++i) for(int j=0;j<=m;++j)
	{
		ll t=z[i][j];z[i+1][j]+=t/2;
		z[i][j+1]+=(t+1)/2;z[i][j]=t&1;
	}x=y=0;
	while(x<=n && y<=m && x+y<n+m)
		if(z[x][y]) ++x;else ++y;
	if(x==n && y==m) printf("YES\n");
	else printf("NO\n");
		
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}