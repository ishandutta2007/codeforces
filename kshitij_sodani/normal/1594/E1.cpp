//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo dp[61][6];
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<6;i++){
		dp[0][i]=1;
	}
	for(llo i=1;i<n;i++){
		for(llo j=0;j<6;j++){
			for(llo l=0;l<6;l++){
				for(llo m=0;m<6;m++){
					if(j==l or j==m ){
						continue;
					}
					if((j^1)==l or (j^1)==m){
						continue;
					}
					dp[i][j]=(dp[i][j]+dp[i-1][l]*dp[i-1][m])%mod;
				}
			}
		}
	}
	llo ans=6*(dp[n-1][0])%mod;
	cout<<ans<<endl;


 
 
 
	return 0;
}