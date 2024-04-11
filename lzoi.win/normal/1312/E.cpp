#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=505;
int f[MAXN][MAXN];
int g[MAXN];
int main() {
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i][i]);
	for(int i=1;i<n;i++) 
		for(int j=1;j+i<=n;j++) {
			int x=j,y=j+i;
			for(int k=x;k<y;k++) {
				if(f[x][k]==f[k+1][y]&&f[x][k])
					f[x][y]=f[x][k]+1;
			}
		}
	for(int i=1; i<=n; i++){
		g[i]=g[i-1]+1;
		for(int j=1;j<i;j++)
			if(f[j][i]) g[i]=min(g[i],g[j-1]+1);
	}
	printf("%d\n",g[n]);
	return 0;
}