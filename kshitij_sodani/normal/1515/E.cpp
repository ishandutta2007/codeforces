//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,mod;
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
llo fac[401];
llo fac2[401];
llo val[401];
llo dp[401][401];
//till index i total j elements

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>mod;
	fac[0]=1;
	for(llo i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
	for(llo i=0;i<=n;i++){
		fac2[i]=ee(fac[i],mod-2);
	//	cout<<fac2[i]<<":";
	}
	//cout<<endl;
	val[1]=1;
	for(llo i=2;i<=n;i++){
		val[i]=(val[i-1]*2)%mod;
	}
	for(llo i=0;i<n;i++){
		for(llo j=i;j>=0;j--){
			for(llo k=n;k>=(i-j+1);k--){
				if(j==0){
					if(k==(i-j+1)){
						llo cur=fac2[(i-j+1)];
						cur=(cur*val[i-j+1])%mod;
						dp[i][k]=(dp[i][k]+cur)%mod;
					}
					/*if(i==n-1 and j==0 and k==n){
						cout<<((cur*fac[k])%mod)<<endl;
					}*/
				}
				else if(j>1){
					llo cur=(dp[j-2][k-(i-j+1)]*fac2[(i-j+1)])%mod;
					//cur=()%mod;
					dp[i][k]=(dp[i][k]+cur*val[i-j+1])%mod;
				}
			}
		}
	}
	llo ans=0;
	for(llo i=0;i<=n;i++){
		ans=(ans+dp[n-1][i]*fac[i])%mod;
		//cout<<i<<":"<<((dp[n-1][i]*fac[i])%mod)<<endl;
	}
	cout<<ans<<endl;











	return 0;
}