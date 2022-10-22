#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

#define Maxi 20000005

int cnt[Maxi];
long long dp[Maxi];
vector<int> p;
int main(){
	
	for(int i=2;i<Maxi;i++){
		if(cnt[i]==0){
			p.push_back(i);
			for(int j=i;j<Maxi;j+=i)cnt[j]++;
		}
	}
	rep(i,Maxi)cnt[i] = 0;
	
	int n;
	cin>>n;
	
	rep(i,n){
		int a;
		scanf("%d",&a);
		cnt[a]++;
	}
	/*
	for(int i=1;i<Maxi;i++){
		for(int j=i*2;j<Maxi;j+=i)cnt[i] += cnt[j];
	}
	*/
	
	rep(i,p.size()){
		for(int j=(Maxi-1)/p[i];j>=1;j--){
			cnt[j] += cnt[j*p[i]];
		}
	}
	
	for(int i=Maxi-1;i>=1;i--){
		if(cnt[i]==0)continue;
		dp[i] = cnt[i];
		dp[i] *= i;
		rep(j,p.size()){
			long long t = p[j];
			t *= i;
			if(t >= Maxi)break;
			t = dp[t] + ((long long)(cnt[i] - cnt[t]))*i;

			dp[i] = max(dp[i],t);
		}
	}
	long long ans = 0;
	rep(i,Maxi)ans = max(ans,dp[i]);
	
	cout<<ans<<endl;
	
		
	return 0;
}