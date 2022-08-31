//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo dp[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<llo,llo>> aa;
	for(llo i=0;i<n;i++){
		llo bb,cc;
		cin>>bb>>cc;
	
		aa.pb({bb,cc});
	}
	sort(aa.begin(),aa.end());
	for(llo i=1;i<=aa.size();i++){
		llo ind=i;
		for(llo j=19;j>=0;j--){
			if((ind-(1<<j))>0){
				if(aa[ind-(1<<j)-1].a>=aa[i-1].a-aa[i-1].b){
					ind-=(1<<j);
				}
			}
		}
		dp[i]=dp[ind-1]+(i-ind);
	}
	llo ans=n+1;
	for(llo i=0;i<=n;i++){
		ans=min(ans,n-i+dp[i]);
	}
	cout<<ans<<endl;


 
	return 0;
}