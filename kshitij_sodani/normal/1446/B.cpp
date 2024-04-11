//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,m;
llo dp[5001][5001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	string s;
	string t;
	cin>>s;
	cin>>t;
	llo ans=0;
	for(llo i=1;i<=n;i++){
		for(llo j=1;j<=m;j++){
			dp[i][j]=0;
			dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
			dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
			if(s[i-1]==t[j-1]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			}
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;





 
 
	return 0;
}