//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo co[30][30];
int dp[1<<23][23];
const llo mod=998244353;
llo mi[30];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		string s;
		cin>>s;
		for(llo j=0;j<s.size();j++){
			co[i][s[j]-'a']++;
		}
	}
	llo ans=0;
	for(llo i=1;i<(1<<n);i++){
		llo su=0;
		llo co2=0;
		for(llo j=0;j<26;j++){
			mi[j]=2e4;
		}
		for(llo j=0;j<n;j++){
			if((1<<j)&i){
				co2++;
				su+=j+1;
				for(llo k=0;k<26;k++){
					mi[k]=min(mi[k],co[j][k]);
				}
			}
		}
		llo cur=1;
		for(llo k=0;k<26;k++){
			cur=(cur*(mi[k]+1))%mod;
		}
		if(co2%2==0){
			cur=(mod-cur)%mod;
		}
		dp[i][0]=cur;
		for(llo j=1;j<=n;j++){
			dp[i][j]=dp[i][j-1];
			if((1<<(j-1))&i){
				dp[i][j]=(dp[i][j]+(dp[i^(1<<(j-1))][j-1]));
				if(dp[i][j]>=mod){
					dp[i][j]-=mod;
				}
			}

		}
		llo zz=dp[i][n];
		zz=(zz*su*co2);//%mod;
		ans=(ans^zz);

	}
	cout<<ans<<endl;


 
	return 0;
}