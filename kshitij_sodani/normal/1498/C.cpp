//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'



llo t;
const llo mod=1e9+7;
//llo dp[1002][1002];
llo co[1002];
llo co2[1002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){

		}
	}*/
	cin>>t;

	while(t--){
		llo n,k;
		cin>>n>>k;
		llo ans=1;
		for(int i=0;i<=n;i++){
			co[i]=0;
			co2[i]=0;
		}
		co[0]=1;
		for(int i=k-1;i>=1;i--){
			llo su=0;
			for(int j=0;j<n;j++){
				su=(su+co[j])%mod;
				co2[j]=su;
			}
			for(int j=0;j<=n;j++){
				ans=(ans+co2[j])%mod;
				co[j]=co2[j];
				co2[j]=0;
			}
			for(int j=0;j<=n/2;j++){
				swap(co[j],co[n-j]);
			}
		}
		cout<<ans<<endl;

	}








 
	return 0;
}