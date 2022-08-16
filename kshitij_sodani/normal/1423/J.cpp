
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int dp[61][8];
int mod=1e9+7;

int pre[16];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<8;i+=2){
			dp[0][i/2]+=1;
		}

	while(t--){
		llo n;
		cin>>n;
		
		int kk=60;
		int ma=0;
	/*	for(int i=0;i<8;i++){
			cout<<dp[i][0]<<",";
		}
		cout<<endl;*/
		for(int i=1;i<kk;i++){

			for(int j=0;j<8;j++){
				dp[i][j]=0;
			}
			pre[0]=dp[i-1][0];
			for(int j=1;j<8;j++){
				pre[j]=(pre[j-1]+dp[i-1][j]);
				if(pre[j]>=mod){
					pre[j]-=mod;
				}
			}
		/*	for(int j=8;j<16;j++){
				pre[j]=pre[j-1];
			}*/
			int xx=0;
			if(n&(1LL<<i)){
				xx=1;
				ma=i;
			}
			int jj=0;
			for(int j=xx;j<16;j+=2){

				int yy=pre[min(j,7)];
				if(j>=8){
					yy=yy-pre[j-8];
				}
				if(yy<0){
					yy+=mod;
				}
				dp[i][jj]=(dp[i][jj]+yy);
				if(dp[i][jj]>=mod){
					dp[i][jj]-=mod;
				}
				jj+=1;
			}
			/*for(int j=0;j<8;j++){
				cout<<dp[i][j]<<",";
			}
			cout<<endl;*/
		}
		cout<<dp[kk-1][0]<<endl;




	}


	return 0;
}