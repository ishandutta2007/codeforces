#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

const llo mod=998244353;
llo dp[200001];
llo fac[200001];
llo fac2[200001];
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
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
llo ans[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=200000;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
 
	for(llo i=ma;i>=0;i--){
		if(i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
		//cout<<fac2[i]<<":";
	}
	llo n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i==1){
			dp[i]=fac[n-1];
		}
		else if(n-i+1<=(n/2)){
			dp[i]=0;
		}
		else{

			dp[i]=fac[n-i];
			dp[i]=(dp[i]*(i-1))%mod;
			dp[i]=(dp[i]*fac[i-2])%mod;
			dp[i]=(dp[i]*cal(n-((n+1)/2),i-1))%mod;;
		}
	//	cout<<i<<":"<<dp[i]<<endl;
	}
	llo su=0;
	for(int i=n;i>=1;i--){
		llo cur=dp[i];
		llo cur2=su;
		cur2=(cur2*ee(i,mod-2))%mod;
		cur=(cur-cur2+mod)%mod;
		ans[i]=cur;
		su=(su+ans[i]);
		if(su>=mod){
			su-=mod;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;






	return 0;
}