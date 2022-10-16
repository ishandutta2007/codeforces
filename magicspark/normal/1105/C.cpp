//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,l,r;
int fastpow(int x,int y){
	if(y==0)return 1ll;
	if(y&1){
		int k=fastpow(x,y>>1);
		k=k*k%mod;
		k=k*x%mod;
		return k;
	}else{
		int k=fastpow(x,y>>1);
		k=k*k%mod;
		return k; 
	}
}
int dp[200005][3]; 
int cnt[3];
signed main(){
	cin>>n>>l>>r;
	cnt[0]=dp[0][0]=r/3-(l-1)/3;
	cnt[1]=dp[0][1]=(r+2)/3-(l+1)/3;
	cnt[2]=dp[0][2]=(r+1)/3-l/3;
	for(int i=0;i<n;i++){
		for(int j=0;j<=2;j++){
			for(int k=0;k<=2;k++){
				dp[i+1][(j+k)%3]+=(dp[i][j]*cnt[k])%mod;
				dp[i+1][(j+k)%3]%=mod;
			}
		}
	}
	cout<<dp[n-1][0]<<endl;
	return 0;
}