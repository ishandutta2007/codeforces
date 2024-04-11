#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second


int n;
int it[101];
int dp[103][103][2];
int co[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	co[0]=n/2;
	co[1]=(n+1)/2;
	for(int i=1;i<=n;i++){
		cin>>it[i-1];
	/*	if(it[i-1]>0){
			co[(it[i-1]%2)]--;
		}*/
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=n;
			dp[i][j][1]=n;
		}
	}
	if(it[0]==0){
		dp[0][1][0]=0;
		dp[0][0][1]=0;
	}
	else{
		if(it[0]%2==1){
			dp[0][0][1]=0;
		}
		else{
			dp[0][1][0]=0;
		}
	}
	for(int i=1;i<n;i++){
		if(it[i]==0){
			for(int j=0;j<=n;j++){
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][0]);
				dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][1]+1);

				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
				dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
			}
		}
		else{
			if(it[i]%2==0){
				for(int j=0;j<=n;j++){
					dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][0]);
					dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][1]+1);

					/*dp[i][j+1][1]=min(dp[i][j+1][1],dp[i-1][j][1]);
					dp[i][j+1][1]=min(dp[i][j+1][1],dp[i-1][j][0]+1);*/
				}
			}
			else{
				for(int j=0;j<=n;j++){
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]);
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][0]+1);
				}
			}
		}
	}
	//cout<<dp[1][1][1]<<endl;
	cout<<min(dp[n-1][n/2][0],dp[n-1][n/2][1])<<endl;




	


	return 0;
}