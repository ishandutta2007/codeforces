#include<bits/stdc++.h>
using namespace std;
int const N=105;
int n,ans,f[N][N][5][5];
vector<array<int,3> >a;
int main(){
	ios::sync_with_stdio(0);
	cin>>n,a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	memset(f,0xcc,sizeof f);
	for(int i=1;i<=n;i++){
		int x=a[i-1][0],k=a[i-1][1],y=a[i-1][2];
		f[i][i][x][y]=f[i][i][y][x]=k;
	}
	for(int d=2;d<=n;d++)
		for(int l=1;l<=n-d+1;l++)
			for(int a=1;a<=4;a++)
				for(int b=1;b<=4;b++)
					for(int p=l;p<l+d-1;p++){
						int r=l+d-1;
						f[l][r][a][b]=max(f[l][r][a][b],
							max(f[l][p][a][b],f[p+1][r][a][b]));
						for(int c=1;c<=4;c++)
							f[l][r][a][b]=max(f[l][r][a][b],
								f[l][p][a][c]+f[p+1][r][c][b]);
						f[l][r][a][b]=f[l][r][b][a]=
							max(f[l][r][a][b],f[l][r][b][a]);
					}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			ans=max(ans,f[1][n][i][j]);
	cout<<ans<<"\n";
}