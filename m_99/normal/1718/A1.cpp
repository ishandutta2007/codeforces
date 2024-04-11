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
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		vector<int> dp(1<<13,Inf);
		dp[0] = 0;
		rep(i,n){
			vector<int> ndp(1<<13,Inf);
			rep(j,1<<13){
				int ta = a[i] ^ j;
				if(ta==0||a[i]==0){
					ndp[0] = min(ndp[0],dp[j]);
				}
				else{
					ndp[ta] = min(ndp[ta],dp[j]+1);
					ndp[a[i]] = min(ndp[a[i]],dp[j]+1);
				}
			}
			swap(dp,ndp);
		}
		int ans = Inf;
		rep(i,1<<13)ans = min(ans,dp[i]);
		cout<<ans<<endl;
	}
	
    return 0;
}