#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,ans=INF,a[N],c[N][N],f[N][N][N];
void tomin(int&x,int y){
	if(x>y)x=y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=1;j<=m;j++)
				f[i][j][1]=a[i]?INF*(j!=a[i]):c[i][j];
			continue;
		}
		if(a[i]){
			for(int j=1;j<=m;j++)
				for(int t=1;t<=k;t++)
					tomin(f[i][a[i]][t],f[i-1][j][t-(j!=a[i])]);
		}else{
			for(int j=1;j<=m;j++)
				for(int t=1;t<=k;t++)
					for(int p=1;p<=m;p++)
						tomin(f[i][j][t],f[i-1][p][t-(j!=p)]+c[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
		tomin(ans,f[n][i][k]);
	cout<<(ans<INF?ans:-1)<<"\n";
}