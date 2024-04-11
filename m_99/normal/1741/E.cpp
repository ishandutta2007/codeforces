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
		
		vector<int> b(n);
		rep(i,n)scanf("%d",&b[i]);
		
		vector dp(n+1,false);
		dp[0] = true;
		
		rep(i,n+1){
			if(i!=0){
				int x = b[i-1];
				if(i-1-x>=0&&dp[i-1-x])dp[i] = true;
			}
			if(i!=n){
				if(dp[i]){
					if(i+b[i]+1<=n)dp[i+b[i]+1] = true;
				}				
			}
		}
		
		if(dp[n])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}