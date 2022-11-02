#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1))%mod;
}

ll inv(ll x){
	return pot(x, mod-2);
}

ll geom(ll a, ll q){
	a%=mod;
	q%=mod;
	return (a*inv(mod+1-q))%mod;
}

ll dp[1010][2020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	ll a,b;
	cin>>k>>a>>b;
	ll pa=(a*inv(a+b))%mod;
	ll pb=(b*inv(a+b))%mod;
// 	cout<<pa<<" "<<pb<<endl;
	dp[0][0]=geom(pb, pb);
	dp[1][0]=pa;
	for (int i=0;i<k;i++){
		for (int j=0;j<k;j++){
// 			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			
			dp[i+1][j]+=dp[i][j]*pa;
			dp[i+1][j]%=mod;
			
			if (i>0){
				dp[i][i+j]+=dp[i][j]*pb;
				dp[i][i+j]%=mod;
			}
		}
	}
	ll v=0;
	for (int i=0;i<=k;i++){
		for (int j=k;j<=2*k;j++){
// 			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			v+=dp[i][j]*(ll)j;
			v%=mod;
		}
	}
	for (int i=0;i<k;i++){
		ll t=dp[k][i];
// 		cout<<i<<" "<<dp[k][i]<<endl;
		v+=((ll)(k+i)+geom(pa, pa))*t;
		v%=mod;
	}
	cout<<v<<endl;
}