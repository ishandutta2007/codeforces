#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=5005;
int T,n,p[N],f[N][N],g[N][N];ll ans;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)g[n+1][i]=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=f[i-1][j];
		for(int j=p[i];j<=n;j++)f[i][j]++;
	}
	for(int i=n;i;i--){
		for(int j=1;j<=n;j++)g[i][j]=g[i+1][j];
		for(int j=p[i];j<=n;j++)g[i][j]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)ans+=f[i-1][p[j]]*g[j+1][p[i]];
	printf("%llu\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}