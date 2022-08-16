//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=1e9+7;
llo it[200001];
llo dp[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		dp[0]=1;
		llo ans=1;
		llo su=it[0];
		llo su2=1;
		map<llo,llo> ss;
		ss[0]++;
		for(llo i=1;i<n;i++){
			dp[i]=su2;
			if(ss.find(su)!=ss.end()){
				dp[i]-=ss[su];
				dp[i]+=mod*mod;
				dp[i]%=mod;
			}
			if(ss.find(su)!=ss.end()){
				ss[su]=(ss[su]+dp[i])%mod;
			}
			else{
				ss[su]=dp[i];
			}
			su+=it[i];

			su2=(su2+dp[i])%mod;
			ans=(ans+dp[i])%mod;
			//cout<<su2<<":"<<dp[i]<<endl;
		}
		//cout<<endl;
		cout<<ans<<endl;
	}









 
	return 0;
}