#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo dp[2001][2001];
llo dp2[2001][2001];
llo mod;
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
llo fac[200001];
llo fac2[200001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

llo n;
vector<llo> adj[2001];
llo xx[2001][2001];
llo yy[2001][2001];
void dfs(llo no,llo par=-1){
	vector<llo> ss;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss.pb(j);
		}
	}
	if(ss.size()==0){
		for(llo i=1;i<=n-1;i++){
			dp[no][i]=1;
		}
		return;
	}
	for(auto j:ss){
		for(llo i=n-1;i>=1;i--){
			dp2[j][i]=dp[j][i];
			if(i<n-1){
				dp2[j][i]+=dp2[j][i+1];
				if(dp2[j][i]>=mod){
					dp2[j][i]-=mod;
				}
			}
		}
	}
	for(llo i=1;i<=n-1;i++){
		llo cur=1;
		for(auto j:ss){
			cur=(cur*dp2[j][i])%mod;
		}
		dp[no][i]=cur;
	}

	
	if(no==0){
		/*for(llo i=n-2;i>=1;i--){
			dp[no][i]=(dp[no][i]-dp[no][i+1]+mod)%mod;
		}*/

		return;
	}
	for(llo i=1;i<=n-1;i++){
		xx[i][0]=1;
		yy[i][ss.size()]=1;
		int ind=0;
		for(auto j:ss){
			ind++;
			xx[i][ind]=(xx[i][ind-1]*dp2[j][i])%mod;
		}
		ind=ss.size();
		for(int j=ss.size()-1;j>=0;j--){
			yy[i][j]=(yy[i][j+1]*dp2[ss[j]][i])%mod;
		}
	}
	int ind=0;
	for(auto j:ss){
		ind++;
		llo su=0;
		for(llo i=n-1;i>=0;i--){
			dp[no][i]=(dp[no][i]+dp[j][i]*su)%mod;
			su=(su+xx[i][ind-1]*yy[i][ind])%mod;
		}
	}

}
llo ans[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0]=1;
	llo ma=4000;
	cin>>n>>mod;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	for(llo i=ma;i>=0;i--){
		if(i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
	}


	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);

	/*for(int i=0;i<2;i++){
		for(int j=1;j<=n-1;j++){
			cout<<dp[i][j]<<",";
		}
		cout<<endl;
	}*/
	for(llo i=1;i<=n-1;i++){
		ans[i]=dp[0][n-i];
		for(llo j=1;j<i;j++){
			llo xx=ans[j]*cal(i,j);
			xx%=mod;
			ans[i]=(ans[i]-xx+mod);//%mod;
			if(ans[i]>=mod){
				ans[i]-=mod;
			}
		}
	}
	for(llo i=1;i<=n-1;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;







	return 0;
}