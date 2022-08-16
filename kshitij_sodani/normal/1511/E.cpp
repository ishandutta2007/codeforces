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
vector<llo> it[300001];
vector<llo> tt[300001];
llo pre[300001];
const llo mod=998244353;
llo ans=0;
llo xx=0;
llo dp[300001];
void solve(){
	for(llo i=0;i<n;i++){
		llo co=0;
		for(llo j=0;j<m;j++){
			if(it[i][j]==0){
				co=0;
				continue;
			}
			co+=it[i][j];
			if(j>0 and co>=2){
				ans=(ans+pre[xx-co]*dp[co-2])%mod;
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	pre[0]=1;

	for(llo i=1;i<=n*m;i++){
		pre[i]=pre[i-1]+pre[i-1];
		if(pre[i]>=mod){
			pre[i]-=mod;
		}
	}
	dp[0]=1;
	dp[1]=1;
	for(llo i=2;i<=n*m;i++){
		dp[i]=dp[i-2]+pre[i-1];
		if(dp[i]>=mod){
			dp[i]-=mod;
		}
	}

	for(llo i=0;i<n;i++){
		string s;
		cin>>s;
		for(llo j=0;j<m;j++){
			if(s[j]=='*'){
				it[i].pb(0);
			}
			else{
				it[i].pb(1);
				xx++;
			}
			tt[j].pb(it[i][j]);
		}
	}
	solve();
	
	for(llo i=0;i<m;i++){
		it[i]=tt[i];
	}
	swap(n,m);
	solve();

	cout<<ans<<endl;

	













 
 
	return 0;
}