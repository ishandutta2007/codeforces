#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=505,M=23;
int n,m,k,a[N][N],b[N][N],f[M][N][N];
void tomin(int&x,int y){
	if(x>y)x=y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	if(k&1){
		for(int i=1;i<=n;i++,cout<<"\n")
			for(int j=1;j<=m;j++)
				cout<<"-1 ";
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			cin>>a[i][j];
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<=k/2;i++){
		memset(f[i],0x3f,sizeof f[i]);
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++){
				if(x>1)tomin(f[i][x][y],f[i-1][x-1][y]+b[x-1][y]);
				if(x<n)tomin(f[i][x][y],f[i-1][x+1][y]+b[x][y]);
				if(y>1)tomin(f[i][x][y],f[i-1][x][y-1]+a[x][y-1]);
				if(y<m)tomin(f[i][x][y],f[i-1][x][y+1]+a[x][y]);
			}
	}
	for(int i=1;i<=n;i++,cout<<"\n")
		for(int j=1;j<=m;j++)
			cout<<f[k/2][i][j]*2<<" ";
}