#include<cstdio>
#include<algorithm>
using namespace std;
const int N=600002;
typedef long long ll;
int n,m,i,j,k,id[2][100],cnt[N],u,v;
int x[N],y[N],d[N];
ll a[N],f[200][200],D[200][200],ans=1<<30;
ll min(ll x,ll y){
	return x<y?x:y;
}
bool cmp(int u,int v){
	return x[u]<x[v];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d",a+i);
		for(j=0;j<63;j++)
			if(a[i]>>j&1){
				cnt[j]++;
				if(cnt[j]>=3){
					printf("3");
					return 0;
				}
				id[cnt[j]-1][j]=i;
			}
	}
	for(i=0;i<63;i++)
		if(id[0][i]&&id[1][i]){
			x[++m]=id[0][i];
			d[m]=m;
			x[++m]=id[1][i];
			d[m]=m;
		}
	sort(d+1,d+m+1,cmp);
	for(i=1;i<=m;i++)
		y[d[i]]=y[d[i-1]]+(x[d[i]]!=x[d[i-1]]);
	n=y[d[m]];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=1ll<<50,D[i][j]=1ll<<50;
	for(i=1;i<=m;i+=2){
		u=y[i];v=y[i+1];
		f[u][v]=min(f[u][v],1);
		f[v][u]=min(f[v][u],1);
		D[u][v]=min(D[u][v],1);
		D[v][u]=min(D[v][u],1);
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(i!=k&&k!=j&&i!=j)
				ans=min(ans,D[i][k]+D[j][k]+f[i][j]);
				f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
			}
	if(ans==1<<30)
		printf("-1");
	else
		printf("%lld",ans);
	//while(1);
	return 0;
}