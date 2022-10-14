#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=405;
int n,MOD,f[N][N];
void add(int&x,int y){
	x=(x+y)%MOD;
}
signed main(){
	cin>>n>>MOD,f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i+1;j++){
			add(f[i][j],f[i-1][j-1]*j%MOD);
			add(f[i][j],f[i-1][j]*j*2%MOD);
			if(i>1)add(f[i][j],f[i-2][j]*j*2%MOD);
			if(i>1)add(f[i][j],f[i-2][j+1]*j*2%MOD);
			if(i>2)add(f[i][j],f[i-3][j+1]*j%MOD);
		}
	cout<<f[n][1]<<"\n";
}