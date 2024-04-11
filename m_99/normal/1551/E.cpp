#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		vector nxt(n+1,vector<int>(n+1,Inf));
		{
			vector<int> cur(n+1,Inf);
			
			for(int i=n-1;i>=0;i--){
				nxt[i+1] = cur;
				cur[a[i]] = i+1;
			}
			nxt[0] = cur;
		}
		
		vector dp(n+1,vector<int>(n+1,Inf));
		dp[0][0] = 0;
		rep(i,n){
			rep(j,n+1){
				if(dp[i][j]>=n)continue;
				dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1);
				if(j!=n){
					dp[i+1][j+1] = min(dp[i+1][j+1],nxt[dp[i][j]][i+1]);
				}
			}
		}
		int ans = -Inf;
		rep(i,n+1){
			rep(j,n+1){
				//cout<<dp[i][j]<<',';
				if(j>=k&&dp[i][j]!=Inf){
					ans = max(ans,i);
				}
			}
			//cout<<endl;
		}
		
		if(ans==-Inf)ans = -1;
		else ans = n-ans;
		printf("%d\n",ans);
	
		
	}
	
	return 0;
}