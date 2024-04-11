#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=505,INF=0x3fffffff;
const int DIRE[2][4]={
	{1,-1,0,0},
	{0,0,-1,1}
	// swad
};
int n,m,k,a[MAXN][MAXN],w[MAXN][MAXN][4];
int f[MAXN][MAXN][11];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++)
				printf("-1 ");
			puts("");
		}
		return 0;
	}
	k/=2;
	for(int i=1; i<=n; i++)
		for(int j=1; j<m; j++)
			scanf("%d",w[i][j]+3),w[i][j+1][2]=w[i][j][3];
	for(int i=1; i<n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",w[i][j]),w[i+1][j][1]=w[i][j][0];
	for(int l=1; l<=k; l++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++){
				f[i][j][l]=INF;
				for(int d=0; d<4; d++){
					int nx=i+DIRE[0][d],ny=j+DIRE[1][d];
					if(nx>0&&nx<=n&&ny>0&&ny<=m) f[i][j][l]=min(f[i][j][l],f[nx][ny][l-1]+w[i][j][d]);
				}
			}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)
			printf("%d ",f[i][j][k]*2);
		puts("");
	}
	return 0;
}