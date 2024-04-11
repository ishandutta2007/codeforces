//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

llo it[5001];
llo dp[5001];
llo dp2[5001];
llo n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<llo> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]-=i;
		ss.pb(it[i]);
		
	}
	sort(ss.begin(),ss.end());

	/*for(llo i=0;i<n/2;i++){
		swap(it[i],it[n-1-i]);
	}*/
	for(llo i=1;i<=n;i++){
		llo ma=(llo)1e18;
		/*if(i==0){
			ma=0;
		}*/
		for(llo j=1;j<=n;j++){
			ma=min(ma,dp[j]);
			dp2[j]=ma+abs(ss[j-1]-it[i-1]);
		}
		for(int j=0;j<=n;j++){
			dp[j]=dp2[j];
			dp2[j]=0;
		}
	}
	llo ans=1e18;
	for(llo i=1;i<=n;i++){
		ans=min(ans,dp[i]);
		//cout<<dp[i]<<",";
	}
	//cout<<endl;
	cout<<ans<<endl;






 
	return 0;
}