#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo it[200001];
llo dp[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,x;
		cin>>n>>x;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		for(llo i=0;i<=n;i++){
			dp[i]=0;
		}
		set<pair<llo,llo>> xx;
		llo ind=0;
		for(llo i=1;i<=n;i++){
			while(true){
				auto j=xx.lower_bound({it[i-1]+2*x+1,-1});
				if(j==xx.end()){
					break;
				}
				ind=max(ind,(*j).b+1);
				xx.erase(j);
			}
			while(true){
				auto j=xx.lower_bound({it[i-1]-2*x,-1});
				if(j==xx.begin()){
					break;
				}
				j--;
				ind=max(ind,(*j).b+1);
				xx.erase(j);
			}
			dp[i]=dp[ind]+1;
			xx.insert({it[i-1],i-1});
			//cout<<i<<":"<<ind<<endl;
		}
		cout<<dp[n]-1<<endl;
	}








	return 0;
}