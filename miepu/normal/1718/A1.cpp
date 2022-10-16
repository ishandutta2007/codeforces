#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N],sum[N];
int dp[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		dp[i]=1e9;
	}
	dp[0]=0;
	map<int,int> fst;fst[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+1;
		if(a[i]==0){
			dp[i]=dp[i-1];
		}
		if(fst.find(sum[i])!=fst.end()){
			dp[i]=min(dp[i],dp[fst[sum[i]]]+i-fst[sum[i]]-1);
		}
		fst[sum[i]]=i;
	}
	cout<<dp[n]<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}