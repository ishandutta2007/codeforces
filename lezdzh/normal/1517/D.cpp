#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct ed{int v,c;};
vector<ed>g[250001];
int f[250001][11];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++){
			int c;
			scanf("%d",&c);
			g[(i-1)*m+j].push_back((ed){(i-1)*m+j+1,c});
			g[(i-1)*m+j+1].push_back((ed){(i-1)*m+j,c});
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++){
			int c;
			scanf("%d",&c);
			g[(i-1)*m+j].push_back((ed){i*m+j,c});
			g[i*m+j].push_back((ed){(i-1)*m+j,c});
		}
	if(k%2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("%d%c",-1,j==m?'\n':' ');
		return 0;
	}
	for(int i=1;i<=n*m;i++)
		for(int j=1;j<=k/2;j++)
			f[i][j]=2e9;
	for(int j=1;j<=k/2;j++)
		for(int i=1;i<=n*m;i++)
			for(int w=0;w<g[i].size();w++)
				f[i][j]=min(f[i][j],f[g[i][w].v][j-1]+g[i][w].c);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			printf("%d%c",2*f[(i-1)*m+j][k/2],j==m?'\n':' ');
}