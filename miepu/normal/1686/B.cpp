#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

int n;
int a[N],dp[N]; 
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]<a[i-1])dp[i]=max(dp[i],dp[i-2]+1);
	}
	cout<<dp[n]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}