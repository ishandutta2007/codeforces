#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int main() {	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		
		vector dp(3,vector<long long>(1<<4,-Inf64));
		dp[0][0] = 0;
		dp[1][0] = 0;
		rep(i,n){
			{
				vector ndp(3,vector<long long>(1<<4,-Inf64));
				rep(j,3){
					rep(k,1<<4){
						ndp[j][k] = max(ndp[j][k],dp[j][k]);
						if(j!=2)ndp[j+1][k] = max(ndp[j+1][k],dp[j][k]);
					}
				}
				swap(dp,ndp);
			}
			{
				vector ndp(3,vector<long long>(1<<4,-Inf64));
				rep(j,3){
					rep(k,1<<4){
						ndp[j][k] = max(ndp[j][k],dp[j][k]);
						if(j==0||j==2){
							if((k&1)==0){
								ndp[j][k|1] = max(ndp[j][k|1],dp[j][k] - a[i]);
							}
							if((k&2)==0){
								ndp[j][k|2] = max(ndp[j][k|2],dp[j][k] + a[i]);
							}
							if((k&3)==0){
								ndp[j][k|3] = max(ndp[j][k|3],dp[j][k]);
							}
						}
						else{
							if((k&4)==0){
								ndp[j][k|4] = max(ndp[j][k|4],dp[j][k] - a[i]);
							}
							if((k&8)==0){
								ndp[j][k|8] = max(ndp[j][k|8],dp[j][k] + a[i]);
							}
							if((k&12)==0){
								ndp[j][k|12] = max(ndp[j][k|12],dp[j][k]);
							}
						}
					}
				}
				swap(dp,ndp);
			}
		}
		long long ans = -Inf64;
		rep(i,3)ans = max(ans,dp[i].back());
		cout<<ans<<endl;
	}
	
    return 0;
}