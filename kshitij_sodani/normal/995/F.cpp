#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo dp[3010][3010];
llo dp2[3010][3010];
llo mod=1e9+7;
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
vector<llo> adj[3010];
void dfs(llo no,llo par=-1){
	vector<llo> ss;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss.pb(j);
		}
	}
	if(ss.size()==0){
		for(llo i=1;i<=n;i++){
			dp[no][i]=1;
		}
		return;
	}
	for(auto j:ss){
		for(llo i=n;i>=1;i--){
			dp2[j][i]=dp2[j][i+1]+dp[j][i];
			if(dp2[j][i]>=mod){
					dp2[j][i]-=mod;
				}
			//dp2[j][i]%=mod;
			//cout<<dp[j][i]<<endl;
			//cout<<j<<":"<<i<<":"<<dp2[j][i]<<endl;
			/*if(i<n){
				dp2[j][i]+=dp2[j][i+1];
				if(dp2[j][i]>=mod){
					dp2[j][i]-=mod;
				}
			}*/
			//cout<<j<<":"<<i<<":"<<dp2[j][i]<<endl;
		}
	}
	for(llo i=1;i<=n;i++){
		llo cur=1;
		for(auto j:ss){
			cur=(cur*dp2[j][i])%mod;
		}
		dp[no][i]=cur;
	}


}
llo ans[3010];
llo pre3[3010];
llo pre4[3010];
llo cal2(llo i,llo j){
	llo cur=fac2[j];
	cur=(cur*pre3[i-(i-j+1)+1])%mod;
	return cur;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0]=1;
	llo ma=4000;
	llo d;
	cin>>n>>d;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	pre3[0]=1;
	for(llo i=1;i<=min(n,d);i++){
		pre3[i]=(pre3[i-1]*(d-i+1))%mod;
	}
	for(llo i=0;i<=min(n,d);i++){
		pre4[i]=ee(pre3[i],mod-2);
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
		cin>>aa;
		bb=i+2;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);

	
	for(llo i=1;i<=n;i++){
		ans[i]=dp[0][n+1-i];
		for(llo j=1;j<i;j++){
			llo xx=ans[j]*cal(i-1,j-1);
			xx%=mod;
			ans[i]=(ans[i]-xx+mod);//%mod;
			if(ans[i]>=mod){
				ans[i]-=mod;
			}
		}
	}
	llo cur=0;
	for(llo i=1;i<=n;i++){
		if(i<=d){
			cur=(cur+ans[i]*cal2(d,i))%mod;
		}
	}
	cout<<cur<<endl;






	return 0;
}