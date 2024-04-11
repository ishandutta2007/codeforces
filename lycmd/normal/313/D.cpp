#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=305,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,k,v[N][N],f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	memset(v,0x3f,sizeof v);
	memset(f,0x3f,sizeof f),f[0][0]=0;
	for(int l,r,w;m--;)
		cin>>l>>r>>w,v[l][r]=min(v[l][r],w);
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			for(int p=l;p<r;p++)
				v[l][r]=min(v[l][r],v[l][p]+v[p+1][r]);
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;j--){
			f[i][j]=min(f[i-1][j],f[i][j+1]);
			for(int p=i-j+1;p<=i;p++)
				f[i][j]=min(f[i][j],f[p-1][j-i+p-1]+v[p][i]),
				f[p-1][j-i+p-1]=min(f[p-1][j-i+p-1],f[i][j]);
		}
	cout<<(f[n][k]<INF?f[n][k]:-1)<<"\n";
}