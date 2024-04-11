#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=205;
const ll INF=1ll<<60;
typedef pair<ll,int> pr;
#define mkp make_pair
int n,c[MAXN][MAXN];
ll s[MAXN][MAXN];
pr f[MAXN][MAXN];
ll g[MAXN][MAXN];
int fa[MAXN];
int Dfs(int l,int r){
	if(l>r) return 0;
	int u=f[l][r].second;
	fa[Dfs(l,u-1)]=u;
	fa[Dfs(u+1,r)]=u;
	return u;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			scanf("%d",c[i]+j);
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c[i][j];
		}
	for(int i=n; i; i--)
		for(int j=i; j<=n; j++){
			f[i][j]=mkp(INF,0);
			for(int k=i; k<=j; k++)
				f[i][j]=min(f[i][j],mkp(g[i][k-1]+g[k+1][j],k));
			g[i][j]=f[i][j].first+s[j][i-1]-s[i-1][i-1]+s[j][n]-s[j][j]-s[i-1][n]+s[i-1][j];
		}
	Dfs(1,n);
	for(int i=1; i<=n; i++)
		printf("%d ",fa[i]);
	puts("");
	return 0;
}