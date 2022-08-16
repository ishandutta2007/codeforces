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
llo it[500001];
llo co[500001];
llo xx[500001];
llo co2[500001];
llo co3[500001];
llo dp[500001];
llo pre[500001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		co[it[i]]++;
	}
	for(llo i=0;i<n;i++){
		co2[it[i]]++;
		if(xx[it[i]]==0){
			xx[it[i]]=i+1;
		}
		if(co2[it[i]]==co[it[i]]){
			dp[i+1]=max(dp[i+1],pre[xx[it[i]]-1]+co[it[i]]);
		}
		pre[i+1]=pre[i];
		pre[i+1]=max(pre[i+1],dp[i+1]);
	}
	llo ans=pre[n];
	for(llo i=n-1;i>=0;i--){
		co3[it[i]]++;
		ans=max(ans,co3[it[i]]+pre[i]);
	}
	cout<<n-ans<<endl;














 
	return 0;
}