//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int t;
int it[50001];
int dp[50001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int x;
		cin>>x;
		dp[0]=0;
		int ind=1;
		for(int i=1;i<=n;i++){
			if(i==1){
				dp[i]=1;
				continue;
			}
			if(it[i-1]+it[i-2]<2*x){
				ind=max(ind,i);
			}
			if(i>=3){
				if(it[i-1]+it[i-2]+it[i-3]<3*x){
					ind=max(ind,i-1);
				}
			}
			dp[i]=dp[max(0,ind-2)]+i-ind+1;

		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;



	}






 
	return 0;
}