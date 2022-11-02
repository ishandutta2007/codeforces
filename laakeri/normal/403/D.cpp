#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[55][1010];
ll v[55][1010];
ll ke[55];

ll bin[2020][2020];

void cv(int k, int n){
	int rs=n-k;
	if (rs<0) return;
	for (int i=0;i<=rs;i++){
		v[k][n]+=bin[k+rs-i][k]*dp[k][i];
		v[k][n]%=mod;
	}
	v[k][n]*=ke[k];
	v[k][n]%=mod;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bin[0][0]=1;
	for (int i=1;i<=2000;i++){
		bin[i][0]=1;
		for (int j=1;j<=2000;j++){
			bin[i][j]=bin[i-1][j-1]+bin[i-1][j];
			bin[i][j]%=mod;
		}
	}
	dp[0][0]=1;
	for (int t=0;t<=1000;t++){
		for (int j=50;j>0;j--){
			for (int i=1000;i-t>=0;i--){
				dp[j][i]+=dp[j-1][i-t];
				dp[j][i]%=mod;
			}
		}
	}
	ke[0]=1;
	for (ll i=1;i<=50;i++){
		ke[i]=ke[i-1]*i;
		ke[i]%=mod;
	}
	for (int i=1;i<=50;i++){
		for (int j=1;j<=1000;j++){
			cv(i, j);
		}
	}
	int q;
	cin>>q;
	for (int i=0;i<q;i++){
		int n,k;
		cin>>n>>k;
		if (k>50) cout<<0<<'\n';
		else cout<<v[k][n]<<'\n';
	}
}