#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,M=105,MOD=1000000007;
int n,m,a[N],f[N][M],C[N][M];
void add(int&x,int y){
	x=(x+y%MOD+MOD)%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		for(int j=0;j<min(i+1,M);j++)
			C[i][j]=j?(C[i-1][j-1]+C[i-1][j])%MOD:1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l,r,k;m--;){
		cin>>l>>r>>k;
		for(int i=0;i<=k;i++)
			add(f[l][i],C[k][i]),
			add(f[r+1][i],-C[r-l+1+k][k-i]);
	} 
	for(int i=2;i<=n;i++)
		for(int j=M-1;j;j--)
			add(f[i][j-1],f[i-1][j]+f[i-1][j-1]);
	for(int i=1;i<=n;i++)
		add(a[i],f[i][0]),cout<<a[i]<<" ";
	cout<<"\n";
}