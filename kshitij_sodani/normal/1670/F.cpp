#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=1e9+7;

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
llo fac[3000];
llo fac2[3000];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}

llo n,l,r,z;
llo dp[65][1001][2];
llo solve(llo la,llo z){
	if(la==0){
		return 0;
	}
	for(llo i=0;i<=60;i++){
		for(llo j=0;j<=n;j++){
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	for(llo i=0;i<60;i++){
		llo x=(1LL<<i)&la;
		if(x>0){
			x=1;
		}
		llo y=(1LL<<i)&z;
		if(y>0){
			y=1;
		}
		if(i==0){
			for(llo j=y;j<=n;j+=2){
				llo ac=0;
				if(y>x){
					ac=1;
				}
				/*if(ac==1){
					cout<<11<<endl;
				}*/
				//cout<<j<<",,"<<endl;
				dp[1][j/2][ac]+=cal(n,j);
				if(dp[1][j/2][ac]>=mod){
					dp[1][j/2][ac]-=mod;
				}
			}
			continue;
		}
		
			for(llo j=0;j<=n;j++){
				for(llo k=0;k<2;k++){

					if(dp[i][j][k]==0){
						continue;
					}
					/*if(i==1){
						cout<<i<<":"<<j<<":"<<k<<endl;
					}*/
					for(llo l=y;l<=n;l+=2){
						//
						
						llo xx=(l+j)&1;
						llo kk=k;
						if(xx==0 and x==1){
							kk=0;
						}
						if(xx==1 and x==0){
							kk=1;
						}
						llo ok=(l+j)/2;
						//if(i+1==2 and ok==0 and kk==0){
							//cout<<i<<":"<<j<<":"<<k<<":"<<l<<endl;
						//	cout<<((cal(n,l)*dp[i][j][k])%mod)<<endl;
						//}
						dp[i+1][ok][kk]=(dp[i+1][ok][kk]+cal(n,l)*dp[i][j][k])%mod;
					}
				}
			}
		
	}
	//cout<<dp[2][0][0]<<endl;
	//cout<<dp[1][0][0]<<endl;
	return dp[60][0][0];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fac[0]=1;
	llo ma=2000;
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

	cin>>n>>l>>r>>z;
	llo ans=solve(r,z)-solve(l-1,z)+mod;
	ans%=mod;
	cout<<ans<<endl;
 	
 
 
	return 0;
}