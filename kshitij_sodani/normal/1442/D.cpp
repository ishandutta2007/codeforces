
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n,k;
vector<llo> pre[3001];
llo dp[3001];
llo ans=0;
void solve(llo l,llo r){
	if(l==r){
		llo su=0;
		for(llo j=0;j<=min(k,(llo)pre[l].size());j++){
			if(j>0){
				su+=pre[l][j-1];
			}
			ans=max(ans,su+dp[k-j]);
		}
	}
	else{
		llo mid=(l+r)/2;
		vector<llo> ss;
		for(llo i=0;i<=k;i++){
			ss.pb(dp[i]);
		}
		for(llo i=mid+1;i<=r;i++){
			llo kk=0;
			for(auto j:pre[i]){
				kk+=j;
			}
			for(llo j=k;j>=pre[i].size();j--){
				dp[j]=max(dp[j],dp[j-pre[i].size()]+kk);
			}
		}
		solve(l,mid);
		for(llo i=0;i<=k;i++){
			dp[i]=ss[i];
		}
		for(llo i=l;i<=mid;i++){
			llo kk=0;
			for(auto j:pre[i]){
				kk+=j;
			}
			for(llo j=k;j>=pre[i].size();j--){
				dp[j]=max(dp[j],dp[j-pre[i].size()]+kk);
			}
		}
		solve(mid+1,r);
		for(llo i=0;i<=k;i++){
			dp[i]=ss[i];
		}

	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<n;i++){
		llo x;
		cin>>x;
		for(llo j=0;j<x;j++){
			llo aa;
			cin>>aa;
			pre[i].pb(aa);
		}
	}
	solve(0,n-1);






	cout<<ans<<endl;


	return 0;
}