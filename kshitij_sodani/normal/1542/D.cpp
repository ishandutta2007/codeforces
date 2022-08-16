//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

const llo mod=998244353 ;

llo n;
llo dp[510][510];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		char s;
		cin>>s;
		if(s=='-'){
			ss.pb({-1,-1});
		}
		else{
			llo aa;
			cin>>aa;
			ss.pb({1,aa});
		}
	}
	llo ans=0;
	for(llo i=0;i<n;i++){
		if(ss[i].a==1){
			dp[0][0]=1;
			for(llo j=0;j<n;j++){

				for(llo k=0;k<=n;k++){
					dp[j+1][k]=dp[j][k];
				}
				if(j==i){
					continue;
				}
				if(ss[j].a==1){
					llo val=0;
					if(ss[j].b<ss[i].b){
						val=1;
					}
					else if(ss[j].b==ss[i].b){
						if(j<i){
							val=1;
						}
					}
					for(llo k=0;k<=n;k++){
						if(val<=k){
							dp[j+1][k]+=dp[j][k-val];
							if(dp[j+1][k]>=mod){
								dp[j+1][k]%=mod;
							}
						}
					}
				}
				else{
					if(j<i){
						dp[j+1][0]+=dp[j][0];
						if(dp[j+1][0]>=mod){
							dp[j+1][0]-=mod;
						}
					}
					for(llo k=0;k<=n;k++){
						dp[j+1][k]+=dp[j][k+1];
						if(dp[j+1][k]>=mod){
							dp[j+1][k]%=mod;
						}
						
					}
				}
			}

			for(llo j=0;j<=n;j++){
				ans=(ans+ss[i].b*dp[n][j])%mod;
			}
			/*for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					cout<<dp[j][k]<<",";
				}
				cout<<endl;
			}
			cout<<endl;*/
		}
	}
	cout<<ans<<endl;





	return 0;
}