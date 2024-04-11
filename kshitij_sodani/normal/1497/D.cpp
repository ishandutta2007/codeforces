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
llo n;
llo it[5001];
llo aa[5001];
llo dp[5001];

/*pair<pair<llo,llo>,pair<llo,llo>> dp[5001][2][2];
pair<llo,llo> cur[5001][2][2];*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			dp[i]=0;
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=0;i<n;i++){
			for(llo j=i-1;j>=0;j--){
				if(aa[i]!=aa[j]){
					llo x=dp[i];
					llo y=dp[j];
					dp[j]=max(dp[j],x+abs(it[i]-it[j]));
					dp[i]=max(dp[i],y+abs(it[i]-it[j]));
				}
			}
		}
		for(llo i=0;i<n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;

	}







	return 0;
}