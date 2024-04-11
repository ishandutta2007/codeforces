#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=405,INF=0x3fffffff;
int n,m;
char s[MAXN];
int a[MAXN][MAXN],b[MAXN][MAXN];
int f[MAXN][MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			scanf("%s",s+1);
			for(int j=1; j<=m; j++)
				a[i][j]=s[j]-'0',b[i][j]=b[i][j-1]+a[i][j];
		}
		for(int i=1; i<=m; i++)
			for(int j=i+3; j<=m; j++)
				f[i][j]=INF;
		int ans=INF;
		for(int i=4; i<=n; i++)
			for(int j=1; j<=m; j++)
				for(int k=j+3; k<=m; k++){
					ans=min(ans,f[j][k]+k-j-1-b[i][k-1]+b[i][j]);
					//printf("%d %d %d ans %d\n",i,j,k,f[j][k]);
					f[j][k]=min(f[j][k]+b[i][k-1]-b[i][j]+2-a[i][j]-a[i][k],k-j-1-b[i-3][k-1]+b[i-3][j]+6-a[i-2][j]-a[i-2][k]-a[i-1][j]-a[i-1][k]-a[i][j]-a[i][k]+b[i-2][k-1]-b[i-2][j]+b[i-1][k-1]-b[i-1][j]+b[i][k-1]-b[i][j]);
				}
		printf("%d\n",ans);
	}
	return 0;
}