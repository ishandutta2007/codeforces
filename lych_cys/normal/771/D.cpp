#include<bits/stdc++.h>
#define N 105
#define dn(x,y) ((x>(y))?x=(y):0)
using namespace std;

int n,a[3][N],p[3],dp[N][N][N][3]; char s[N];
int calc(int x,int y,int z,int k){
	int i,ans=0;
	for (i=1; i<=x; i++) ans+=(a[0][i]>k);
	for (i=1; i<=y; i++) ans+=(a[1][i]>k);
	for (i=1; i<=z; i++) ans+=(a[2][i]>k);
	return ans;
}
int main(){
	scanf("%d%s",&n,s+1);
	int i,l,x,y,z;
	for (i=1; i<=n; i++){
		if (s[i]=='V') a[0][++p[0]]=i; else
		if (s[i]=='K') a[1][++p[1]]=i; else a[2][++p[2]]=i;
	}
	memset(dp,60,sizeof(dp));
	dp[0][0][0][1]=0;
	for (i=1; i<=n; i++)
		for (x=0; x<=p[0]; x++)
			for (y=0; y<=p[1]; y++)
				for (l=0; l<2; l++){
					z=i-1-x-y; if (z<0 || z>p[2]) continue;
					if (x<p[0]) dn(dp[i][x+1][y][0],dp[i-1][x][y][l]+calc(x,y,z,a[0][x+1]));
					if (y<p[1] && l) dn(dp[i][x][y+1][1],dp[i-1][x][y][l]+calc(x,y,z,a[1][y+1]));
					if (z<p[2]) dn(dp[i][x][y][1],dp[i-1][x][y][l]+calc(x,y,z,a[2][z+1]));
				}
	printf("%d\n",min(dp[n][p[0]][p[1]][0],dp[n][p[0]][p[1]][1]));
	return 0;
}