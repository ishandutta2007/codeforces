#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=305,MOD=1000000007;
int n,a[N],f[2][N][N];
void add(int&x,int y){
	x=(x+y%MOD+MOD)%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=2;j*j<=a[i];j++)
			while(a[i]%(j*j)==0)
				a[i]/=j*j;
	}
	sort(a+1,a+1+n),f[0][0][0]=1;
	int pre=0;
	for(int i=1;i<=n;i++){
		memset(f[i&1],0,sizeof f[i&1]);
		if(a[i]^a[i-1]){
			for(int j=0;j<=i;j++)
				for(int k=1;k<=pre;k++)
					add(f[~i&1][j][0],f[~i&1][j][k]),f[~i&1][j][k]=0;
			pre=0;
		}
		for(int j=0;j<=i;j++)
			for(int k=0;k<=min(pre,j);k++)
				add(f[i&1][j][k],(j&&k)*f[~i&1][j-1][k-1]*(2*pre-k+1)),
				add(f[i&1][j][k],f[~i&1][j+1][k]*(j+1-k)),
				add(f[i&1][j][k],f[~i&1][j][k]*(i-j-2*pre+2*k));
		pre++;
	}
	cout<<f[n&1][0][0]<<"\n";
}