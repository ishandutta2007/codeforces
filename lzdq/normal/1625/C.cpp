#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=505,INF=0x3fffffff;
int n,l,k;
int d[MAXN],a[MAXN];
int f[MAXN][MAXN],ans;
int main(){
	scanf("%d%d%d",&n,&l,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",d+i);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	d[++n]=l;
	memset(f,0x3f,sizeof(f));
	f[1][k]=0;
	for(int i=1; i<n; i++)
		for(int j=0; j<=k; j++){
			int t=j;
			for(int x=i+1; x<=n&&t>=0; x++,t--)
				f[x][t]=min(f[x][t],f[i][j]+(d[x]-d[i])*a[i]);
		}
	ans=INF;
	for(int i=0; i<=k; i++)
		ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}