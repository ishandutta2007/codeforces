#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[1001];
int dp[101][101][2];
//even,odd,parity
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			dp[i][j][0]=0;
			dp[i][j][1]=0;
			if(i==0 and j==0){
				dp[i][j][0]=1;
				continue;
			}
			if(i==0){
				if(((j+1)/2)%2==0){
					dp[i][j][0]=1;
				}
				else{
					dp[i][j][1]=1;
				}
				continue;
			}
			if(j==0){
				dp[i][j][0]=1;
				continue;
			}
			if(dp[i-1][j][0]==0){
				if((j-1)%2==0){
					dp[i][j][0]=1;
				}
				else{
					dp[i][j][1]=1;
				}
			}
			if(dp[i-1][j][1]==0){
				//even must
				if((j%2)==1){
					dp[i][j][1]=1;
				}
				else{
					dp[i][j][0]=1;
				}
			}

			if(dp[i][j-1][0]==0){
				if((j)%2==0){
					dp[i][j][1]=1;
				}
				else{
					dp[i][j][0]=1;
				}
			}
			if(dp[i][j-1][1]==0){
				//even must
				if(((j-1)%2)==1){
					dp[i][j][0]=1;
				}
				else{
					dp[i][j][1]=1;
				}
			}
		}
	}
	while(t--){
		int n;
		cin>>n;
		int su=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(abs(it[i])%2==0){
				su++;
			}
		}
		if(dp[su][n-su][0]==1){
			cout<<"Alice"<<endl;
		}
		else{
			cout<<"Bob"<<endl;
		}

	}
	



	return 0;
}