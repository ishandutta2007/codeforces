#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

#define Maxi 5000005

int main(){
	int n;
	cin>>n;
	
	vector<int> cnt(Maxi,0);
	rep(i,n){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	
	for(int i=1;i<Maxi;i++){
		for(int j=i*2;j<Maxi;j+=i)cnt[i] += cnt[j];
	}
	
	vector<long long> dp(Maxi,0);
	for(int i=Maxi-1;i>=1;i--){
		dp[i] = cnt[i];
		dp[i] *= i;
		for(int j=i*2;j<Maxi;j+=i){
			long long t = dp[j];
			t += ((long long)(cnt[i] - cnt[j]))*i;
			dp[i] = max(dp[i],t);
		}
	}
	long long ans = 0;
	rep(i,dp.size())ans = max(ans,dp[i]);
	
	cout<<ans<<endl;
	
		
	return 0;
}