//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,l,kk;
llo it[501];
llo aa[501];
llo dp[501][501];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l>>kk;
	for(llo i=0;i<n;i++){
			cin>>it[i];
	}
	for(llo i=0;i<=n;i++){
		for(llo j=0;j<=n;j++){
			dp[i][j]=1e9;
		}
	}
	llo ans=1e9;
	for(llo i=0;i<n;i++){
		cin>>aa[i];
	}
	dp[0][1]=0;
	for(llo j=1;j<n;j++){
		for(llo k=0;k<=j-1;k++){
			for(llo i=1;i<=k+1;i++){
				dp[j][i+1]=min(dp[j][i+1],dp[k][i]+(it[j]-it[k])*aa[k]);
			}
		}
	}
	for(llo i=0;i<n;i++){
		for(llo j=1;j<=n;j++){
			if(n-j<=kk){
				ans=min(ans,dp[i][j]+(l-it[i])*aa[i]);
			}
		}
	
	}
	cout<<ans<<endl;




 
	return 0;
}