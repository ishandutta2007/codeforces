#include <bits/stdc++.h>
using namespace std;
#define N 505
int n,m,q,L,R,ans,c[N][N][4],s[N][N][N>>1];char a[N][N];
int min(int x,int y) {return x<y?x:y;} 
int f(char x)
{
	if(x=='G') return 0;if(x=='Y') return 1;
	if(x=='R') return 2;if(x=='B') return 3;return -1;
}
bool chk(int x,int x1,int y1,int x2,int y2)
{
	if(!x) return 1;
	return s[x2][y2][x]-s[x1+(x<<1)-2][y2][x]-s[x2][y1+(x<<1)-2][x]+s[x1+(x<<1)-2][y1+(x<<1)-2][x];
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1,t;i<=n;++i) for(int j=1;j<=m;++j)
	{
		t=f(a[i][j]);
		c[i][j][t]=min(min(c[i-1][j][t],c[i][j-1][t]),c[i-1][j-1][t])+1;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) for(int k=1;k<=min(i>>1,j>>1);++k)
	{
		s[i][j][k]=s[i-1][j][k]+s[i][j-1][k]-s[i-1][j-1][k];
		if(c[i][j][3]>=k && c[i-k][j][0]>=k && c[i][j-k][1]>=k && c[i-k][j-k][2]>=k)
			++s[i][j][k];
	}
	for(int i=1,x1,y1,x2,y2;i<=q;++i)
	{
		ans=0;scanf("%d %d %d %d",&x1,&y1,&x2,&y2);L=0;R=min(x2-x1+1>>1,y2-y1+1>>1);
		while(L<=R) {int mid=L+R>>1;if(chk(mid,x1,y1,x2,y2)) ans=mid,L=mid+1;else R=mid-1;}
		printf("%d\n",ans*ans<<2);
	}
}