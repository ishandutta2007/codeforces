//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


 const llo mod=1e9+7;
//llo pre[200001];
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
llo fac[3000002];
llo fac2[3000002];
llo cal(llo x,llo y){
 	if(y>x){
 		return 0;
 	}
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}
llo dp[3000001][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=3000001;
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
	llo n,q;
	cin>>n>>q;
	dp[0][0]=n;
	dp[0][1]=n;
	dp[0][2]=n;
	llo tt=ee(3,mod-2);
	
	for(llo i=1;i<=3*n;i++){
		llo su=cal(3*n,i+1);
		//cout<<su<<endl;
		llo x=dp[i-1][0];
		llo y=dp[i-1][1];
		llo zz=(su-y-2*x+3*mod)%mod;
	//	cout<<zz<<":"<<endl;
		dp[i][0]=(zz*tt)%mod;
		dp[i][1]=(dp[i][0]+x)%mod;
		dp[i][2]=(dp[i][1]+y)%mod;
	}
	/*for(int i=0;i<=3*n;i++){
		cout<<dp[i][0]<<":"<<dp[i][1]<<":"<<dp[i][2]<<endl;
	}*/
	while(q--){
		llo x;
		cin>>x;
		llo ans=(dp[x][0]+cal(3*n,x))%mod;
		cout<<ans<<endl;
	}
 
 
 
 
 
 
 
 
 
 
 
	return 0;
}