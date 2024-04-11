#include<bits/stdc++.h>
using namespace std;
int n,a,b;
const int N=2048;
unsigned dp[N][N];
unsigned f[N],g[N],h[N];
inline void update(unsigned &x,const unsigned &y){if(y>x)x=y;return;}
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d.%d",&x,&y);
		f[i]=x*1000+y;
	}
	for(int i=1;i<=n;i++){
		int x,y;scanf("%d.%d",&x,&y);
		g[i]=x*1000+y;
		h[i]=1000000-(1000-f[i])*(1000-g[i]);
		f[i]*=1000;g[i]*=1000;
	}
	memset(dp,0,sizeof dp);dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int x=min(i,a);x>a-(n-i)-2&&x>0;x--)for(int y=min(i,b);y>b-(n-i)-2&&y>0;y--){
			update(dp[x][y],dp[x-1][y-1]+h[i]);
			update(dp[x][y],dp[x-1][y]+f[i]);
			update(dp[x][y],dp[x][y-1]+g[i]);
		}
		for(int x=min(i,a);x>0;x--)update(dp[x][0],dp[x-1][0]+f[i]);
		for(int x=min(i,b);x>0;x--)update(dp[0][x],dp[0][x-1]+g[i]);
	}
	printf("%.12lf\n",1.0*dp[a][b]/1e6);
	return 0;
}