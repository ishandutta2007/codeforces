#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		vector a(n,vector<long long>(m));
		rep(i,n){
			rep(j,m){
				scanf("%lld",&a[i][j]);
			}
		}
		long long ans = Inf;
		rep(i,n){
			rep(j,m){
				vector dp(n,vector<long long>(m,Inf));
				long long t = a[i][j] - (i+j);
				if(t>a[0][0])continue;
				dp[0][0] = a[0][0] - t;
				rep(k,n){
					rep(l,m){
						if(dp[k][l]==Inf)continue;
						if(k!=n-1){
							long long g = t+(k+l+1);
							if(a[k+1][l]>=g)dp[k+1][l] = min(dp[k+1][l],dp[k][l] + a[k+1][l]-g);
						}
						if(l!=m-1){
							long long g = t+(k+l+1);
							//if(j==1&&i==1)cout<<g<<endl;
							if(a[k][l+1]>=g)dp[k][l+1] = min(dp[k][l+1],dp[k][l] + a[k][l+1]-g);
						}
					}
				}
				ans = min(ans,dp.back().back());
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}