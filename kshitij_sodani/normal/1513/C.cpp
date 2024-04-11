//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo dp[11][200010];
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(llo i=0;i<=200000;i++){
		for(llo j=0;j<10;j++){
			if(i==0){
				dp[j][i]=1;
				continue;
			}
			if(j<9){
				dp[j][i]=dp[j+1][i-1];
			}
			else{
				dp[j][i]=dp[1][i-1]+dp[0][i-1];
				if(dp[j][i]>=mod){
					dp[j][i]-=mod;
				}
			}
		}
	}

	llo t;
	cin>>t;

	while(t--){
		llo n,m;
		cin>>n>>m;
		llo ans=0;
		while(n){
			llo ss=n%10;
			n/=10;
			ans=(ans+dp[ss][m]);
			if(ans>=mod){
				ans-=mod;
			}
		}
		cout<<ans<<endl;
	}



 
 
	return 0;
}