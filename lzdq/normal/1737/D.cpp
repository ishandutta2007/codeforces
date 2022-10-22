#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=505,MAXM=250005,Inf=0x3fffffff;
const ll INF=1ll<<60;
int n,m,ed[MAXM][3];
int dep[MAXN][MAXN];
ll ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				dep[i][j]=Inf;
			dep[i][i]=0;
		}
		for(int i=1; i<=m; i++){
			scanf("%d%d%d",ed[i],ed[i]+1,ed[i]+2);
			int u=ed[i][0],v=ed[i][1];
			dep[u][v]=dep[v][u]=1;
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					dep[i][j]=min(dep[i][j],dep[i][k]+dep[k][j]);
		ans=INF;
		for(int i=1; i<=m; i++){
			int u=ed[i][0],v=ed[i][1],d=min(dep[1][u]+dep[v][n],dep[1][v]+dep[u][n])+1;
			for(int p=1; p<=n; p++)
				d=min(d,dep[1][p]+dep[p][n]+min(dep[p][u],dep[p][v])+2);
			ans=min(ans,1ll*d*ed[i][2]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}