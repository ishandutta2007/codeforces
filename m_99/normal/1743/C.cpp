#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		if(n==1){
			if(s[0]=='0')cout<<0<<endl;
			else cout<<a[0]<<endl;
			continue;
		}
		
		vector dp(2,-Inf32);
		if(s[0]=='0'){
			dp[0] = 0;
			if(s[1]=='1')dp[1] = a[0];
		}
		else{
			dp[0] = a[0];
		}
		//if(s[1]=='1')dp[1] = a[0];
		for(int i=1;i<n;i++){
			vector<int> ndp(2,-Inf32);
			rep(j,2){
				if(dp[j]==-Inf32)continue;
				rep(k,2){
					if(i==n-1||(s[i+1]=='0')){
						if(k==1)continue;
					}
					ndp[0] = max({ndp[0],dp[0],dp[1]});
					if(j==0&&s[i]=='1'){
						ndp[0] = max(ndp[0],dp[0]+a[i]);
					}
					if(k==1){
						ndp[1] = max(ndp[1],dp[0]+a[i]);
						ndp[1] = max(ndp[1],dp[1]+a[i]);
						
					}
				}
			}
			swap(dp,ndp);
		}
		cout<<dp[0]<<endl;
	}
	
	return 0;
}