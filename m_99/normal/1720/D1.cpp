#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

int main() {	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		vector<int> dp(n,1);
		rep(i,n){
			rep(j,256){
				int ii = i,jj = i+1+j;
				if(jj>=n)break;
				if((a[ii]^jj)<(a[jj]^ii)){
					dp[jj] = max(dp[jj],dp[ii]+1);
				}
			}
		}
		
		int ans = 0;
		rep(i,n)ans = max(ans,dp[i]);
		cout<<ans<<endl;
	}
	
    return 0;
}