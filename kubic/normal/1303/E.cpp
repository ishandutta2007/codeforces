#include <bits/stdc++.h>
using namespace std;
#define N 405
#define M 26
#define INF 0x3f3f3f3f
#define set(a,v) memset(a,v,sizeof(a))
int T,n,m,ps[N][M],dp[N][N];bool fl;char a[N],b[N];
int min(int x,int y) {return x<y?x:y;} 
bool chk(int x)
{
	set(dp,0);
	for(int i=0;i<=x;++i) for(int j=0;j<=m-x;++j)
	{
		dp[i][j]=INF;if(!i && !j) dp[i][j]=0;
		if(i && dp[i-1][j]<INF && ps[dp[i-1][j]][b[i]-'a'])
			dp[i][j]=ps[dp[i-1][j]][b[i]-'a'];
		if(j && dp[i][j-1]<INF && ps[dp[i][j-1]][b[j+x]-'a'])
			dp[i][j]=min(dp[i][j],ps[dp[i][j-1]][b[j+x]-'a']);
	}return dp[x][m-x]<INF;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{ 
		fl=0;set(ps,0);scanf("%s %s",a+1,b+1);n=strlen(a+1);m=strlen(b+1);
		for(int i=n-1;i>=0;--i)
		{
			ps[i][a[i+1]-'a']=i+1;
			for(int j=0;j<26;++j) if(j!=a[i+1]-'a') ps[i][j]=ps[i+1][j];
		}for(int i=1;i<m;++i) if(chk(i)) {fl=1;puts("YES");break;}
		if(fl) continue;if(m>1) {puts("NO");continue;}
		for(int i=1;i<=n;++i) if(a[i]==b[1]) {fl=1;puts("YES");break;}if(!fl) puts("NO");
	}
}