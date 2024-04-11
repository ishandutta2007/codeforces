#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo dp[200003][8][8];
llo it[200003];
const llo mod=998244353;
llo ind[10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string ss;
	cin>>ss;
	llo n=ss.size();
	for(llo i=0;i<n;i++){
		it[i+1]=ss[i]-'0';
	}
	
	ind[0]=0;
	ind[1]=1;
	ind[2]=2;
	ind[4]=4;
	ind[5]=2;
	ind[6]=1;
	ind[3]=4;
	ind[7]=0;
	dp[0][0][0]=1;
	for(llo i=1;i<=n;i++){
		if(it[i]==0){
			for(llo j=0;j<8;j++){
				for(llo k=0;k<8;k++){
					for(llo kk=0;kk<8;kk++){
						if((kk&j)==kk){
							dp[i][j][k|ind[kk]]+=dp[i-1][j][k];
							if(dp[i][j][k|ind[kk]]>=mod){
								dp[i][j][k|ind[kk]]-=mod;
							}
						}
					}
					
				}
			}
		}
		else{
			for(llo j=0;j<8;j++){
				for(llo k=0;k<8;k++){
					for(llo kk=0;kk<8;kk++){
						llo jj=(7-kk)|j;
						dp[i][jj][k|ind[kk]]+=dp[i-1][j][k];
						if(dp[i][jj][k|ind[kk]]>=mod){
							dp[i][jj][k|ind[kk]]-=mod;
						}
					}
				}
			}
		}


	}
	/*for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(dp[1][i][j]>0){
				cout<<i<<":"<<j<<":"<<dp[1][i][j]<<endl;
			}
		}
	}*/
	llo ans=0;
		for(llo i=0;i<8;i++){
			ans+=dp[n][i][7];
			if(ans>=mod){
				ans-=mod;
			}
		}
		cout<<ans<<endl;
	




	return 0;
}