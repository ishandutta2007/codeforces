#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	

	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		
		vector dp(2,vector<long long>(2,0));
		dp[0][0] = 1;
		while(n!=0){
			int d = n%10;
			vector ndp(2,vector<long long>(2,0));
			rep(i,2){
				rep(j,2){
					rep(k,10){
						rep(l,10){
							int sum = k+l+j;
							if(sum%10!=d)continue;
							int ni = 0;
							if(sum>=10)ni = 1;
							ndp[ni][i] += dp[i][j];
						}
					}
				}
			}
			swap(dp,ndp);
			n /= 10;
		}
		long long ans = dp[0][0];
		ans -= 2;
		cout<<ans<<endl;
	}
	
	return 0;
}