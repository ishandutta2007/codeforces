#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233,INF=0x3f3f3f3f3f3f3f3fll;
int t,n,m,a[N][N],f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int ans=INF;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				for(int x=1;x<=n;x++)
					for(int y=1;y<=m;y++)
						f[x][y]=(x>1||y>1)*INF;
				for(int x=1;x<=n;x++)
					for(int y=1;y<=m;y++){
						int k=a[i][j]-i-j+x+y;
						if(a[x][y]<k){f[x][y]=INF;continue;}
						f[x][y]+=a[x][y]-k;
						if(x<n)f[x+1][y]=min(f[x+1][y],f[x][y]);
						if(y<m)f[x][y+1]=min(f[x][y+1],f[x][y]);
					}
				ans=min(ans,f[n][m]);
			}
		cout<<ans<<"\n";
	} 
}