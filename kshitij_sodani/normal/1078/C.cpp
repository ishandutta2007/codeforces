//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=998244353;
llo n;
llo dp[3000001];//included in some matching
llo dp2[3000001];//1 size component
llo dp3[3000001];
vector<int> adj[3000001];
llo ee(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}

void dfs(int no,int par=-1){


	dp2[no]=1;
	dp3[no]=1;
	vector<int> ss;

	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			dp2[no]=(dp2[no]*((dp[j]+dp2[j]))%mod)%mod;
			dp3[no]=(dp3[no]*((dp[j]*2+dp2[j])%mod))%mod;
		}
	}
	llo cur=dp3[no];
	for(auto j:adj[no]){
		if(j!=par){
			llo cot=(cur*ee((dp[j]*2+dp2[j])%mod,mod-2))%mod;
			cot=(cot*dp3[j])%mod;
			dp[no]=(dp[no]+cot)%mod;
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	cout<<((dp[0]+dp2[0])%mod)<<endl;



 
	return 0;
}