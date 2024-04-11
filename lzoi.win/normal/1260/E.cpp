#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1<<20;
typedef long long ll;
int n,a[MAXN];
ll f[MAXN][20],g[20],ans;
int main(){
	scanf("%d",&n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),f[i][0]=0;
	for(int i=n;i;i--)
		if(a[i]==-1||i<n&&!a[i+1]) a[i]=0;
	memcpy(g,f[1],sizeof(g));
	for(int i=2;i<=n;i++){
		for(int j=1;1<<j<=i;j++){/*
			for(int k=1;k<i;k++){
				f[i][j]=min(f[i][j],f[k][j]);
				f[i][j]=min(f[i][j],f[k][j-1]+a[i]);
			}*/
			f[i][j]=min(g[j],g[j-1]+a[i]);
			if(i==n&&1<<j==i) ans=f[i][j];
		}
		for(int j=1;1<<j<=i;j++)
			g[j]=min(g[j],f[i][j]);
	}
	printf("%I64d\n",ans);
	return 0;
}