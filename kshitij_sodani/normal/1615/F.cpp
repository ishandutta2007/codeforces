//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo aa[2001];
llo bb[2001];
llo dp[2001][2001][2][2];
llo dp2[2001][2001][2][2];

const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s;
		string ss;
		cin>>s>>ss;
		vector<llo> cc;
		for(llo i=0;i<n;i++){
			aa[i]=s[i]-'0';
			if(s[i]=='?'){
				aa[i]=-1;
			}
			else{
				if(i%2==0){
					aa[i]=1-aa[i];
				}
			}
			bb[i]=ss[i]-'0';
			if(ss[i]=='?'){
				bb[i]=-1;
			}
			else{
				if(i%2==0){
					bb[i]=1-bb[i];
				}
			}
		}
		llo ans=0;
		for(llo i=0;i<=n;i++){
			for(llo j=0;j<=n;j++){
				if(i==0 and j==0){
					dp[i][j][0][0]=1;
					continue;
				}
				if(i==0){
					if(bb[j-1]==1){
						dp[i][j][0][0]=0;
						continue;
					}
					dp[i][j][0][0]=dp[i][j-1][0][0];
					continue;
				}
				if(j==0){
					if(aa[i-1]==1){
						dp[i][j][0][0]=0;
						continue;
					}
					dp[i][j][0][0]=dp[i-1][j][0][0];
					continue;
				}
				dp[i][j][0][0]=0;
				dp[i][j][1][0]=0;
				dp[i][j][0][1]=0;
				dp[i][j][1][1]=0;
				for(llo k=0;k<2;k++){
					if(aa[i-1]>=0 and aa[i-1]!=k){
						continue;
					}
					for(llo l=0;l<2;l++){
						if(bb[j-1]>=0 and bb[j-1]!=l){
							continue;
						}
						if(k==1 and l==1){
							dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][j-1][0][0]+dp[i-1][j-1][0][1]+dp[i-1][j-1][1][0]+dp[i-1][j-1][1][1]);
							dp[i][j][k][l]%=mod;
							continue;
						}
						if(k==0){
							dp[i][j][k][l]=(dp[i][j][k][l]+dp[i-1][j][0][l]+dp[i-1][j][1][l]);
							dp[i][j][k][l]%=mod;
							continue;
						}
						if(l==0){
							dp[i][j][k][l]=(dp[i][j][k][l]+dp[i][j-1][k][0]+dp[i][j-1][k][1]);
							dp[i][j][k][l]%=mod;
							continue;
						}

					}
				}
			}
		}
		for(int i=0;i<n/2;i++){
			swap(aa[i],aa[n-i-1]);
			swap(bb[i],bb[n-i-1]);
		}
		for(llo i=0;i<=n;i++){
			for(llo j=0;j<=n;j++){
				if(i==0 and j==0){
					dp2[i][j][0][0]=1;
					continue;
				}
				if(i==0){
					if(bb[j-1]==1){
						dp2[i][j][0][0]=0;
						continue;
					}
					dp2[i][j][0][0]=dp2[i][j-1][0][0];
					continue;
				}
				if(j==0){
					if(aa[i-1]==1){
						dp2[i][j][0][0]=0;
						continue;
					}
					dp2[i][j][0][0]=dp2[i-1][j][0][0];
					continue;
				}
				dp2[i][j][0][0]=0;
				dp2[i][j][1][0]=0;
				dp2[i][j][0][1]=0;
				dp2[i][j][1][1]=0;
				for(llo k=0;k<2;k++){
					if(aa[i-1]>=0 and aa[i-1]!=k){
						continue;
					}
					for(llo l=0;l<2;l++){
						if(bb[j-1]>=0 and bb[j-1]!=l){
							continue;
						}
						if(k==1 and l==1){
							dp2[i][j][k][l]=(dp2[i][j][k][l]+dp2[i-1][j-1][0][0]+dp2[i-1][j-1][0][1]+dp2[i-1][j-1][1][0]+dp2[i-1][j-1][1][1]);
							dp2[i][j][k][l]%=mod;
							continue;
						}
						if(k==0){
							dp2[i][j][k][l]=(dp2[i][j][k][l]+dp2[i-1][j][0][l]+dp2[i-1][j][1][l]);
							dp2[i][j][k][l]%=mod;
							continue;
						}
						if(l==0){
							dp2[i][j][k][l]=(dp2[i][j][k][l]+dp2[i][j-1][k][0]+dp2[i][j-1][k][1]);
							dp2[i][j][k][l]%=mod;
							continue;
						}

					}
				}
			}
		}
		
		for(int i=0;i<n/2;i++){
			swap(aa[i],aa[n-i-1]);
			swap(bb[i],bb[n-i-1]);
		}

		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				if(aa[i]!=0 and bb[j]!=0){
					/*if(dp[i][j]>0){
						cout<<i<<":"<<j<<":"<<dp[i][j]<<":"<<dp2[n-i-1][n-j-1]<<endl;
					}*/
					llo cur=(dp[i+1][j+1][1][1]*dp2[n-i][n-j][1][1])%mod;
					ans=(ans+cur*(abs(i-j)))%mod;
				}
			}
		}


		cout<<ans<<endl;

	}






 
	return 0;
}