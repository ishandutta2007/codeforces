#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int it[4001];
int dp[2001][2001];
int ne[4001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<2*n;i++){
			cin>>it[i];
		}
		for(int i=0;i<2*n;i++){
			ne[i]=-1;
			for(int j=i+1;j<2*n;j++){
				if(it[j]>it[i]){
					ne[i]=j;
					break;
				}
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=0;
				if(i==0 or j==0){
					dp[i][j]=1;
					continue;
				}
				int x=ne[2*n-i-j];
				int cur=2*n-i-j;
				if(x==-1){
					continue;
				}
				if(x-cur<=i){
					dp[i][j]|=dp[i-(x-cur)][j];
				}
				if(x-cur<=j){
					dp[i][j]|=dp[i][j-(x-cur)];
				}
			}
		}
		if(dp[n][n]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}


	}
	





	return 0;
}