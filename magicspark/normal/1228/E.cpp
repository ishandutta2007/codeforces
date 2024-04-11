#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
typedef long long ll;

int n,k;
int dp[255][255];
int pwk[255],pwk1[255];
int C[255][255];


void solve(int x){
	for(int i=0;i<=n;i++){
		for(int add=0;add+i<=n;add++){
			int now=(pwk[i]-(add==0?pwk1[i]:0ll)+mod)*C[n-i][add]%mod*pwk1[n-i-add]%mod;
			dp[x+1][i+add]+=dp[x][i]*now;
			dp[x+1][i+add]%=mod;
		}
	}
}

signed main(){
	cin>>n>>k;
	pwk[0]=1;pwk1[0]=1;
	for(int i=1;i<=255;i++){
		pwk[i]=pwk[i-1]*k%mod;
		pwk1[i]=pwk1[i-1]*(k-1)%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=250;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]%=mod;
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n+1;i++){
		solve(i-1);
	}
	cout<<dp[n][n]<<endl;
	return 0;
}