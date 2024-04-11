#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int power(int x,int y){
	int ret=1;
	do{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
	}while(y>>=1);
	return ret;
}
int n,a[111],dp[1<<14],win[111][111];
int get_cost(int m1,int m2){
	int ret=1;
	for(int i=0;i<n;i++)if(m1&(1<<i)){
		for(int j=0;j<n;j++)if(m2&(1<<j)){
			ret=1ll*ret*win[i][j]%mod;
		}
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			win[i][j]=1ll*a[i]*power(a[i]+a[j],mod-2)%mod;
		}
	}
	const int full=(1<<n)-1;
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		dp[i]=1;
		for(int sub=i&(i-1);sub;sub=(sub-1)&i){
			dp[i]=(dp[i]-1ll*dp[sub]*get_cost(sub,i^sub)%mod+mod)%mod;
		}
		ans=(ans+1ll*dp[i]*__builtin_popcount(i)%mod*get_cost(i,full^i))%mod;
	}
	cout<<ans<<endl;
	return 0;
}