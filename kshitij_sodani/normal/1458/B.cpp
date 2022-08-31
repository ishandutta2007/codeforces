//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int aa[101];
int bb[101];
int dp[101][101*101][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int su=0;
	for(int i=0;i<n;i++){
		cin>>aa[i]>>bb[i];
		su+=bb[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=100*n;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k]=-1;
			}
		}
	}
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=i;k++){
			for(int j=0;j<=100*i;j++){
				if(dp[i-1][j][k]!=-1){
					dp[i][j][k]=dp[i-1][j][k];
				}
				if(k>0 and j>=aa[i-1]){
					if(dp[i-1][j-aa[i-1]][k-1]!=-1){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-aa[i-1]][k-1]+bb[i-1]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		long double ans=0;
		for(int j=0;j<=100*n;j++){
			long double cur=su;
			if(dp[n][j][i]!=-1){
				cur+=(long double)(dp[n][j][i]);
				cur/=2;
				long double cur2=j;
				cur=min(cur,cur2);
				ans=max(ans,cur);
			}
		}
		cout<<setprecision(10)<<ans<<" ";

	}
	
	cout<<endl;




 
	return 0;
}